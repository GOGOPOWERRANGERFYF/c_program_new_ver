#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void * routine(void *);
void * routine_add_mutex_lock(void *);

// mutex 互斥
pthread_mutex_t lock;

int sum = 0, sum_lock = 0;
// 出现问题的原因:
// sum++编译成汇编语言后,一句代码生成多条汇编指令,sum++代码非原子操作,
// 不加锁的情况下无法保证发生进程切换时,sum++语句已经完全执行完毕,因此
// 就无法保证两个线程分别进行一次循环最终结果为sum+2,会出现实际sum+1的情况.
// 出现随机的sum<2000的结果.
// 一个核心,双线程,两个线程是不可能同时运行的,只是两个线程会线程上下文切换执行.
// 发生线程上下文切换,保存当前线程上下文(挂起n微秒),切换/恢复另一个线程上下文,循环往复.
// 关键点:不加锁的话,我们并不能控制线程什么情况下切换(是由内核的系统调度决定的)?
// 操作系统最初的历史,操作系统其实也是一个程序,是管理程序的程序...?

// thread id: t_id

// -l 链接pthread
// gcc thread.c -l pthread

int main(void) {
    //printf("sizeof pthread_mutex_t variable: %zd bytes.\n", sizeof lock);

    pthread_t pthread1, pthread2, pthread3, pthread4, pthread5, pthread6;
    //void * task_return1, *task_return2;
    /*
    // arg1: 指向线程(标识符)的指针,(restrict:限定,限定线程的指针),pthread_t *;
    // arg2: 线程属性(指针),如果默认,则传入NULL,const pthread_attr_t *;
    // arg3: 线程运行函数的地址,即函数指针(c函数名就为函数指针); 开始例程(start routine);
    // arg4: 传入运行线程(函数)的参数,(线程)函数要有形参接收传入的实参;
    pthread_create(&pthread1, NULL, routine, NULL);
    pthread_create(&pthread2, NULL, routine, NULL);
    pthread_join(pthread1, NULL);
    pthread_join(pthread2, NULL);
    printf("%d\n", sum);

    // arg1: 线程标识符,线程ID
    // arg2: 存储以不同方式结束的线程(函数)的返回值,没兴趣知道的可直接传NULL???
    //       传入NULL,该参数就不存储被等待线程(函数)的返回值???
    // 以阻塞的方式等待一个线程结束
    // join 加入;并集
    pthread_create(&pthread3, NULL, routine_add_mutex_lock, NULL);
    pthread_create(&pthread4, NULL, routine_add_mutex_lock, NULL);
    pthread_join(pthread3, NULL);
    pthread_join(pthread4, NULL);
    printf("%d\n", sum_lock);
    */

    pthread_create(&pthread5, NULL, routine, NULL);
    // 阻塞其他线程,等待线程5结束?
    //pthread_join(pthread5, NULL);
    pthread_create(&pthread6, NULL, routine, NULL);
    //pthread_join(pthread6, NULL);

    pthread_join(pthread5, NULL);
    pthread_join(pthread6, NULL);
    /*
        pthread_join()的形象理解,
            |
            |
     create +--------+ pthread_create()
            |        |        
     主线程  |        | 子线程
            |        |        
            |        +
            |       /
            |      /
     join   +-----+ pthread_join()
            |
            |

    join 合并,集合
    join() 等待子线程结束
    */
    printf("%d\n", sum);
    return 0;
}

// routine替换task
void * routine(void * void_pointer) {
    for (int i = 0; i < 1000000; i++) {
        sum++;
        // sum++执行完毕后,
        // 挂起线程10微秒(千分之一毫秒),为什么要挂起?
        // usleep返回0为成功.
        //usleep(100); // 主动触发线程上下文切换;注释后被动由分配给线程的时间片消耗完触发
    }
    return NULL;
}

void * routine_add_mutex_lock(void * void_pointer) {
    for (int i = 0; i < 100000; i++) {
        pthread_mutex_lock(&lock);
        sum_lock++;
        // 挂起线程10微秒(千分之一毫秒)
        // 只是为了实现线程的切换?
        // usleep返回0为成功.
        pthread_mutex_unlock(&lock);
        usleep(10);
    }
    return NULL;
}

// 一、为什么要有锁？
// 1.1 线程安全
// 当多个线程同时操作同一个共享全局变量的时候,就容易出现线程安全问题,
// 线程安全问题只会影响到线程对同一个共享的全局变量的写操作。

