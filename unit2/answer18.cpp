//Emboss滤波

#include <iostream>
#include <opencv2/opencv.hpp>

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

cv::Mat sobelfilter(cv::Mat img, int n)
{
    //建立高斯核模板
    //float *guass= new float[n,n];

    int height = img.rows;
    int width = img.cols;
    int channel = img.channels();
    int c = 0, c1 = 0, r = 0, r1 = 0;
    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC1);

    double kernel[n][n] = {{-2, -1, 0}, {-1, 1, 0}, {0, 1, 2}};

    int pad = floor(n / 2);

    double v = 0;

    // filtering
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
                        v += img.at<uchar>(y + dy, x + dx) * kernel[dy + pad][dx + pad];
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
    cv::Mat guass = sobelfilter(BGR2GRAY(img), 3);

    cv::namedWindow("img");
    cv::namedWindow("guass");

    cv::imshow("img", img);
    cv::imshow("guass", guass);

    cv::imwrite("F:\\learnOpencv\\unit2\\answer_image\\answer18.jpg", guass);
    cv::waitKey(0);
    cv::destroyAllWindows();
}