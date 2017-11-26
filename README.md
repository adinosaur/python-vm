python-vm
==========


## About
在一个进程中嵌入多个python vm，并且可以并行的在多个线程上运行。原理是通过加载多份dll或是so，使得每个python vm 使用不同的代码和数据。

## Usage
在磁盘上拷贝多份python的动态连接库（windows下是pythonX.Y.dll，linux则是libpythonX.Y.so），动态连接库的命名参考代码。

windows直接打开vs编译，linux下编译命令如下：
`g++ -g -D linux -std=c++11 python_vm.cpp main.cpp -pthread -ldl`
