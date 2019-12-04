//大津法二值化图像

#include <iostream>
#include <opencv2/opencv.hpp>

cv::Mat Thersdhold_process(cv::Mat img, int thershold)
{
    int width = img.cols;
    int height = img.rows;

    cv::Mat gary = cv::Mat::zeros(height, width, CV_8UC1);
    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC1);
    cvtColor(img, gary, cv::COLOR_BGR2GRAY);

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            if (gary.at<uchar>(y, x) < thershold)
            {
                out.at<uchar>(y, x) = 0;
            }
            else
            {
                out.at<uchar>(y, x) = 255;
            }
        }
    }
    return out;
}

double otsu(cv::Mat &img)
{
    int thershold = 0;
    double m0 = 0, m1 = 0;    //两类的均值
    double w0 = 0, w1 = 0;    //两类的比例
    double maxvar = 0;        //最大类间方差
    int histogram[256] = {0}; //存储直方图

    int height = img.rows;
    int width = img.cols;
    double num = height * width;
    double sb = 0;
    int sum=0;
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            histogram[img.at<uchar>(y, x)]=histogram[img.at<uchar>(y, x)]+1; 
            sum+=1;//计算直方图
        }
    }

    //i代表阈值，遍历得到最大类间方差，得到最佳阈值
    for (int i = 0; i < 256; i++)
    {   w0=0;
        w1=0;
        m1=0;
        m0=0;

        //计算第一类的均值和比例
        for (int j = 0; j <= i; j++)
        {
            w0 += histogram[j];     //总个数
            m0 += j * histogram[j]; //总和
        }

        //计算第二类的均值和比例
        for (int j = i + 1; j <= 255; j++)
        {
            w1 += histogram[j];     //总个数
            m1 += j * histogram[j]; //总和
        }

        if (w0 == 0 || w1 == 0)
        {
            sb = 0;
        }
        else
        {
            // std::cout << "m0:" << m0 << "m1：" << m1 << "w0：" << w0 << "w1：" << w1 << std::endl;
            m0 = m0 / int(w0);
            w0 = w0 / num;
            m1 = m1 / int(w1);
            w1 = w1 / num;
            sb = w0 * w1 * (m1 - m0) * (m1 - m0);
        }

        if (sb > maxvar)
        {
            maxvar = sb;
            thershold = i;
            // std::cout << "阈值：" << i << std::endl;
            // std::cout << "sb：" << sb << std::endl;
            // std::cout << "m0:" << m0 << "m1：" << m1 << "w0：" << w0 << "w1：" << w1 << std::endl;
        }
    }
    std::cout << "阈值为" << thershold << std::endl;

    return thershold;
}

int main(int agrc, const char *[])
{
    cv::Mat img = cv::imread("F:\\learnOpencv\\unit1\\imori.jpg");
    cv::Mat img1,img2;
    img.copyTo(img1);
    //img.copyTo(img2);

    cv::cvtColor(img1, img1, cv::COLOR_BGR2GRAY);
    cv::cvtColor(img, img2, cv::COLOR_BGR2GRAY);
    int thres = cv::threshold(img1, img1, 0, 255, cv::THRESH_OTSU);
    std::cout << "opencv阈值：" << thres << std::endl;
    int th=otsu(img2);
    std::cout<<"otsu阈值"<<th<<std::endl;
    //std::cout<<otsu(img1)<<std::endl;
    Thersdhold_process(img,th).copyTo(img2);

    cv::namedWindow("img");
    cv::namedWindow("img2");
    cv::imshow("img", img1);
    cv::imshow("img2", img2);

    cv::imwrite("F:\\learnOpencv\\unit1\\answer_image\\answer4.jpg",img2);

    cv::waitKey(0);

    cv::destroyAllWindows();
}