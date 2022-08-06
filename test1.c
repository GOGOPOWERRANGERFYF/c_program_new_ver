#include <stdio.h>
#include <unistd.h>

// MMU(内存管理单元)处理虚拟内存与物理内存
// 编译生成了两个程序,分别运行后挂起,
// MMU实际给两个相同的虚拟地址分配了不同的物理地址
// 有了MMU才实现了所谓的进程,有了进程的私有地址空间,没有MMU只有线程
// 所以私有地址空间是物理地址的私有,而分配的虚拟地址实际是有重复分配的?
int a = 15;
int main(void) {
    printf("%p, %d\n", &a, a);
    sleep(15);
    return 0;
}

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
