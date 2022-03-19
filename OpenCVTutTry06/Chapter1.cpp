#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int cameraToGray() {
    VideoCapture cap(0);
    Mat inputImg;
    Mat outputImg;
    Mat blurredImg;
    Mat cannyImg;
    Mat dilatedImg;
    Mat dilatingKernel = getStructuringElement(MORPH_RECT, Size(5, 5));
    Mat erodedImg;
    Mat erodingKernel = getStructuringElement(MORPH_RECT, Size(5, 5));
    while (true) {
        auto wasGrabbed = cap.read(inputImg);
        
        GaussianBlur(inputImg, blurredImg, Size(3, 3), 3, 0);
        
        Canny(blurredImg, cannyImg, 50, 150);
        
        dilate(cannyImg, dilatedImg, dilatingKernel);
        
        erode(dilatedImg, erodedImg, erodingKernel);
        
        imshow("Image", erodedImg);
        waitKey(1);
    }
    
    return 0;
}


void cameraFaceDetection() {
    
    CascadeClassifier faceCascade;
    faceCascade.load("Resources/haarcascade_frontalface_default.xml");
    
    if (faceCascade.empty()) {
        cout << "XML file not loaded" << endl;
    } else {
        cout << "XML file loaded" << endl;
    }
    
    VideoCapture cap(0);
    Mat inputImg;
    while (true) {
        auto wasGrabbed = cap.read(inputImg);
        
        vector<Rect> faces;
        faceCascade.detectMultiScale(inputImg, faces, 1.1, 10);
        
        for (int i = 0; i < faces.size(); i++) {
            rectangle(inputImg, faces[i], Scalar(255, 0, 255), 3);
        }

        imshow("Image", inputImg);
        waitKey(1);
    }
}

int main() {
    cameraToGray();
}
