//log滤波
#include <opencv2/core.hpp>

#include <opencv2/highgui.hpp>
#include <iostream>
#include <math.h>

// BGR -> Gray
cv::Mat BGR2GRAY(cv::Mat img)
{
    // get height and width
    int width = img.cols;
    int height = img.rows;

    // prepare output
    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC1);

    // each y, x
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            // BGR -> Gray
            out.at<uchar>(y, x) = 0.2126 * (float)img.at<cv::Vec3b>(y, x)[2] + 0.7152 * (float)img.at<cv::Vec3b>(y, x)[1] + 0.0722 * (float)img.at<cv::Vec3b>(y, x)[0];
        }
    }
    return out;
}

cv::Mat logfilter(cv::Mat img, int size, double sig)
{
    int height = img.rows;
    int width = img.cols;
    int channel = img.channels();

    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC1);

    double kanel[size][size] = {0};
    int pad = floor(size / 2);
    int _x = 0, _y = 0;
    double sum;

    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            _x = x - pad;
            _y = y - pad;
            kanel[x][y] = (_x * _x + _y * _y - sig * sig) * exp(-(_x * _x + _y * _y) / (2 * sig * sig)) / (2 * 3.14159 * pow(sig, 6));
            sum += kanel[x][y];
        }
    }
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size; y++)
        {
            kanel[x][y] /=sum;
        }
    }
    double v;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            v = 0;
            for (int dy = -pad; dy < pad + 1; dy++)
            {
                for (int dx = -pad; dx < pad + 1; dx++)
                {
                    if (((y + dy) >= 0) && ((x + dx) >= 0) && ((y + dy) < height) && ((x + dx) < width))
                    {
                        v += img.at<uchar>(y + dy, x + dx) * kanel[dy + pad][dx + pad];
                    }
                }
            }
            v = fmax(v, 0);
            v = fmin(v, 255);
            out.at<uchar>(y, x) = (uchar)v;
        }
    }
    return out;
}

int main(int agrc, const char *agrv[])
{
    cv::Mat img = cv::imread("F:\\learnOpencv\\unit2\\imori.jpg");
    cv::Mat guass = logfilter(BGR2GRAY(img), 5,3);

    cv::namedWindow("img");
    cv::namedWindow("guass");

    cv::imshow("img", img);
    cv::imshow("guass", guass);

    cv::imwrite("F:\\learnOpencv\\unit2\\answer_image\\answer19.jpg", guass);
    cv::waitKey(0);
    cv::destroyAllWindows();
}