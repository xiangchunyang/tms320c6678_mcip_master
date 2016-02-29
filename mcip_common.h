#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include <stdint.h>
#include <xdc/std.h>

#include <ti/ipc/Ipc.h>
#include <ti/ipc/MessageQ.h>

char* MCIP_HEAP_NAME = "MCIP_HEAP";
const unsigned short MCIP_HEAP_ID = 0;

const unsigned int   NUM_OF_CORES = 8;

char*  MASTER_MSGQ_NAME = "MSGQ_MASTER";

char*  SLAVE_MSGQ_NAMES[8] =
{
		"MSGQ_SLAVE0",
		"MSGQ_SLAVE1",
		"MSGQ_SLAVE2",
		"MSGQ_SLAVE3",
		"MSGQ_SLAVE4",
		"MSGQ_SLAVE5",
		"MSGQ_SLAVE6",
		"MSGQ_SLAVE7"
};

const int DDR_HEAP_SIZE   =  240*1024*1024; // < 256M

const int MAX_BUFF_SIZE   =   64*1024*1024; // < 1/4 of ddr_heap

const int DATA_BLOCK_SIZE =   32*1024*1024; // < 1/6 of ddr_heap

typedef unsigned char byte;

typedef struct s_img_info_t
{
	int   width;
	int   height;
	int   depth;
}img_info_t;

//           recvBuf                  sendBuf
//  src->+-------------+     dst->+-------------+
//       |     [0]     |          |     [0]     |
//       |  ---------  |          |  ---------  |
//       |     [1]     |          |     [1]     |
//       |  ---------  |          |  ---------  |
//       |     [2]     |          |     [2]     |
//       |  ---------  |          |  ---------  |
//       |     [3]     |          |     [3]     |
//       |  ---------  |          |  ---------  |
//       |     [4]     |          |     [4]     |
//       |  ---------  |          |  ---------  |
//       |     [5]     |          |     [5]     |
//       |  ---------  |          |  ---------  |
//       |     [6]     |          |     [6]     |
//       |  ---------  |          |  ---------  |
//       |     [7]     |          |     [7]     |
//       +-------------+          +-------------+
//       |             |          |             |
//       |     tmp     |          |     tmp     |
//       |             |          |             |
//       +-------------+          +-------------+


typedef struct s_memr_ptr_t
{
	byte*  recvBuf;
	byte*  sendBuf;
}memr_ptr_t;

typedef struct s_proc_msg_t
{
    MessageQ_MsgHeader header;
    img_info_t         info;
    memr_ptr_t         memr;
} proc_msg_t;

const int IMG_INFO_SIZE = sizeof(img_info_t);
const int PROC_MSG_SIZE = sizeof(proc_msg_t);

#endif /* IMAGE_PROCESSING_H */
