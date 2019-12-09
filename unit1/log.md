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

# ansewr4

1. 大津法二值化图像 
    
    当类间距离最大的时候，取其阈值为最终阈值。类间距离表示方式为`w0*w1*(m0-m1)*(m0-m1)`

    算法比较简单，但是由于编程习惯，没有了VS的智能提示，导致出现了几个坑。
    * 类型转换，int->double,导致数据变为0；
    * 控制变量在重新回到循环的时候没有归为0，导致上一次的累加结果进入到下一次的计算。
    * 注意Mat类的类型，对应的通道等，不同的函数要求的类型不一致。

# ansewr5 

1. RGB->HSV,然后色相(H)反转,然后HSV->RGB

    要注意变量的强制类型转换，char->float,double等。

# answer6

1. 过于简单hhh

# answer7

1. 过于简单

# answer8

1. 过于简单

# answer9

1. 过于简单

# answer10
    
1. 使用内置排序函数，`std::sort(array,attay+size);`

2. 写滤波函数的时候，可以使用填充边界的策略，也可是使用获取窗口的左上角和右下角的坐标来获取滑动窗口的范围，这样就不会越界了。


