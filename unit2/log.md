# answer11

1. **GDB报错**`This GDB was configured as "x86_64-w64-mingw32".
Type "show configuration" for configuration details.` 显然它讲的是GDB是64为的架构，程序不是64位的，在exe文件夹加入64位的dll就好了。

# ansewr12 and answer13 

1. 为指针动态申请内存 `int *a=new int[n]`

# answer 15

1. 进行sobel处理之后，有的像元值为负数，有的像元值为正数，使用下列代码，把值转化到0-255
```c++
 fmax(piexl,0);
 fmin(poexl,255)
 ```

 2. 滑动窗口可以使用更巧妙的方法实现，嵌套四个for循环加一个if判断是否出界。
 

