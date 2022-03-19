#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

extern void cameraToGray();

void lab() {
    
    string path = "Resources/test.png";
    
    Mat inputImg = imread(path);
    Mat outputImg;
    cvtColor(inputImg, outputImg, COLOR_BGR2GRAY);
    
    imshow("Image", outputImg);
    waitKey(0);
}
