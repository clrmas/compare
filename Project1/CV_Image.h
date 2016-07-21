/***************************************************************
Image CV Process
***************************************************************/
#ifndef __CV_Image_H__
#define __CV_Image_H__

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc_c.h"
#include "opencv2/highgui/highgui.hpp"

/* 直方图的比较结果 */
 struct histo_compare{
	double CV_CHISQR_Rate;		//卡方的比较，值越小，说明图形越相似
	double CV_BHATTACHARYYA;		//，值越小，说明图形越相似
	double CV_CORREL_Rate;		//相关的比较，值越大，说明图形越相似
	double CV_INTERSECT_Rate;	//相交的比较，值越大，说明图形越相似
};

/* 图大小一致化
	return :
	0 size no change
	1 size changed
	-1 error
*/
int CompareSize(const char* imagefile1,
	const char* imagefile2,
	int size_switch,	/* size_switch = 0: turn two targets small; size_switch = 1: turn two targets big */
	IplImage **image1,
	IplImage **image2);

/* 直方图的比较 */
void CompareHist(const char* imagefile1,
	const char* imagefile2,
	histo_compare* compare_result);
/*
function : Sobel and save image
in: the file name to be sobeled
*/
int Sobel(const char* imagefile1,
		  const char* Sobelfile);
/*
function :Compare two images
*/
int histemd(IplImage** src,
	IplImage** src1,
	float* r_emd);	/* out: Comparison result */

#endif