//RGB转HSV

#include<iostream>
#include<opencv2/opencv.hpp>
#include<math.h>



cv::Mat RGB2HSV(cv::Mat rgb)
{
    int height=rgb.rows;
    int width=rgb.cols;
    float r,g,b;
    float h,s,v;
    float max,min;

    cv::Mat hsv=cv::Mat::zeros(height,width,CV_32FC3);//三通道的浮点数组

    for (int x=0;x<width;x++)
    {
        for(int y=0;y<height;y++)
        {
            r=(float)rgb.at<cv::Vec3b>(y,x)[2]/255;
            g=(float)rgb.at<cv::Vec3b>(y,x)[1]/255;
            b=(float)rgb.at<cv::Vec3b>(y,x)[0]/255;

            min=fmin(r,fmin(g,b));
            max=fmax(r,fmax(g,b));

            if(min==max)
            {
                h=0;
            }else if(min==b)
            {
               h= 60*(g-r)/(max-min)+60;
            }else if(min==r)
            {
                h= 60*(b-g)/(max-min)+180;
            }else
            {
                h= 60*(r-b)/(max-min)+300;
            }
            
            s=max-min;

            v=max;

            hsv.at<cv::Vec3f>(y,x)[0]=h;
            hsv.at<cv::Vec3f>(y,x)[1]=s;
            hsv.at<cv::Vec3f>(y,x)[2]=v;

        }
    }

    return hsv;
}

// HSV -> BGR
cv::Mat HSV2BGR(cv::Mat hsv){
  // get height and width
  int width = hsv.cols;
  int height = hsv.rows;

  float h, s, v;
  double c, _h, _x;
  double r, g, b;

  // prepare output
  cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);

  // each y, x
  for (int y = 0; y < height; y++){
    for (int x = 0; x < width; x++){

      h = hsv.at<cv::Vec3f>(y, x)[0];
      s = hsv.at<cv::Vec3f>(y, x)[1];
      v = hsv.at<cv::Vec3f>(y, x)[2];

      c = s;
      _h = h / 60;
      _x = c * (1 - abs(fmod(_h, 2) - 1));

      r = g = b = v - c;
      
      if (_h < 1) {
        r += c;
        g += _x;
      } else if (_h < 2) {
        r += _x;
        g += c;
      } else if (_h < 3) {
	  g += c;
	  b += _x;
      } else if (_h < 4) {
	  g += _x;
	  b += c;
      } else if (_h < 5) {
	  r += _x;
	  b += c;
      } else if (_h < 6) {
	  r += c;
	  b += _x;
      }

      out.at<cv::Vec3b>(y, x)[0] = (uchar)(b * 255);
      out.at<cv::Vec3b>(y, x)[1] = (uchar)(g * 255);
      out.at<cv::Vec3b>(y, x)[2] = (uchar)(r * 255);
    }
  }

  return out;
}

// inverse Hue
cv::Mat inverse_hue(cv::Mat hsv){
  int height = hsv.rows;
  int width = hsv.cols;

  for(int y = 0; y < height; y++){
    for(int x = 0; x < width; x++){
      hsv.at<cv::Vec3f>(y, x)[0] = fmod(hsv.at<cv::Vec3f>(y, x)[0] + 180, 360);
    }
  }

  return hsv;
}

int main(int agrc,const char*agrv[])
{
    cv::Mat img=cv::imread("F:\\learnOpencv\\unit1\\imori.jpg");
    cv::Mat hsv=RGB2HSV(img);
    
    cv::Mat inverse=inverse_hue(hsv);
    cv::Mat hsvtorgb=HSV2BGR(inverse);

    cv::namedWindow("img");
    cv::namedWindow("inverse");

    cv::imshow("img",img);
    cv::imshow("inverse",hsvtorgb);

    cv::imwrite("F:\\learnOpencv\\unit1\\answer_image\\answer5HSV.jpg",hsvtorgb);
    cv::waitKey(0);
    cv::destroyAllWindows();

}