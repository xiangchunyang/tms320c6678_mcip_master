
#ifndef MCIP_COMMON_H_
#define MCIP_COMMON_H_

#include <xdc/std.h>
#include <ti/ipc/MessageQ.h>

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

void image_proc(proc_msg_t* pMsg, int coreId, int numCores);

#endif /* MCIP_COMMON_H_ */
