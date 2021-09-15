#include <stdlib.h> //malloc函数原型头文件
#include "fyf_my_test.h"
int single_linked_list_insert();
typedef struct node {
    int           value;
    struct node * link;    
} node;  

int main(void){
    //struct node * s_node_root_pointer;
    //struct node linked_list_element1;
    //s_node_root_pointer = &linked_list_element1;
    return 0;
}
//  第12章 使用结构和指针
//  
//  12.1 链表
//  链表(linked list)是一些包含数据的独立数据结构(通常称为节点)的集合
//  链表中的每个节点通过链或指针连接在一起
//  程序通过指针访问链表中的节点
//  
//  12.2 单链表
//  在单链表中,每个节点包含一个指向链表下一个节点的指针.
//  链表最后一个节点的指针的值为NULL(NULL指针,第6章知识点).
//  为了记住链表的第一个节点,使用一个根指针(root pointer),
//  根指针指向链表的第一个节点(根指针只是一个指针,不包含任何数据).
//  《c和指针》P235 图示
//  typedef struct node {
//      struct node * link;    
//      int           value;
//  } node;  
//  typedef形式声明一个带标签(tag:node)的结构类型,该结构类型别名为node
//  
//  *链表是动态分配的
//
//  12.2.1 在单链表中插入
//  previous 先前的;以前的;上个  
//  current 当前的
int single_linked_list_insert(){
    node * root_pointer;
    return 0;
}