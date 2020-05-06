#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "img_process.hpp"

using namespace cv;
using namespace imgPT;


int main( int argc, char** argv )
{
    Mat image;
    image = imread( samples::findFile( "jul.jpg" ), IMREAD_GRAYSCALE ); // Read the file
    // image = threshold_greyscale(image, 75);
    image = mirrorH_greyscale(image);
    image = threshold_greyscale(image, 200);
    // std::cout << image.size << std::endl;
     
    namedWindow( "Display window", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Display window", image );                // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window
    return 0;
}