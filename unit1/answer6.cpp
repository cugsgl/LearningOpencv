//减色处理，即降低图像的辐射分辨率（位数）

#include<iostream>
#include<opencv2/opencv.hpp>

cv::Mat ReduceColor(cv::Mat img)
{
    int width=img.cols;
    int height=img.rows;
    int chennls=img.channels();

    cv::Mat out=cv::Mat::zeros(height,width,CV_8UC3);

    for (int x=0;x<width;x++)
    {
        for(int y=0;y<height;y++)
        {
            for(int c=0;c<chennls;c++)
            {
                out.at<cv::Vec3b>(y,x)[c]=(img.at<cv::Vec3b>(y,x)[c]/64)*64+32;
            }
            
        }
    }
    return out;
}

int main(int agrc,const char*agrv[])
{
    cv::Mat img=cv::imread("F:\\learnOpencv\\unit1\\imori.jpg");
    cv::Mat hsv=ReduceColor(img);
    
    cv::namedWindow("img");
    cv::namedWindow("reduce");

    cv::imshow("img",img);
    cv::imshow("reduce",hsv);

    cv::imwrite("F:\\learnOpencv\\unit1\\answer_image\\answer6H.jpg",hsv);
    cv::waitKey(0);
    cv::destroyAllWindows();

}