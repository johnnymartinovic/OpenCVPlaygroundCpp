//#include <opencv2/imgcodecs.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/imgproc.hpp>
//#include <iostream>
//#include <opencv2/calib3d.hpp>
//#include <opencv2/video/tracking.hpp>
//
//int main() {
//    cv::Mat first = cv::imread("Resources/prvo.jpg");
//    cv::Mat second = cv::imread("Resources/drugo.jpg");
//
//    cv::Mat result = cv::estimateRigidTransform(first, second, false);
//
//    std::cout << "M = " << std::endl << " "  << result << std::endl << std::endl;
//
//    cv::Point2f initialPoint(1000, 400);
//    std::vector<cv::Point2f> vec;
//        vec.push_back(initialPoint);
//    cv::transform(vec, vec, result);
//    cv::Point2f finalPoint = vec[0];
//
//    std::cout << "initialPoint = " << std::endl << " "  << initialPoint << std::endl << std::endl;
//    std::cout << "finalPoint = " << std::endl << " "  << finalPoint << std::endl << std::endl;
//}

// CPP program to Stitch
// input images (panorama) using OpenCV
#include <iostream>
#include <fstream>

// Include header files from OpenCV directory
// required to stitch images.
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/stitching.hpp"

using namespace std;
using namespace cv;

// Define mode for stitching as panoroma
// (One out of many functions of Stitcher)
Stitcher::Mode mode = Stitcher::PANORAMA;

// Array for pictures
vector<Mat> imgs;

int main3()
{
    imgs.push_back(imread("Resources/polica1.jpeg"));
    imgs.push_back(imread("Resources/polica2.jpeg"));
    
    // Define object to store the stitched image
    Mat pano;
    
    // Create a Stitcher class object with mode panoroma
    Ptr<Stitcher> stitcher = Stitcher::create();
    
    // Command to stitch all the images present in the image array
    Stitcher::Status status = stitcher->stitch(imgs, pano);

    if (status != Stitcher::OK)
    {
        // Check if images could not be stiched
        // status is OK if images are stiched successfully
        cout << "Can't stitch images\n";
        return -1;
    }
    
    // Store a new image stiched from the given
    //set of images as "result.jpg"
    imwrite("result.jpg", pano);
    
    // Show the result
    imshow("Result", pano);
    
    waitKey(0);
    return 0;
}
