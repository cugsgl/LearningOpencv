# answer1

**1. 创建一个空矩阵**

`cv::Mat::zeros(rows,cols,datatype);`

**2. 读取图像、显示图像、写入图像分别为**

```c++
cv::imread("name",cv::Mat);

cv::imshow("name",cv::Mat);

cv::imwrite("name",cv::Mat);
```

**3. 访问图像像素**

`PixellValue=cv::Mat.at<vetortype>(y,x)[ChanelNum]`

**4. 命名窗体,销毁窗体**

```c++
cv::namedWindows("name");
cv::destoryWindow("name");
cv::destoryAllWindows();

```

# answer2

**1. 图像颜色空间转化**
```c++
void cvtColor(img,trans_image,type,num_channel);
```

例如转化为灰度图片`cv::COLOR_BGR2GARY`

# answer3

**1. 访问单通道图像**

之前一直使用的是迭代器访问数据，比如`Mat.at<Vec3b>(y,x)[0]`访问的是3通道图像的中某个通道和某个坐标的像素。但是如果方位单通道图像时候，没有`Vec1b`这种向量结构。此时，可以直接使用像素类型，如`Mat.at<uchar>(y,x)`访问单通道的图像。