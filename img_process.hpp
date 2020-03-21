
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;


#ifndef IMG_PROCESS_HPP
#define IMG_PROCESS_HPP

namespace imgPT
{
    
    Mat threshold_greyscale(Mat img, int thresh);
    Mat threshold_rgb(Mat img, int blueThresh, int greenThresh, int redThresh);
    Mat level_rgb(Mat img, float Bmult, float Gmult, float Rmult);

}


#endif