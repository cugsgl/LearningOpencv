//平均池化，即取平均金字塔，得到的降低分辨率的图像
#include<iostream>
#include<opencv2/opencv.hpp>

cv::Mat AvePooling(cv::Mat img, int n)
{
    int width=img.cols;
    int height=img.rows;
    int channel=img.channels();

   cv::Mat out=cv::Mat::zeros(height,width,CV_8UC3);

   for (int y=0;y<height;y+=n)
   {
       for(int x=0;x<width;x+=n)
       {
           for(int c=0;c<channel;c++)
           {
               float sum=0;
               for(int i=0;i<n;i++)
               {
                   for(int j=0;j<n;j++)
                {
                    sum+=(float)img.at<cv::Vec3b>(y+i,j+x)[c];
                }
               }
               sum/=(n*n);
                 for(int i=0;i<n;i++)
               {
                   for(int j=0;j<n;j++)
                   {
                        out.at<cv::Vec3b>(y+i,x+j)[c]=(uchar)sum;
                   }

               }
               
           }
       }
   }
   return out;

}

int main(int agrc,const char*agrv[])
{
    cv::Mat img=cv::imread("F:\\learnOpencv\\unit1\\imori.jpg");
    cv::Mat hsv=AvePooling(img,8);
   // cv::Mat resize;
    //cv::resize(hsv,resize,img.size());
    
    cv::namedWindow("img");
    cv::namedWindow("pool");
    //cv::namedWindow("resize");

    cv::imshow("img",img);
    cv::imshow("pool",hsv);
    //cv::imshow("resize",resize);

    cv::imwrite("F:\\learnOpencv\\unit1\\answer_image\\answer7.jpg",hsv);
    cv::waitKey(0);
    cv::destroyAllWindows();

}
