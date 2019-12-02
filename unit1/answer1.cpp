#include<opencv2/opencv.hpp>//opencv简单程序标配头文件
using namespace cv;//使用cv命名空间

int main()
{
    Mat src=imread("D:\\1.jpg");//读取图片，要提前将图片放在程序路径下
   // cvtColor(src,src,CV_BGR2GRAY);//转为灰度图
    namedWindow("img");
    imshow("img",src);
    //imwrite("E://1.bmp",src);//保存结果图片
    waitKey(0);//暂停按键等待
}
