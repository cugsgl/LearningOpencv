#include<iostream>
#include<opencv2/opencv.hpp>

cv::Mat Thersdhold_process(cv::Mat img,int thershold)
{
    int width=img.cols;
    int height=img.rows;

    cv::Mat gary=cv::Mat::zeros(height,width,CV_8UC1);
    cv::Mat out=cv::Mat::zeros(height,width,CV_8UC1);
    cvtColor(img,gary,cv::COLOR_BGR2GRAY);

    for (int x =0;x<width;x++)
    {
        for(int y=0;y<height;y++)
        {
            if(gary.at<uchar>(y,x) <thershold)
            {
                out.at<uchar>(y,x)=0;
            }else
            {
                out.at<uchar>(y,x)=255;
            }
            
        }
    }
    return out;
}

int main()
{
    cv::Mat img=cv::imread("F:\\learnOpencv\\unit1\\imori.jpg");
    cv::Mat out=Thersdhold_process(img,128);

    cv::namedWindow("img");
    cv::namedWindow("out");

    cv::imshow("img",img);
    cv::imshow("out",out);

    cv::imwrite("F:\\learnOpencv\\unit1\\answer_image\\answer3.jpg",out);
    cv::waitKey();
    cv::destroyAllWindows();
    


}