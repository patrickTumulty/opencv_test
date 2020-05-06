#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "img_process.hpp"

using namespace cv;

Mat imgPT::threshold_greyscale(Mat img, int thresh)
{
    int pxl = 0;
    int sensitivity = thresh;
    Mat image = img;
    for (int i = 0; i < image.rows; i++)
        for (int j = 0; j < image.cols; j++)
        {
            pxl = (int)image.at<uchar>(i, j);
            if (pxl >= sensitivity)
            {
                image.at<uchar>(i, j) = (uchar)255;
            }
            else if (pxl < sensitivity)
            {
                image.at<uchar>(i, j) = (uchar)0;
            } 
        }      
    return image;
}

Mat imgPT::threshold_rgb(Mat img, int blueThresh, int greenThresh, int redThresh)
{
    int pxlR = 0;
    int pxlG = 0;
    int pxlB = 0;
    int sensBlue = blueThresh;
    int sensGreen = greenThresh;
    int sensRed = redThresh;
    Mat image = img;
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            pxlB = (int)image.at<Vec3b>(i, j)[0];
            if (pxlB >= sensBlue)
            {
                image.at<Vec3b>(i, j)[0] = (uchar)255;
            }
            else if (pxlB < sensBlue)
            {
                image.at<Vec3b>(i, j)[0] = (uchar)0;
            }

            pxlG = (int)image.at<Vec3b>(i, j)[1];
            if (pxlG >= sensGreen)
            {
                image.at<Vec3b>(i, j)[1] = (uchar)255;
            }
            else if (pxlG < sensGreen)
            {
                image.at<Vec3b>(i, j)[1] = (uchar)0;
            }

            pxlR = (int)image.at<Vec3b>(i, j)[2];
            if (pxlR >= sensRed)
            {
                image.at<Vec3b>(i, j)[2] = (uchar)255;
            }
            else if (pxlR < sensRed)
            {
                image.at<Vec3b>(i, j)[2] = (uchar)0;
            }       
        }
    }
    return image;
}

Mat imgPT::level_rgb(Mat img, float Bmult, float Gmult, float Rmult)
{
    Mat image = img;
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            image.at<Vec3b>(i, j)[0] = (uchar)((float)image.at<Vec3b>(i, j)[0] * Bmult);
            image.at<Vec3b>(i, j)[1] = (uchar)((float)image.at<Vec3b>(i, j)[1] * Gmult);
            image.at<Vec3b>(i, j)[2] = (uchar)((float)image.at<Vec3b>(i, j)[2] * Rmult);
        }
    }
    return image;
}

Mat imgPT::mirrorV_greyscale(Mat img)
{
    Mat image = img;
    for (int i = 0; i < image.rows; i++)
        for (int j = 0; j < image.cols * 0.5; j++)
            image.at<uchar>(i, j) = image.at<uchar>(i, image.cols - j);
    return image;
}

Mat imgPT::mirrorV_rgb(Mat img)
{
    Mat image = img;
    for (int i = 0; i < image.rows; i++)
        for (int j = 0; j < image.cols * 0.5; j++)
            image.at<Vec3b>(i, j) = image.at<Vec3b>(i, image.cols - j);
    return image;
}

Mat imgPT::mirrorH_greyscale(Mat img)
{
    Mat image = img;
    for (int i = 0; i < image.rows * 0.5; i++)
        for (int j = 0; j < image.cols; j++)
            image.at<uchar>(i, j) = image.at<uchar>(image.rows - i, j);
    return image;
}

Mat imgPT::mirrorH_rgb(Mat img)
{
    Mat image = img;
    for (int i = 0; i < image.rows * 0.5; i++)
        for (int j = 0; j < image.cols; j++)
            image.at<Vec3b>(i, j) = image.at<Vec3b>(image.rows - i, j);
    return image;
}
