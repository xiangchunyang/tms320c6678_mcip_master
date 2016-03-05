
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

void ImageNegative(proc_msg_t* pMsg, int coreId, int numCores);

void CalcHist(int* hist, byte* imgData, int imgSize);

void HistSmoothing(int* dst_hist, int* src_hist, int window);

void ImageThresholding(byte* dst, byte* src, int imgSize, byte thresh);

int FindFirstPeak(int* smooth_hist, int search_window);

int FindFirstNadir(int* smooth_hist, int i_first_peak, int search_window);

int FindLastPeak(int* smooth_hist, int search_window);

int FindLastNadir(int* smooth_hist, int i_last_peak, int search_window);

int IndexOfNextMax(int* smooth_hist, int curr_max, int index, int search_window);

int IndexOfNextMin(int* smooth_hist, int curr_min, int index, int search_window);

int IndexOfPrevMax(int* smooth_hist, int curr_max, int index, int search_window);

int IndexOfPrevMin(int* smooth_hist, int curr_min, int index, int search_window);

#endif /* MCIP_COMMON_H_ */
