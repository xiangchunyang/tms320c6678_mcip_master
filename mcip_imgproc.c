#include "mcip_common.h"
#include "stdlib.h"
#include "string.h"

const int NGRAY = 256;

void ImageNegative(proc_msg_t* pMsg, int coreId, int numCores)
{
	//
	byte* src = pMsg->memr.recvBuf;
	byte* dst = pMsg->memr.sendBuf;

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
		dst[i] = (byte)(255 - src[i]);
	}
}

void CalcHist(int* hist, byte* imgData, int imgSize)
{
	memset(hist, 0, sizeof(int)*NGRAY);

	int i;

	for (i = 0; i < imgSize; ++i)
	{
		++hist[imgData[i]];
	}
}

void HistSmoothing(int* dst_hist, int* src_hist, int window)
{
	if (window < 1 || window>5)
	{
		window = 3;
	}

	int* tmp = (int*)malloc(sizeof(int)*(window + NGRAY + window));

	int i;

	for (i = 0; i < window; ++i)
	{
		tmp[i] = src_hist[0];
	}
	for (i = window; i < window + NGRAY; ++i)
	{
		tmp[i] = src_hist[i - window];
	}
	for (i = window + NGRAY; i < window + NGRAY + window; ++i)
	{
		tmp[i] = src_hist[NGRAY - 1];
	}

	int j,sum;
	int w_ext = window + 1 + window;

	for (i = 0; i < NGRAY; ++i)
	{
		sum = window;
		for (j = -window; j <= window; ++j)
		{
			sum += tmp[window + i + j];
		}
		dst_hist[i] = sum / w_ext;
	}

	free(tmp);
}

void ImageThresholding(byte* dst, byte* src, int imgSize, byte thresh)
{
	byte bv, b0=(byte)0, bx=(byte)255;

	int i;
	for (i = 0; i < imgSize; ++i)
	{
		bv = src[i];
		dst[i] = bv > thresh ? bx : b0;
	}
}

int FindFirstPeak(int* smooth_hist, int search_window)
{
	if (search_window < 2 || search_window>10)
	{
		search_window = 2;
	}

	int max = smooth_hist[0];
	int index = search_window;
	int i, next;
	for (i = search_window + 1; i < NGRAY; ++i)
	{
		if (smooth_hist[i] > max)
		{
			max = smooth_hist[i];
			index = i;
		}
		else
		{
			next = IndexOfNextMax(smooth_hist, max, i + 1, search_window);
			if (next > 0)
			{
				i = next;
				max = smooth_hist[i];
				index = i;
			}
			else
			{
				break;
			}
		}
	}

	return index;
}

int FindFirstNadir(int* smooth_hist, int i_first_peak, int search_window)
{
	if (search_window < 2 || search_window>10)
	{
		search_window = 2;
	}

	int min = smooth_hist[i_first_peak];
	int index = i_first_peak;
	int i, next;
	for (i = i_first_peak + 1; i < NGRAY; ++i)
	{
		if (smooth_hist[i] < min)
		{
			min = smooth_hist[i];
			index = i;
		}
		else
		{
			next = IndexOfNextMin(smooth_hist, min, i + 1, search_window);
			if (next > 0)
			{
				i = next;
				min = smooth_hist[i];
				index = i;
			}
			else
			{
				break;
			}
		}
	}

	return index;
}

int FindLastPeak(int* smooth_hist, int search_window)
{
	if (search_window < 2 || search_window>10)
	{
		search_window = 2;
	}

	int max = smooth_hist[NGRAY - 1];
	int index = NGRAY - 1;
	int i, prev;
	for (i = NGRAY - 2; i > search_window; --i)
	{
		if (smooth_hist[i] >= max)
		{
			max = smooth_hist[i];
			index = i;
		}
		else
		{
			prev = IndexOfPrevMax(smooth_hist, max, i - 1, search_window);
			if (prev > 0)
			{
				i = prev;
				max = smooth_hist[i];
				index = i;
			}
			else
			{
				break;
			}
		}
	}

	return index;
}

int FindLastNadir(int* smooth_hist, int i_last_peak, int search_window)
{
	if (search_window < 2 || search_window>10)
	{
		search_window = 2;
	}

	int min = smooth_hist[i_last_peak];
	int index = i_last_peak;
	int i, prev;
	for (i = i_last_peak - 1; i > 0; --i)
	{
		if (smooth_hist[i] <= min)
		{
			min = smooth_hist[i];
			index = i;
		}
		else
		{
			prev = IndexOfPrevMin(smooth_hist, min, i - 1, search_window);
			if (prev > 0)
			{
				i = prev;
				min = smooth_hist[i];
				index = i;
			}
			else
			{
				break;
			}
		}
	}

	return index;
}

int IndexOfNextMax(int* smooth_hist, int curr_max, int index, int search_window)
{
	int i;

	for (i = index; i < index + search_window && i < NGRAY; ++i)
	{
		if (smooth_hist[i] >= curr_max) return i;
	}

	return -1;
}

int IndexOfNextMin(int* smooth_hist, int curr_min, int index, int search_window)
{
	int i;

	for (i = index; i < index + search_window && i < NGRAY; ++i)
	{
		if (smooth_hist[i] <= curr_min) return i;
	}

	return -1;
}

int IndexOfPrevMax(int* smooth_hist, int curr_max, int index, int search_window)
{
	int i;

	for (i = index; i > index - search_window && i > 0; --i)
	{
		if (smooth_hist[i] >= curr_max) return i;
	}

	return -1;
}

int IndexOfPrevMin(int* smooth_hist, int curr_min, int index, int search_window)
{
	int i;

	for (i = index; i > index - search_window && i > 0; --i)
	{
		if (smooth_hist[i] <= curr_min) return i;
	}

	return -1;
}
