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
    image = imread( samples::findFile( "pool.jpg" ), IMREAD_COLOR ); // Read the file
    // image = threshold_greyscale(image, 75);
    image = level_rgb(image, 1.0, 1.0, 0);
    // std::cout << image.size << std::endl;
     
    namedWindow( "Display window", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Display window", image );                // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window
    return 0;
}