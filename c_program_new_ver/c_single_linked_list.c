#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    struct node * next_node_pointer;
    int integer_data;
} node;
//} node, * root_pointer;
// root_pointer为node结构指针类型的别名
// typedef int * int_p;
// 创建int指针类型别名int_p

// struct node {
//     struct node * next_node_pointer;
//     int integer_data;
// } node;
// 
// typedef struct node * root_pointer;
// 为node结构指针类型创建别名

node * single_linked_list_init(void);
node * single_linked_list_create_head(void);
node * single_linked_list_create_tail(void);

int main(void){
    node * header_p, pointer_temp;

    //pointer_temp = single_linked_list_init();
    //printf("pointer_temp = header_pointer: %p\n", pointer_temp);
    //printf("pointer_temp->next_node_pointer: %p\n",
    // pointer_temp->next_node_pointer);

    header_p = single_linked_list_create_head();
    printf("header_p: %p\n", header_p);
    printf("%d\n", header_p->next_node_pointer->integer_data);


    return 0;
}

//单链表初始化(作用:创建一个空链表?)
//函数返回值为node类型指针变量
node * single_linked_list_init(void){
    node * root_pointer;
    root_pointer = (node *)malloc(sizeof(node));
    //判断动态内存分配是否成功
    if (root_pointer == NULL){
        printf("memory allocation failed!");
    }
    root_pointer->next_node_pointer = NULL;
    return root_pointer;
}

// EOF(end of file)
// c_primer_plus21.c 《c primer plus》第8章
// 个人理解:
//  C处理流(stream)而不是直接处理文件
//  正在读取的键盘输入不是文件怎么办?
//  绝大部分系统(不是全部)都有办法通过键盘模拟文件结尾条件
//  

// 带表头(header)的链表

//头插法创建单链表
node * single_linked_list_create_head(void){
    //为根节点分配内存空间
    node * root_node_pointer;
    root_node_pointer = (node *)malloc(sizeof(node));
    //给(根节点)结构成员(指针类型成员)赋值NULL
    root_node_pointer->next_node_pointer = NULL;

    int int_temp;
    //while(scanf("%d", &int_temp) == 1){
    //getchar()和scanf()读取文件检测到文件结尾时返回一个特殊值EOF
    //正在读取的键盘输入不是文件怎么办?
    //unix中文件结尾为换行,Ctrl+d,键盘输入模拟文件结尾(end of file)
    //windows中文件结尾Ctrl+d,键盘输入模拟文件结尾(end of file)
    //(windows没试过,不知道要不要换行)
    //(不同操作系统的end of file并不相同)
    //当scanf()读取到结尾时,结束循坏
    while(scanf("%d", &int_temp) != EOF){
        node * node_pointer;
        node_pointer = (node *)malloc(sizeof(node));
        //赋值给结构成员(整型成员)
        node_pointer->integer_data = int_temp;
        //赋值给结构成员(结构指针成员)
        //node_pointer->next_node_pointer = NULL;
        node_pointer->next_node_pointer = root_node_pointer->next_node_pointer;
        //赋值给根节点结构成员(结构指针成员)
        //root_node_pointer为指向根节点(root pointer)的指针
        root_node_pointer->next_node_pointer = node_pointer;
    }
    return root_node_pointer;
}

//尾插法创建单链表
node * single_linked_list_create_tail(void){
    node * header_pointer;
    //分配(header)头节点空间(内存存储空间)
    header_pointer = (node *)malloc(sizeof(node));
    //结构指针成员赋值为NULL
    header_pointer->next_node_pointer = NULL;
    //移动的指针,作用:始终指向最后一个节点(结构变量)
    node * move_pointer = header_pointer;

    int int_temp;
    while(scanf("%d", &int_temp) != EOF){
        node * new_node_pointer;
        //指向node结构变量的指针(就像指向其它类型变量的指针一样)
        //不同类型指针的意义:
        //  1.知道变量的地址;
        //  2.知道如何正确读取变量(数据存储长度);
        //  结构变量的话还知道结构成员的地址和存储长度
        new_node_pointer = (node *)malloc(sizeof(node));

        //个人理解:
        //  源代码理解:
        //      结构指针间接访问结构成员(整数类型变量)
        //  机器码理解(关键:机器码中并没有结构的信息):
        //      
        new_node_pointer->integer_data = int_temp;
        //替换配对1
        new_node_pointer->next_node_pointer = move_pointer->next_node_pointer;

        move_pointer->next_node_pointer = new_node_pointer;
        move_pointer = new_node_pointer;
    }
    //替换配对1
    //move_pointer->next_node_pointer = NULL;
    return header_pointer;
}


