
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <complex>
#include <iostream>
#include <valarray>

using namespace cv;


#ifndef IMG_PROCESS_HPP
#define IMG_PROCESS_HPP


namespace imgPT
{
    
    Mat threshold_greyscale(Mat img, int thresh);
    Mat threshold_rgb(Mat img, int blueThresh, int greenThresh, int redThresh);
    Mat level_rgb(Mat img, float Bmult, float Gmult, float Rmult);
    Mat mirrorV_greyscale(Mat img);
    Mat mirrorV_rgb(Mat img);
    Mat mirrorH_greyscale(Mat img);
    Mat mirrorH_rgb(Mat img);
   
 

}


#endif