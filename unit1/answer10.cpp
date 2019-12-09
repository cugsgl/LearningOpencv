//中值滤波

#include <iostream>
#include <opencv2/opencv.hpp>

cv::Mat guassfilter(cv::Mat img, int n)
{
    //建立高斯核模板
    //float *guass= new float[n,n];
    
    int height = img.rows;
    int width = img.cols;
    int channel = img.channels();
    int c = 0, c1 = 0, r = 0, r1 = 0;
    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            for (int ch = 0; ch < channel; ch++)
            {   float v=0;
                c = x - n / 2, c1 = x + n / 2;
                r = y - n / 2, r1 = y + n / 2;
                if (x < n / 2)
                    c = 0, c1 = x + n / 2;
                if (y < n / 2)
                    r = 0, r1 = y + n / 2;
                if (x > (width - n / 2 - 1))
                    c = x - n / 2, c1 = width - 1;
                if (y > (height - n / 2 - 1))
                    r = y - n / 2, r1 = height - 1;

                int temp[n*n]={0};
                int count=0;
                for (int cc=c; cc <= c1; cc++)
                {
                    for (int rr=r; rr <= r1; rr++)
                    {
                       temp[count++]=(int)img.at<cv::Vec3b>(rr, cc)[ch];
                       
                       
                    }
                }
                std::sort(temp, temp + (n * n));
                //for(int i=0;i<count;i++) std::cout<<"temp"<<temp[i]<<std::endl;
                out.at<cv::Vec3b>(y, x)[ch]=(uchar)temp[count/2];
            }
        }
    }


    return out;
}

int main(int agrc, const char *agrv[])
{
    cv::Mat img = cv::imread("F:\\learnOpencv\\unit1\\imori_noise.jpg");
    cv::Mat guass = guassfilter(img, 3);

    cv::namedWindow("img");
    cv::namedWindow("guass");

    cv::imshow("img", img);
    cv::imshow("guass", guass);

    cv::imwrite("F:\\learnOpencv\\unit1\\answer_image\\answer10.jpg", guass);
    cv::waitKey(0);
    cv::destroyAllWindows();
}