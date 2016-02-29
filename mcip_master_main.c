
#include <c6x.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <ti/ndk/inc/netmain.h>
#include <ti/ndk/inc/_stack.h>
#include <ti/ndk/inc/tools/console.h>
#include <ti/ndk/inc/tools/servers.h>

#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/runtime/Memory.h>
#include <ti/ipc/Ipc.h>
#include <ti/ipc/MessageQ.h>
#include <ti/ipc/HeapBufMP.h>
#include <ti/ipc/MultiProc.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <xdc/cfg/global.h>

#include <ti/platform/platform.h>
#include <ti/platform/resource_mgr.h>

#include "mcip_common.h"

// Network

char *PCStaticIP = "192.168.2.123";
char *EVMStaticIP = "192.168.2.100";
char *LocalIPMask = "255.255.255.0";
char *GatewayIP = "192.168.2.123"; // Not used when using DHCP
char *DomainName = "TI-C6678-DSP"; // Not used when using DHCP

const int TCP_LISTEN_PORT = 56789;
const int MAX_CONNECTION  = 1;

int tcp_listen = 1;

#define S_RECV_OK    1
#define S_RECV_ERROR 0

#define S_SEND_OK    1
#define S_SEND_ERROR 0

#define DDR_SHARED_HEAP (HeapMem_Handle_to_xdc_runtime_IHeap(systemHeapMaster))

byte* recvBuff  = NULL;
byte* sendBuff  = NULL;
int   buffSize  = 0;

proc_msg_t**     pMessageList = NULL;
MessageQ_Handle  hMasterQueue = NULL;

void MasterDaemon(void);

void MemoryAlloc(void);
void MemoryFree(void);

void NetStart(void);

int recvData(SOCKET sock,byte* pBuf,img_info_t* pInfo);
int sendData(SOCKET sock,byte* pBuf,img_info_t* pInfo);

void Slave0_Task(proc_msg_t* p_msg);

/////////////////////////////////////

void main(void)
{
	Task_Params task_params;
	Task_Params_init(&task_params);
	task_params.priority = 5;

	Task_create((ti_sysbios_knl_Task_FuncPtr)MasterDaemon, &task_params, NULL);

	Ipc_start();
	BIOS_start();
}

void MasterDaemon(void)
{
	platform_uart_init();
	platform_uart_set_baudrate(115200);
	platform_write_configure(PLATFORM_WRITE_ALL);

	// EVM_init
	platform_init_flags sFlags;
	platform_init_config sConfig;
	memset((void*)&sFlags, 0, sizeof(platform_init_flags));
	memset((void*)&sConfig, 0, sizeof(platform_init_config));
	sFlags.pll = 0;
	sFlags.ddr = 0;
	sFlags.tcsl = 1;
	sFlags.phy = 1;
	sFlags.ecc = 0;
	sConfig.pllm = 0;
	platform_init(&sFlags, &sConfig);

    // QMSS -- CPPI -- PA -- CFG

	QMSS_CFG_T qmss_cfg;
	CPPI_CFG_T cppi_cfg;

	qmss_cfg.master_core = 1; // core0 is master
	cppi_cfg.master_core = 1;
	
	/*
	if (platform_get_coreid() == 0)
	{
		qmss_cfg.master_core = 1;
		cppi_cfg.master_core = 1;
	}
	else
	{
		qmss_cfg.master_core = 0;
		cppi_cfg.master_core = 0;
	}
	*/

	qmss_cfg.max_num_desc = MAX_NUM_DESC;
	qmss_cfg.desc_size = MAX_DESC_SIZE;
	qmss_cfg.mem_region = Qmss_MemRegion_MEMORY_REGION0;

	cppi_cfg.dma_num = Cppi_CpDma_PASS_CPDMA;
	cppi_cfg.num_tx_queues = NUM_PA_TX_QUEUES;
	cppi_cfg.num_rx_channels = NUM_PA_RX_CHANNELS;

	res_mgr_init_qmss(&qmss_cfg);
	res_mgr_init_cppi(&cppi_cfg);
	res_mgr_init_pass();

	NC_SystemOpen( NC_PRIORITY_LOW, NC_OPMODE_INTERRUPT);
	MemoryAlloc();

	HANDLE hCfg = CfgNew();

	CI_IPNET NA;
	bzero(&NA, sizeof(NA));
	NA.IPAddr = inet_addr(EVMStaticIP);
	NA.IPMask = inet_addr(LocalIPMask);
	strcpy(NA.Domain, DomainName);
	CfgAddEntry(hCfg, CFGTAG_IPNET, 1, 0, sizeof(CI_IPNET), (UINT8*)&NA, 0);

	CI_ROUTE RT;
	bzero(&RT, sizeof(RT));
	RT.IPDestAddr = inet_addr(PCStaticIP);
	RT.IPDestMask = inet_addr(LocalIPMask);
	RT.IPGateAddr = inet_addr(GatewayIP);
	CfgAddEntry(hCfg, CFGTAG_ROUTE, 0, 0, sizeof(CI_ROUTE), (UINT8*)&RT, 0);

	// START
	NC_NetStart(hCfg, NetStart, NULL, NULL);

	//EXIT
	CfgFree(hCfg);
	MemoryFree();
	NC_SystemClose();
}

