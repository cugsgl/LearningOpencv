#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <math.h>

cv::Mat Histogram_normalization(cv::Mat img, int a, int b)
{
    int width = img.cols;
    int height = img.rows;
    int channel = img.channels();

    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);

    int d, c; //求解图像中的3个波段中的最大值和最小值

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            for (int _c = 0; _c < channel; _c++)
            {
                d = fmax(d, img.at<cv::Vec3b>(y, x)[_c]);
                c = fmin(c, img.at<cv::Vec3b>(y, x)[_c]);
            }
        }
    }

    //遍历图像，计算输出值
    int val;

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            for (int _c = 0; _c < channel; _c++)
            {
                val = img.at<cv::Vec3b>(y, x)[_c];
                if (val < c)
                {
                    out.at<cv::Vec3b>(y, x)[_c] = (uchar)a;
                }
                else if (val > d)
                {
                    out.at<cv::Vec3b>(y, x)[_c] = (uchar)b;
                }
                else
                {
                    out.at<cv::Vec3b>(y, x)[_c] = (uchar)(((b - a) / (d - c)) * (val - c) + a);
                }
            }
        }
    }

    return out;
}

int main(int argc, const char *argv[])
{
    // read image
    cv::Mat img = cv::imread("F:\\learnOpencv\\unit3\\imori_dark.jpg", cv::IMREAD_COLOR);

    // histogram normalization
    cv::Mat out = Histogram_normalization(img, 0, 255);
    cv::namedWindow("answer");
    cv::imwrite("F:\\learnOpencv\\unit3\\answer_image\\answer21.jpg", out);
    cv::imshow("answer", out);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}