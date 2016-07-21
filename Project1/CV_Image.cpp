/***************************************************************
 Image CV Process
 ***************************************************************/
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc_c.h"
#include "opencv2/highgui/highgui.hpp"
#include "CV_Image.h"

#define cvQueryHistValue_3D( hist, idx0, idx1, idx2 )     cvGetReal3D( (hist)->bins, (idx0), (idx1), (idx2) ) 
/***************************************************************
 Make two images the same size 

return :
	0 size no change
	1 size changed
	-1 error
****************************************************************/
int CompareSize(const char* imagefile1,
				const char* imagefile2,
				int size_switch,	/* size_switch = 0: turn two targets small; size_switch = 1: turn two targets big */
				IplImage **image1,
				IplImage **image2)
{
	bool Resize = false;
	CvSize czSize;              // target image size

	if (imagefile1 == NULL || imagefile2 == NULL){
		return -1;
	}
	if (image1 == NULL || image2 == NULL){
		return -1;
	}
	/* load the images */
	IplImage *image3 = *image1;
	IplImage *image4 = *image2;
	IplImage *image3_c = new IplImage();
	IplImage *image4_c = new IplImage();

	/* make the two image the same size */
	Resize = false;
	if (image3->width != image4->width || image3->height != image4->height){
		Resize = true;
		if (image3->width > image4->width){
			czSize.width = image3->width;
			czSize.height = image3->height;
			/* create image according to the image3( big size ) */
			image4_c = cvCreateImage(czSize, image3->depth, image3->nChannels);
			/* resize image4(small) to big size  */
			cvResize(image4, image4_c, CV_INTER_AREA);
			/* save resized image */
			cvSaveImage(imagefile2, image4_c);
			return 1;
		}
		else{
			czSize.width = image4->width;
			czSize.height = image4->height;
			/* create image according to the image4( small size ) */
			image3_c = cvCreateImage(czSize, image4->depth, image4->nChannels);
			/* resize image4(big) to small size  */
			cvResize(image3, image3_c, CV_INTER_AREA);
			/* save resized image */
			cvSaveImage(imagefile1, image3_c);
			return 1;
		}
	}
	return 0;
}
/***************************************************************
histograms images comparison
****************************************************************/
void CompareHist(const char* imagefile1,	/* image1 file name */
			  	 const char* imagefile2,	/* image2 file name */
				 histo_compare* compare_result)	/* out: comparison result */
{
	int Resize = false;
	int HistogramBins = 256;
	float HistogramRange1[2] = { 0, 255 };
	float *HistogramRange = HistogramRange1;

	/* load the images */
	IplImage *image1 = cvLoadImage(imagefile1, 0);
	IplImage *image2 = cvLoadImage(imagefile2, 0);

	/* create the histograms using image1 and image2 */
	CvHistogram *Histogram1 = cvCreateHist(1, &HistogramBins, CV_HIST_ARRAY, &HistogramRange);
	CvHistogram *Histogram2 = cvCreateHist(1, &HistogramBins, CV_HIST_ARRAY, &HistogramRange);

	cvCalcHist(&image1, Histogram1);
	cvCalcHist(&image2, Histogram2);

	cvNormalizeHist(Histogram1, 1);
	cvNormalizeHist(Histogram2, 1);

	/* deploy the compare the histograms */
	compare_result->CV_CHISQR_Rate = cvCompareHist(Histogram1, Histogram2, CV_COMP_CHISQR);//卡方
	compare_result->CV_BHATTACHARYYA = cvCompareHist(Histogram1, Histogram2, CV_COMP_BHATTACHARYYA);
	compare_result->CV_CORREL_Rate = cvCompareHist(Histogram1, Histogram2, CV_COMP_CORREL);//相关
	compare_result->CV_INTERSECT_Rate = cvCompareHist(Histogram1, Histogram2, CV_COMP_INTERSECT);//相交
}