void NetStart(void)
{
	printf("\n[Server] %s : %d\n\n",EVMStaticIP,TCP_LISTEN_PORT);

	fdOpenSession(TaskSelf());

	SOCKET serverSock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

	struct sockaddr_in ssa;
	int sLen = sizeof(ssa);

	memset(&ssa,0,sLen);
	ssa.sin_family = AF_INET;
	//ssa.sin_len = sLen;
	ssa.sin_addr.s_addr = inet_addr(EVMStaticIP);
	ssa.sin_port = htons(TCP_LISTEN_PORT);
	
	bind(serverSock,(PSA)&ssa,sLen);

	listen(serverSock,MAX_CONNECTION);

	int iLen = sizeof(int);
	
	int iLoop,nLoop,i;
	img_info_t imgInfo;

	MessageQ_QueueId queueId;
	proc_msg_t* pMsg = NULL;

	int status;

	while(tcp_listen)
	{
		SOCKET clientSock = accept(serverSock,(PSA)&ssa,&sLen);
		
		recv(clientSock,&nLoop,iLen,0);

		for(iLoop=1;iLoop<=nLoop;++iLoop)
		{
			printf("PROGRESS: %d/%d\n",iLoop,nLoop);

			status = recvData(clientSock,recvBuff,&imgInfo);

			if(status != S_RECV_OK)
			{
				break;
			}

			memcpy(&(pMessageList[0]->info),&imgInfo,IMG_INFO_SIZE);

			for(i=1;i<NUM_OF_CORES;++i)
			{
				memcpy(&(pMessageList[i]->info),&imgInfo,IMG_INFO_SIZE);

				MessageQ_open(SLAVE_MSGQ_NAMES[i],&queueId);
	            MessageQ_put(queueId,(MessageQ_MsgHeader*)(pMessageList[i]));
			}

			Slave0_Task(pMessageList[0]);

			for(i=1;i<NUM_OF_CORES;++i)
			{
				MessageQ_get(hMasterQueue,(MessageQ_MsgHeader**)&pMsg,MessageQ_FOREVER);
			}

			status = sendData(clientSock,sendBuff,&imgInfo);

			if(status != S_RECV_OK)
			{
				break;
			}

			printf("\n");
		}

		printf("FINISHED.\n\n");

		shutdown(clientSock,SHUT_RDWR);
	}

	shutdown(serverSock,SHUT_RDWR);

	fdCloseSession(TaskSelf());
}

int recvData(SOCKET sock,byte* pBuf,img_info_t* pInfo)
{
	recv(sock,pInfo,IMG_INFO_SIZE,0);

	int size = (pInfo->width)*(pInfo->height);

	byte* ptr = pBuf;
	int   res = size;
	int   len = 0;

	while(res>0)
	{
		len = recv(sock,ptr,res,0);

		if(len<0) break;

		ptr += len;
		res -= len;
	}

	if(res)
	{
		printf("RECV_ERROR(%d/%d)\n",res,size);
		return S_RECV_ERROR;
	}

	printf("RECV_SUCCESS\n");

	return S_RECV_OK;
}

