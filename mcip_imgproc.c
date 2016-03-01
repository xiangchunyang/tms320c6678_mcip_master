#include "mcip_common.h"

void image_proc(proc_msg_t* pMsg, int coreId, int numCores)
{
	//
	byte* recvBuff = pMsg->memr.recvBuf;
	byte* sendBuff = pMsg->memr.sendBuf;

	int width  = pMsg->info.width;
	int height = pMsg->info.height;

	int hx = height/numCores;

	int h0 = hx*coreId;
	int h1 = h0 + hx;

	if(coreId == numCores-1)
	{
		h1 = height;
	}

	int i;
	int k0 = h0*width;
	int k1 = h1*width;

	for(i=k0;i<k1;++i)
	{
		sendBuff[i] = (byte)255 - recvBuff[i];
	}
}
