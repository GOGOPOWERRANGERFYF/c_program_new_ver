'''
python虚拟机的个人理解:
    python虚拟机通过操作系统的系统调用创建的进程和线程,因此它们都有相应的系统级别的进程和线程。
    相当于在操作系统的进程和线程上再"封装"了一层。
    我们平时正常对python进程和线程的使用是通过python虚拟机调用解释器动态编译字节码来执行实现的。
    进程实现资源的隔离。线程是基本的CPU调度单位。
    

'''