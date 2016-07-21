// 045 直方??比.cpp : 定?控制台?用程序的入口点。
//

//#include "stdafx.h"

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;


int main( int argc, char** argv )
{
 //?存基准?像和?外???比?像的矩?( RGB 和 HSV )
  Mat src_base, hsv_base;
  Mat src_test1, hsv_test1;
  Mat src_test2, hsv_test2;
  Mat hsv_half_down;

 

  /// 装?三?背景?境不同的?

  src_base = imread( "hand_sample1.jpg" );
  src_test1 = imread( "hand_sample2.jpg" );
  src_test2 = imread( "hand_sample3.jpg");


  /// ??到 HSV
  cvtColor( src_base, hsv_base, CV_BGR2HSV );
  cvtColor( src_test1, hsv_test1, CV_BGR2HSV );
  cvtColor( src_test2, hsv_test2, CV_BGR2HSV );

 

  //?建包含基准?像下半部的半身?像(HSV格式)
  hsv_half_down = hsv_base( Range( hsv_base.rows/2, hsv_base.rows - 1 ), Range( 0, hsv_base.cols - 1 ) );

 

  /// ?hue通道使用50个bin,?saturatoin通道使用60个bin
  int h_bins = 50; int s_bins = 60;
  int histSize[] = { h_bins, s_bins };

 

  // hue的取?范?从0到256, saturation取?范?从0到180
  float h_ranges[] = { 0, 256 };
  float s_ranges[] = { 0, 180 };
  const float* ranges[] = { h_ranges, s_ranges };

 

  // 使用第0和第1通道
  int channels[] = { 0, 1 };

 

  /// 直方?矩?，二?
  MatND hist_base;
  MatND hist_half_down;
  MatND hist_test1;
  MatND hist_test2;

 

  /// ?算基准HSV?像的二?直方?
  calcHist( &hsv_base, 1, channels, Mat(), hist_base, 2, histSize, ranges, true, false );
  normalize( hist_base, hist_base, 0, 1, NORM_MINMAX, -1, Mat() );

 

  //半身基准?像的二?直方?
  calcHist( &hsv_half_down, 1, channels, Mat(), hist_half_down, 2, histSize, ranges, true, false );
  normalize( hist_half_down, hist_half_down, 0, 1, NORM_MINMAX, -1, Mat() );

 

  //???像1的二?直方?
  calcHist( &hsv_test1, 1, channels, Mat(), hist_test1, 2, histSize, ranges, true, false );
  normalize( hist_test1, hist_test1, 0, 1, NORM_MINMAX, -1, Mat() );

 

  //???像2的二?直方?
  calcHist( &hsv_test2, 1, channels, Mat(), hist_test2, 2, histSize, ranges, true, false );
  normalize( hist_test2, hist_test2, 0, 1, NORM_MINMAX, -1, Mat() );


  ///按?序使用4??比?准将基准?像(hist_base)的直方?与其余各直方??行?比
  for( int i = 0; i < 4; i++ )
     {
    int compare_method = i;
       double base_base = compareHist( hist_base, hist_base, compare_method );
       double base_half = compareHist( hist_base, hist_half_down, compare_method );
       double base_test1 = compareHist( hist_base, hist_test1, compare_method );
       double base_test2 = compareHist( hist_base, hist_test2, compare_method );
    
    cout<<"Method "<<i<<": Base_Base        Base-Half        Base-Test(1)       Base-Test(2)"<<endl;
    cout<<"             "<<base_base<<"                "<<base_half<<"         "<<base_test1<<"         "<<base_test2<<endl;

     //  printf( " Method [%d]  Base_Base , Base-Half, Base-Test(1), Base-Test(2) : %f, %f, %f, %f \n", i, base_base, base_half , base_test1, base_test2 );
     }

  printf( "Done \n" );

  return 0;
 }

