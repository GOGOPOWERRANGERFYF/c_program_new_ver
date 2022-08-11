#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    pid_t pid = getpid();
    pid_t ppid = getppid();
    printf("创建当前进程的父进程ID:%d\n当前进程ID:%d\n", ppid, pid);

    pid_t current_pid;
    // 子进程返回0;父进程返回子进程的PID;
    printf("fork开始创建子进程==============>\n");
    pid_t child_pid_and_child_p_return = fork();
    //printf("%d\n", child_pid_and_child_p_return);
    //printf("子进程结束? %d\n", child_pid_and_child_p_return);
    //printf("after %d\n\n", child_pid_and_child_p_return);

    // 重点:父进程和子进程的并发,进程的时间片由内核调度器分配,
    // 输出结果随机
    if (child_pid_and_child_p_return == 0) {
        printf("子进程:%d 开始执行...\n", getpid());
        for (int i = 0; i < 10; i++) {
            printf("这人是个大傻子!\n");
        }
        printf("子进程:%d 结束...\n", getpid());
        exit(0);
    }

    if (child_pid_and_child_p_return != 0) {
        printf("父进程:%d 开始执行...\n", getpid());
        for (int i = 0; i < 10; i++) {
            printf("这人是个大聪明!\n");
        }
        printf("父进程:%d 结束...\n", getpid());
        exit(0);
    }
    //return 5;
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
