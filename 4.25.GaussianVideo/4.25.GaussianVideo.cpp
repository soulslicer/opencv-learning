#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

void example2_5( cv::Mat & image ) {
    // Create some windows to show the input
    // and output images in.
    //
    cv::namedWindow( "Example2_5-in", cv::WINDOW_AUTOSIZE ); 
    cv::namedWindow( "Example2_5-out", cv::WINDOW_AUTOSIZE );
    // // Create a window to show our input image //
    cv::imshow( "Example2_5-in", image );
    // // Create an image to hold the smoothed output 
    cv::Mat out;
    // Do the smoothing
    // Could use GaussianBlur(), blur(), medianBlur() or bilateralFilter(). 
    // Give a odd number as it is centered
    cv::GaussianBlur( image, out, cv::Size(5,5), 3, 3);
    cv::GaussianBlur( out, out, cv::Size(5,5), 3, 3);
    // ￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼￼
    // // Show the smoothed image in the output window //
    cv::imshow( "Example2_5-out", out );
    // // Wait for the user to hit a key, windows will self destruct //
    //cv::waitKey( 0 );
}

int main( int argc, char** argv ) {
    cv::namedWindow( "Example3", cv::WINDOW_AUTOSIZE );
    cv::VideoCapture cap;
    cap.open( string(argv[1]) );
    cv::Mat frame;

    while(1){
        cap >> frame;
        if( !frame.data )
            break;
        example2_5(frame);
        if( cv::waitKey(33) >= 0 )
            break;
    }

    return 0;
}

