// 第12章 存储类别.链接和内存管理
#include <stdio.h>
#include <stdlib.h>
void memory_allocation(void);

void main(void){
    memory_allocation();
    return;
}

// storage class 存储类别

// 面向对象语言的对象(object)指的是
//  类对象,对象包括数据(属性)和允许对数据的操作(方法)

// C语言(面向过程语言)中的对象:
// 1.从硬件方法看,每个值都占用物理内存(也有占用寄存器的),
// C语言用术语对象object来表示这一块内存 
// 一个对象可以存储一个或多个值
// 一个对象也可能还没有一个存储值
// 但它能以正确的存储长度保存相应的值
// 2.从软件方面看,程序需要一个方法去访问对象
// 通过声明变量来完成

// malloc 全称:memory allocation
// allocation 分配,拨给的场地
void memory_allocation(void){
    // 使用malloc()函数创建数组
    char * char_pointer;
    int * int_pointer;
    // sizeof 数据类型关键字
    int_pointer = (int *)malloc(4 * sizeof(int));
    *int_pointer = 1;
    *(int_pointer + 1) = 2;
    *(int_pointer + 2) = 3;
    *(int_pointer + 3) = 4;

    printf("%zd\n", sizeof(int));
    printf("%d\n", 4 * sizeof(int));

    printf("%d\n", *int_pointer);
    printf("%d\n", *(int_pointer + 1));
    printf("%d\n", *(int_pointer + 2));
    printf("%d\n", *(int_pointer + 3));
    return;
}