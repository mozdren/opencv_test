#include <cstdio>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int /*argc*/, char** /*argv*/)
{
    const auto image = imread("lenna.png", 1);

    if (!image.data)
    {
        printf("No image data \n");
        return -1;
    }

    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", image);

    waitKey(0);

    return 0;
}