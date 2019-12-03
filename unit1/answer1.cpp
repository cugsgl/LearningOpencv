/*
将图片的BGR三个通道的顺序变为RGB
*/
#include<opencv2/opencv.hpp>//opencv简单程序标配头文件
 using namespace cv;//使用cv命名空间

cv::Mat Mat_swap(cv::Mat img)
{
    //图像行列大小
    int height=img.rows;
    int width=img.cols;

    cv::Mat out=cv::Mat::zeros(height,width,CV_8UC3);

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            //B->R
            out.at<Vec3b>(j,i)[2]=img.at<Vec3b>(j,i)[0];
            //G->G
            out.at<Vec3b>(j,i)[1]=img.at<Vec3b>(j,i)[1];
            //R->B
            out.at<Vec3b>(j,i)[0]=img.at<Vec3b>(j,i)[2];
        }
    }
    return out; 

}

int main(int agrv, const char*agrc[])
{
    cv::Mat img=cv::imread("F:\\learnOpencv\\unit1\\imori.jpg");
    cv::Mat out=Mat_swap(img);
    namedWindow("orinig");
    namedWindow("changeRGB");
    cv::imwrite("F:\\learnOpencv\\unit1\\answer_image\\answer1.jpg",out);
    cv::imshow("orinig",img);
    cv::imshow("changeRGB",out);

    cv::waitKey(0);
   
    cv::destroyAllWindows();

}
