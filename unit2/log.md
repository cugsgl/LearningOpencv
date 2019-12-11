# answer11

1. **GDB报错**`This GDB was configured as "x86_64-w64-mingw32".
Type "show configuration" for configuration details.` 显然它讲的是GDB是64为的架构，程序不是64位的，在exe文件夹加入64位的dll就好了。

# ansewr12 and answer13 

1. 为指针动态申请内存 `int *a=new int[n]`