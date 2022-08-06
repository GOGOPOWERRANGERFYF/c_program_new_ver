#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void * task(void *);
void * task_add_mutex_lock(void *);

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

int main(void) {
    printf("sizeof pthread_mutex_t variable: %zd bytes.\n", sizeof lock);

    pthread_t pthread1, pthread2, pthread3, pthread4;
    void * task_return1, *task_return2;
    // arg1: 指向线程标识符的指针
    // arg2: 线程属性,如果默认,则传入NULL
    // arg3: 线程运行函数的地址,即函数指针(c函数名就为函数指针)
    // arg4: 传入运行(线程)函数的参数
    pthread_create(&pthread1, NULL, task, NULL);
    pthread_create(&pthread2, NULL, task, NULL);
    // arg1: 线程标识符,线程ID
    // arg2: 存储以不同方式结束的线程(函数)的返回值,没兴趣知道的可直接传NULL
    //       传入NULL,该参数就不存储被等待线程(函数)的返回值
    // 以阻塞的方式等待一个线程结束
    // join 加入;并集
    pthread_join(pthread1, NULL);
    pthread_join(pthread2, NULL);
    printf("%d\n", sum);

    pthread_create(&pthread3, NULL, task_add_mutex_lock, NULL);
    pthread_create(&pthread4, NULL, task_add_mutex_lock, NULL);
    pthread_join(pthread1, NULL);
    pthread_join(pthread2, NULL);
    printf("%d\n", sum_lock);
    return 0;
}

void * task(void * void_pointer) {
    for (int i = 0; i < 1000; i++) {
        sum++;
        // sum++执行完毕后,
        // 挂起线程10微秒(千分之一毫秒),为什么要挂起?
        // usleep返回0为成功.
        usleep(10);
    }
    return NULL;
}

void * task_add_mutex_lock(void * void_pointer) {
    for (int i = 0; i < 1000; i++) {
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