/***************************************************************
function : Sobel and save a image
in: the file name to be sobeled
****************************************************************/
int Sobel(const char* imagefile,	/* source image file name */
		const char* Sobelfile)		/* Sobeled image file name */
{
	bool show_sobel = false;			/* show the sobel image or not */
	IplImage* src = cvLoadImage(imagefile);
	IplImage* dst = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
	IplImage* dst_x = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
	IplImage* dst_y = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
	IplImage* temp1 = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
	IplImage* temp2 = cvCreateImage(cvGetSize(src), IPL_DEPTH_16S, 1);

	cvCvtColor(src, temp1, CV_RGB2GRAY);

	cvSobel(temp1, temp2, 0, 1, 3);
	cvConvertScale(temp2, dst_y, 1.0, 0);
	cvSobel(temp1, temp2, 1, 0, 3);
	cvConvertScale(temp2, dst_x, 1.0, 0);
	cvAdd(dst_x, dst_y, dst, NULL);

	/* save the sobeled picture */
	cvSaveImage(Sobelfile, dst);

	/* show the sobeled picture in the window */
	if (show_sobel){
		cvNamedWindow("src", 1);
		cvNamedWindow("dst", 1);
		cvNamedWindow("dst_x", 1);
		cvNamedWindow("dst_y", 1);

		cvShowImage("src", src);
		cvShowImage("dst", dst);
		cvShowImage("dst_x", dst_x);
		cvShowImage("dst_y", dst_y);

		cvWaitKey(0);
		/* release the images */
		cvReleaseImage(&src);
		cvReleaseImage(&dst);
		cvReleaseImage(&temp1);
		cvReleaseImage(&temp2);

		cvDestroyAllWindows();
		return 0;
	}

	/* release the images */
	cvReleaseImage(&src);
	cvReleaseImage(&dst);
	cvReleaseImage(&temp1);
	cvReleaseImage(&temp2);

	return 0;
}
/***************************************************************
function : compare two images
****************************************************************/
int histemd(IplImage** src,
			IplImage** src1,
			float* r_emd)	/* out: compare result */
{
	if (src == NULL || src1 == NULL){
		return -1;
	}
	if (r_emd == NULL){
		return -1;
	}
	IplImage* hsv = cvCreateImage(cvGetSize(*src), 8, 3);
	IplImage* hsv1 = cvCreateImage(cvGetSize(*src1), 8, 3);
	cvCvtColor(*src, hsv, CV_BGR2HSV);
	cvCvtColor(*src1, hsv1, CV_BGR2HSV);

	IplImage* h_plane = cvCreateImage(cvGetSize(*src), 8, 1);
	IplImage* s_plane = cvCreateImage(cvGetSize(*src), 8, 1);
	IplImage* v_plane = cvCreateImage(cvGetSize(*src), 8, 1);
	IplImage* h_plane1 = cvCreateImage(cvGetSize(*src), 8, 1);
	IplImage* s_plane1 = cvCreateImage(cvGetSize(*src), 8, 1);
	IplImage* v_plane1 = cvCreateImage(cvGetSize(*src), 8, 1);
	IplImage* planes[] = { h_plane, s_plane, v_plane };
	IplImage* planes1[] = { h_plane1, s_plane1, v_plane1 };
	cvSplit(hsv, h_plane, s_plane, v_plane, 0);
	cvSplit(hsv1, h_plane1, s_plane1, v_plane1, 0);
	// Build the histogram and compute its contents.  
	//计算规模与h_bins*s_bins*v_bins成指数关系，原先 int h_bins = 32, s_bins = 30, v_bins = 8 时，运行半天都没反应  
	int h_bins = 8, s_bins = 5, v_bins = 5;

	CvHistogram* hist, *hist1;
	{
		int hist_size[] = { h_bins, s_bins, v_bins };
		float h_ranges[] = { 0, 180 }; // hue is [0,180]  
		float s_ranges[] = { 0, 255 };
		float v_ranges[] = { 0, 255 };
		float* ranges[] = { h_ranges, s_ranges, v_ranges };
		hist = cvCreateHist(
			3,
			hist_size,
			CV_HIST_ARRAY,
			ranges,
			1
			);
		hist1 = cvCreateHist(
			3,
			hist_size,
			CV_HIST_ARRAY,
			ranges,
			1
			);
	}
	cvCalcHist(planes, hist, 0, 0); //Compute histogram  
	cvNormalizeHist(hist, 1.0); //Normalize it  
	cvCalcHist(planes1, hist1, 0, 0); //Compute histogram  
	cvNormalizeHist(hist1, 1.0); //Normalize it  

	CvMat* sig1, *sig2;
	int numrows = h_bins*s_bins*v_bins;

	sig1 = cvCreateMat(numrows, 4, CV_32FC1);
	sig2 = cvCreateMat(numrows, 4, CV_32FC1);
	int h, s, v;
	for (h = 0; h < h_bins; h++)
	{
		for (s = 0; s < s_bins; s++)
		{
			for (v = 0; v < v_bins; v++)
			{
				double bin_val = cvQueryHistValue_3D(hist, h, s, v);

				cvSet2D(sig1, h*s_bins*v_bins + s*v_bins + v, 0, cvScalar(bin_val)); //bin value  
				cvSet2D(sig1, h*s_bins*v_bins + s*v_bins + v, 1, cvScalar(h)); //Coord 1  
				cvSet2D(sig1, h*s_bins*v_bins + s*v_bins + v, 2, cvScalar(s)); //Coord 2  
				cvSet2D(sig1, h*s_bins*v_bins + s*v_bins + v, 3, cvScalar(v)); //Coord 3  

				bin_val = cvQueryHistValue_3D(hist1, h, s, v);
				cvSet2D(sig2, h*s_bins*v_bins + s*v_bins + v, 0, cvScalar(bin_val)); //bin value  
				cvSet2D(sig2, h*s_bins*v_bins + s*v_bins + v, 1, cvScalar(h)); //Coord 1  
				cvSet2D(sig2, h*s_bins*v_bins + s*v_bins + v, 2, cvScalar(s)); //Coord 2  
				cvSet2D(sig2, h*s_bins*v_bins + s*v_bins + v, 3, cvScalar(v)); //Coord 3  
			}
		}
	}
	float emd = cvCalcEMD2(sig1, sig2, CV_DIST_L2);
	*r_emd = ((1 - emd) * 100);
	return 0;
}