/**
 * 博客资料(无正确性保证)：
 * linux的进程和线程都是通过task实现的,2.6内核之后实现了内核级线程(轻量级进程light weight process: LWP),
 * 每个task都有pid,但这并不是我们操作系统定义的pid,task的tgid(task group id)才是是操作系统定义上的pid,
 * 也是我们通常所指的pid.
 * 
 * 在Linux中，无论是进程还是线程，根本上都是通过clone一个已经存在的task实现的, 
 * 二者的差别在于clone时，当CLONE_VM位设置时,共享地址空间，创建线程；
 * 未设置，则创建进程。(克隆虚拟内存vm标志,然后复制内存映射mm)
 * fork -- 创建进程，通过调用0共享的clone实现;
 * pthread_create -- 创建线程，则是通过调用最多共享的clone实现;
 * htop命令的PID、TGID
 * ps命令的PID、LWP
 * 
 * CPU中断引脚接收到中断信号，读取中断内容，CPU流水线，保存当前进程上下文，
 * 执行操作系统预先设置的中断处理程序(interrupt handler)，操作系统恢复控制权
 * 
 * 书籍资料：
 * 《深入理解linux内核(第三版)》P118
 * 创建进程：
 *     传统的Unix操作系统以统一的方式对待所有的进程：子进程复制父进程所拥有的资源。
 *     这种方法使进程的创建非常慢且效率低，因为子进程需要拷贝父进程的整个地址空间。
 *     实际上，子进程几乎不必读或修改父进程拥有的所有资源，在很多情况下，子进程立即
 *     调用execve()，并清除父进程仔细拷贝过来的地址空间。
 *     
 *     现代Unix内核通过引入三种不同的机制解决了这个问题：
 *     
 *     写时复制技术允许父子进程读相同的物理页，只要两者中有一个试图写一个物理
 *     页，内核就把这个页的内容拷贝到一个新的物理页，并把这个新的物理页分配给正
 *     在写的进程。第九章将全面地解释这种技术在Linux中的实现。
 * 
 *     轻量级进程允许父子进程共享每进程在内核的很多数据结构，如页表（也就是整个
 *     用户态地址空间）、打开文件表及信号处理。
 * 
 *     vfork()系统调用...
 * 
 * 
 * 《UNIX环境高级编程》中文第三版 P14
 * 1.9 信号
 *     信号（signal）用于通知进程发生了某种情况。例如，若某一进程执行出发操作，其除数为0，
 * 则将名为SIGFPE（浮点异常）的信号发送给该进程。进程有以下3种处理信号的方式。
 * <个人笔记：SIGFPE实际涵盖所有算数产生的错误，例如除0>
 *     (1) 忽略信号。有些信号表示硬件异常，例如，除以0或访问进程地址空间以外的存储单元
 * 等，因为这些异常产生的后果不确定，所以不推荐使用这种处理方式。
 *     (2) 按系统默认方式处理。对于除数为0，系统默认方式是终止该进程。
 *     (3) 提供一个函数，信号发生时调用该函数，这称为捕捉该信号。通过提供自编的函数，
 * 我们就能知道什么时候产生了信号，并按期望的方式处理它。
 *     很多情况都会产生信号。终端键盘上有两种产生信号的方法，分别称为中断键（interrupt key，
 * 通常是Delete键或Ctrl+C）和退出键（quit key，通常是Ctrl+\），它们被用于中断当前运行的进程。
 * 另一种产生信号的方法是调用kill函数，在一个进程中调用此函数就可向另一个进程发送一个信
 * 号。当然这样做也有些限制：当向一个进程发送信号时，我们必须是那个进程的所有者或者是超级
 * 用户。
 * 
 * 实例
 *     ...
 *    为了能捕抓到此信号，程序需要调用signal函数，其中指定了当产生SIGINT信号时
 * 要调用的函数的名字。...
 *     
 *     ...
 * 
 * 因为大多数重要的应用程序都对信号进行处理，所以第10章将详细介绍信号。 
 * 
 * 1.10 时间值
 *     历史上，UNIX系统使用过两种不同的时间值。
 *     (1) 日历时间。...
 *  
 *  ...
 * 
 *  第10章 信号
 *  10.1 引言
 *     信号是软件中断。很多
 * 
*/
