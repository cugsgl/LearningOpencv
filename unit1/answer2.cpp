#include <iostream>
#include <opencv2/opencv.hpp>

//把彩色图像转化为灰度图像
int main(int agrc, const char *agrv[])
{
    cv::Mat img = cv::imread("F:\\learnOpencv\\unit1\\imori.jpg");
    if (img.empty())
        std::cout << "读取失败";
    //读取行列
    int width = img.cols;
    int height = img.rows;

    cv::Mat gary = cv::Mat::zeros(height, width, CV_8UC3);

    cv::cvtColor(img, gary, cv::COLOR_BGR2GRAY);

    cv::namedWindow("color");
    cv::namedWindow("gary");

    cv::imwrite("F:\\learnOpencv\\unit1\\answer_image\\answer2.jpg",gary);
    cv::imshow("color",img);
    cv::imshow("gary",gary);

    cv::waitKey(0);
    // cv::destoryAllWindows();
    cv::destroyAllWindows();

}