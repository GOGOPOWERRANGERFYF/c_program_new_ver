/*
    设计模式最开始是针对面向对象语言提出的。
    C++的三个重要特性:继承、封装、多态。
    C也可以实现面向对象,也可以应用设计模式。
*/
#include <stdio.h>
// 继承性
struct super_class;
struct sub_class;
typedef struct super_class {
    unsigned int id;
    // 1.函数签名知识点; 2.C声明语法中()优先级比*高
    int (*printObjectInfo)(void);
} super_class;
typedef struct sub_class {
    super_class super_class;
} sub_class;

sub_class * initObject(void);
int printObjectInfo(void);

int main(void) {
    // 函数名就是指向函数的指针常量,所以下面的两个输出结果是一样的。
    //printf("%p %p\n", printObjectInfo, &printObjectInfo);
    // 通过函数指针调用函数(函数调用的本质)
    //subClass_object.super_class.printObjectInfo();

    sub_class * sub_class_pointer;
    sub_class_pointer = initObject();
    sub_class_pointer->super_class.printObjectInfo();
    return 0;
}

sub_class * initObject(void) {
    sub_class subClass_object, *subClass_object_pointer;
    // 下面两个语句是等价的。
    //subClass_object.super_class.printObjectInfo = printObjectInfo;
    subClass_object.super_class.printObjectInfo = &printObjectInfo;
    subClass_object_pointer = &subClass_object;
    return subClass_object_pointer;
}

int printObjectInfo(void) {
    printf("This is object\n");
    return 0;
}

// 封装性 (20211106待学习)
