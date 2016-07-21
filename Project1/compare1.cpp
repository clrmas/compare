/***************************************************************
	this is a compare images similarity tool.
	create date:2016/06/27

	some tips:
	1. put the image files under the folder the application file in.
	2. limit the image files quantity within 1000.
****************************************************************/
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc_c.h"
#include "opencv2/highgui/highgui.hpp"
#include "File_IO.h"
#include "CV_Image.h"

#define __sobel		/* Use sobel */

//up and low comparison level
float lower_base = 60.0;		/* Low Similarity level */
float up_base = 80.0;			/* Up Similarity level */

bool write_log = true;
char log_buf[50000];
int  log_buf_size = 50000;
char printf_buf[50];

/* compare two images */
void Compare(const char* imagefile1, const char* imagefile2)
{
	int Resize = 0;
	char sobel_file1[50];
	char sobel_file2[50];
	histo_compare	histo_compare1;	/* histograms compare result */
	float g_emd;					/* compare result */

	/* histograms compare */
	CompareHist(imagefile1, imagefile2, &histo_compare1);

	printf("CV_COMP_CHISQR : %.4f\n", histo_compare1.CV_CHISQR_Rate);
	printf("CV_COMP_BHATTACHARYYA : %.4f\n", histo_compare1.CV_BHATTACHARYYA);
	printf("CV_COMP_CORREL : %.4f\n", histo_compare1.CV_CORREL_Rate);
	printf("CV_COMP_INTERSECT : %.4f\n", histo_compare1.CV_INTERSECT_Rate);

	/* make the two image the same size */
	IplImage *image3 = cvLoadImage(imagefile1, 1);
	IplImage *image4 = cvLoadImage(imagefile2, 1);

	Resize = CompareSize(imagefile1, imagefile2, 1, &image3, &image4);
	if (Resize == 1){
		image3 = cvLoadImage(imagefile1, 1);
		image4 = cvLoadImage(imagefile2, 1);
	}

#ifdef __sobel
	/* name the sobel file */
	memset(sobel_file1, 0, 50);
	memset(sobel_file2, 0, 50);
	strcat(sobel_file1, imagefile1);
	strcat(sobel_file2, imagefile2);
	strcat(sobel_file1, "_sobel.bmp");
	strcat(sobel_file2, "_sobel.bmp");
	/* sobel convert */
	Sobel(imagefile1, sobel_file1);
	Sobel(imagefile2, sobel_file2);
	/* refresh the images */
	image3 = cvLoadImage(sobel_file1, 1);
	image4 = cvLoadImage(sobel_file2, 1);
#endif

	/* calulate */
	histemd(&image3, &image4, &g_emd);

	printf("CV_COMP_EMD ：%3.1f%%\n", g_emd);

	/* images similarity level judge */
	int judge_analyse = 0;
	/* case1: CV_CHISQR_Rate or CV_BHATTACHARYYA >1 -->NG */
	if ((histo_compare1.CV_CHISQR_Rate > 1) || (histo_compare1.CV_BHATTACHARYYA > 1)){
		judge_analyse = -1;
	}
	/* case2: CV_CORREL_Rate or CV_INTERSECT_Rate <0.5 -->NG */
	if ((histo_compare1.CV_CORREL_Rate < 0.5) || (histo_compare1.CV_INTERSECT_Rate < 0.5)){
		judge_analyse = -1;
	}
	//	float lower_base = 60;		/* Low Similarity level */
	//	float up_base = 80;			/* Up Similarity level */
	float c1 = g_emd - lower_base;
	float c2 = g_emd - up_base;

	memset(printf_buf, 0, 50);
	if (judge_analyse != -1){
		if (c1 < 0.000001){
			sprintf(printf_buf, "CV_COMP_EMD ：%3.1f%% ==============NG\n", g_emd);
			strcat(log_buf, printf_buf);
		}
		else if (c2 > 0.000000){
			sprintf(printf_buf, "CV_COMP_EMD ：%3.1f%% ----OK\n", g_emd);
			strcat(log_buf, printf_buf);
		}
		else{
			sprintf(printf_buf, "CV_COMP_EMD ：%3.1f%% ------Suspicious\n", g_emd);
			strcat(log_buf, printf_buf);
		}
	}
	else{
		sprintf(printf_buf, "CV_COMP_EMD ：%3.1f%% ==============NG\n", g_emd);
		strcat(log_buf, printf_buf);
	}
#if 1
	memset(printf_buf, 0, 50);
	sprintf(printf_buf, "\n                                   CV_COMP_CHISQR : %.4f\n", histo_compare1.CV_CHISQR_Rate);
	strcat(log_buf, printf_buf);

	sprintf(printf_buf, "                                   CV_COMP_BHATTACHARYYA : %.4f\n", histo_compare1.CV_BHATTACHARYYA);
	strcat(log_buf, printf_buf);

	sprintf(printf_buf, "                                   CV_COMP_CORREL : %.4f\n", histo_compare1.CV_CORREL_Rate);
	strcat(log_buf, printf_buf);

	sprintf(printf_buf, "                                   CV_COMP_INTERSECT : %.4f\n", histo_compare1.CV_INTERSECT_Rate);
	strcat(log_buf, printf_buf);
#endif
}
int main(int argc, char** argv){
	char **picture;		/* pointer to image file list */
	char *pic[1000];	/* image file list arrays */
	char imagefiles[2048];	/* buffer to store content readed from file */
	unsigned int file_quantity;		/*line quantity of the image file list */

	
	/* clear image file list buffer */
	memset(imagefiles, 0, 2048);
	/* clear log buffer */
	memset(log_buf, 0, log_buf_size);

	/* read image files list */
	picture = pic;
	file_quantity = readfile_s("imagelist.txt", imagefiles, 1000, picture);

	/* start compare */
	sprintf(log_buf, "comparison standard base: %s\n", picture[0]);
	for (unsigned int i = 1; i < file_quantity; i++)
	{
		/* write log buffer */
		memset(printf_buf,0,50);
		sprintf(printf_buf, "\n %s:  ", picture[i]);
		strcat(log_buf, printf_buf);

		printf("compare %s and %s\n", picture[0], picture[i]);
		/* compare images */
		Compare(picture[0], picture[i]);
	}
	/* write log buffer to the log file */
	if (write_log){
		writefile_s("image_compare_log.txt", log_buf, sizeof(log_buf));
		writefile_s("image_compare_log.txt", log_buf, sizeof(log_buf));
	}

	cvWaitKey(0);
}
