#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    pid_t pid = getpid();
    pid_t ppid = getppid();
    printf("创建当前进程的父进程ID:%d\n当前进程ID:%d\n", ppid, pid);

    pid_t current_pid;
    // 子进程返回0;父进程返回子进程的PID;
    printf("fork开始创建子进程==============>\n");
    // fork执行时,会有两个返回值,一个是父进程的返回值,一个是子进程的返回值.
    // 1)在父进程中,fork返回新创建子进程的进程ID;
    // 2)在子进程中,fork返回0;
    // 3)fork失败,返回一个负值-1;
    pid_t child_pid_and_child_p_return = fork();
    //printf("%d\n", child_pid_and_child_p_return);
    //printf("子进程结束? %d\n", child_pid_and_child_p_return);
    //printf("after %d\n\n", child_pid_and_child_p_return);

    // 时间
    clock_t start1, finish1, start2, finish2;
    double time1, time2;

    // 重点:父进程和子进程的并发,进程的时间片由内核调度器分配,
    // 输出结果随机
    if (child_pid_and_child_p_return == 0) {
        start1 = clock();
        printf("子进程:%d 开始执行==>\n", getpid());
        for (int i = 0; i < 1000000; i++) {
            if (i % 100000 == 0) printf("子进程执行循环中...100000次\n");
        }
        printf("子进程:%d 结束...\n", getpid());
        finish1 = clock();
        time1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
        printf("time: %fs\n", time1);
        exit(0);
    }
    // 等待子进程结束,才开始执行之后的代码
    waitpid(child_pid_and_child_p_return, NULL, 0);

    if (child_pid_and_child_p_return != 0) {
        start2 = clock();
        printf("父进程:%d 开始执行==>\n", getpid());
        for (int i = 0; i < 1000000; i++) {
            if (i % 100000 == 0) printf("父进程执行循环中...100000次\n");
        }
        printf("父进程:%d 结束...\n", getpid());
        finish2 = clock();
        time2 = (double)(finish2 - start2) / CLOCKS_PER_SEC;
        printf("time: %fs\n", time2);
        exit(0);
    }
}

//int main(void) {
//    char c = 0b10001000, temp;
//    temp = c >> 4;
//    printf("%x\n", temp);
//    temp >>= 4;
//    printf("%x\n", temp);
//    return 0;
//}

//int main(void) {
//    int a = 10;
//    if (a >= 20) {
//        printf("a >= 20\n");
//    } else {
//        printf("a < 20\n");
//    }
//    return 0;
//}

// MMU(内存管理单元)处理虚拟内存与物理内存
// 编译生成了两个程序,分别运行后挂起,
// MMU实际给两个相同的虚拟地址分配了不同的物理地址
// 有了MMU才实现了所谓的进程,有了进程的私有地址空间,没有MMU只有线程
// 所以私有地址空间是物理地址的私有,而分配的虚拟地址实际是有重复分配的?
//int a = 15;
//int main(void) {
//    printf("%p, %d\n", &a, a);
//    sleep(15);
//    return 0;
//}

/*
#include <stdio.h>
int f1(int);

int main(void) {
    int arg1;
    f1(arg1);
    return 0;
}

int f1(int arg) {
    printf("%d\n", arg);
    return 0;
}
*/
