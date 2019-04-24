#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(){
    //Read image
    Mat image = imread("../assets/putin_noise.jpg");

    if(image.empty()){
        cout<<"can not find image"<<endl;
        return 0;
    }

    //set kernel size
    int kernelSize = 5;

    //create a 5x5 kernel with all elements equal to 1. We are use a kernel size of 5x5. To keep things simple, we will 
    //also choose a kernel where all elements are the same. This kernel is often called a Box Kernel. Notice, the sum 
    //of all the elements of the kernel add up to 1. This ensures that the output image has the same brightness level 
    //as the input image. If we do not do this, the output pixels will be approximately 25 times (5x5 = 25) brighter 
    //than the input pixels on average.
    Mat kernel = Mat::ones(kernelSize, kernelSize, CV_32F);

    //normalize kernel so that sum of all the elements is equal to 1
    kernel = kernel / (float)(kernelSize * kernelSize);

    //print kernel to analyze
    cout<<kernel<<endl;

    Mat result;

    //apply convolution filter. The third parameter (depth) is set to -1, which means the bit-depth of the output image 
    //is the same as the input image. So if the input image is of type CV_8UC3, the output image will also be of the same 
    //type. Later we will see certain kinds of kernels where CV_32F or CV_64F should be used.
    filter2D(image, result, -1, kernel, Point(-1, -1), 0, BORDER_DEFAULT);

    //create windows to display images
    namedWindow("image", WINDOW_NORMAL);
    namedWindow("result", WINDOW_NORMAL);

    //display images
    imshow("image", image);
    imshow("result", result);

    //press esc to exit program
    waitKey(0);

    //close all the opened windows
    destroyAllWindows();

    return 0;
}