int sendData(SOCKET sock,byte* pBuf,img_info_t* pInfo)
{
	send(sock,pInfo,IMG_INFO_SIZE,0);

	int size = (pInfo->width)*(pInfo->height);

	byte* ptr = pBuf;
	int   res = size;
	int   len = 0;

	while(res>0)
	{
		len = send(sock,ptr,res,0);

		if(len<0) break;

		ptr += len;
		res -= len;
	}

	if(res)
	{
		printf("SEND_ERROR(%d/%d)\n",res,size);
		return S_SEND_ERROR;
	}

	printf("SEND_SUCCESS\n");

	return S_SEND_OK;
}

void MemoryAlloc(void)
{
	//////////////////////////////////////////////////////////////////////////
	// SHARED_DDR_HEAP

	buffSize = MAX_BUFF_SIZE;

    recvBuff = (byte*)Memory_alloc(DDR_SHARED_HEAP,buffSize,8,NULL);
    sendBuff = (byte*)Memory_alloc(DDR_SHARED_HEAP,buffSize,8,NULL);

	//////////////////////////////////////////////////////////////////////////
	// MessageQ

	HeapBufMP_Params heapBufParams;
	HeapBufMP_Params_init(&heapBufParams);
	heapBufParams.regionId = 0;
	heapBufParams.name = MCIP_HEAP_NAME;
	heapBufParams.numBlocks = 2*NUM_OF_CORES;
	heapBufParams.blockSize = PROC_MSG_SIZE;

	HeapBufMP_Handle heapHandle = NULL;
	heapHandle = HeapBufMP_create(&heapBufParams);
	MessageQ_registerHeap((IHeap_Handle)heapHandle,MCIP_HEAP_ID);

	pMessageList = (proc_msg_t**)calloc(NUM_OF_CORES, sizeof(proc_msg_t*));

	int i;
	for(i=0;i<NUM_OF_CORES;++i)
	{
		pMessageList[i] = (proc_msg_t*)MessageQ_alloc(MCIP_HEAP_ID,PROC_MSG_SIZE);

		pMessageList[i]->memr.recvBuf = recvBuff;
		pMessageList[i]->memr.sendBuf = sendBuff;
	}

	heapHandle = NULL;
	int status = -1;

	while(status<0)
	{
		Task_sleep(1);
	    status = HeapBufMP_open(MCIP_HEAP_NAME, &heapHandle);
	}

	MessageQ_registerHeap((IHeap_Handle)heapHandle, MCIP_HEAP_ID);

	hMasterQueue = MessageQ_create(MASTER_MSGQ_NAME, NULL);
}

void MemoryFree(void)
{
	MessageQ_delete(&hMasterQueue);

	int i;
	for(i=0;i<NUM_OF_CORES;++i)
	{
		MessageQ_free((MessageQ_MsgHeader*)pMessageList[i]);
	}
	free(pMessageList);

	if(recvBuff != NULL)
	{
		Memory_free(DDR_SHARED_HEAP,recvBuff,buffSize);
	}

	if(sendBuff != NULL)
	{
		Memory_free(DDR_SHARED_HEAP,sendBuff,buffSize);
	}
}

void Slave0_Task(proc_msg_t* p_msg)
{
	int width = p_msg->info.width;
	int height = p_msg->info.height;

	int hx = height/NUM_OF_CORES;

	int h0 = 0;
	int h1 = height - hx*(NUM_OF_CORES-1);

	byte* src = p_msg->memr.recvBuf;
	byte* dst = p_msg->memr.sendBuf;

	int i,v;
	int k0 = h0*width;
	int k1 = h1*width;

	for(i=k0;i<k1;++i)
	{
		v=src[i]+64;
		dst[i]=v>255?(byte)255:(byte)v;
	}
}

// EOF
