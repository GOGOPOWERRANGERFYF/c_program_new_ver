/*
    设计模式最开始是针对面向对象语言提出的。
    C++的三个重要特性:继承、封装、多态。(其实这是软件工程思想,这是不分语言的)
    C也可以实现面向对象,也可以应用设计模式。
    
    重要知识点:
        void* 返回或传入一个指针,但不确定指向的类型时使用;
        空指针作为右值赋值时会隐式转换成相应类型的指针(C++不行);
        你也可以自己显示转换成相应的类型;
*/
#include <stdio.h>
#include <stdlib.h>
// 继承性
typedef struct super_class super_class;
typedef struct sub_class sub_class;
typedef struct super_class {
    unsigned int id;
    char *info_first_element;
    // info为数组的指针
    char (*info)[25];
    // 1.函数签名知识点; 2.C声明语法中()优先级比*高
    //int (*printObjectInfo)(void * pointer);
} super_class;
typedef struct sub_class {
    super_class super_class;
} sub_class;

sub_class * initSubObjectPointer(void);
sub_class initSubObject(void);
int printObjectInfo(void * pointer);

int main(void) {
    // 函数名就是指向函数的指针常量,所以下面的两个输出结果是一样的。
    //printf("%p %p\n", printObjectInfo, &printObjectInfo);
    // 通过函数指针调用函数(函数调用的本质)
    //subClass_object.super_class.printObjectInfo();

    sub_class * sub_class_object_pointer;
    sub_class_object_pointer = initSubObjectPointer();
    //printf("%c\n", sub_class_object_pointer->super_class.info[1]);
    printObjectInfo(sub_class_object_pointer);
    return 0;
}

sub_class * initSubObjectPointer(void) {
    printf(">>>>>> initial start >>>>>>\n");
    sub_class subClass_object, *subClass_object_pointer;
    // 下面两个语句是等价的。
    //subClass_object.super_class.printObjectInfo = printObjectInfo;
    //subClass_object.super_class.printObjectInfo = &printObjectInfo;
    subClass_object_pointer = &subClass_object;
    printf("%p %zd\n",
     subClass_object_pointer->super_class.info, sizeof *(subClass_object_pointer->super_class.info));
    //subClass_object_pointer->super_class.info = "This is superClass info";
    printf("%zd %p\n", sizeof *"This is superClass info", "This is superClass info");
    subClass_object_pointer->super_class.info_first_element = "This is superClass info";
    // 字符指针类型显示转换成指向字符数组的指针类型(参照int类型声明,省略了标识符)
    subClass_object_pointer->super_class.info = (char (*)[25])"This is superClass info";
    printf("> %p %zd\n",
     subClass_object_pointer->super_class.info, sizeof *(subClass_object_pointer->super_class.info));
    return subClass_object_pointer;
}

//sub_class initSubObject(void) {
//    sub_class subClass_object, *subClass_object_pointer;
//    subClass_object.super_class.printObjectInfo = &printObjectInfo;
//    subClass_object_pointer = &subClass_object;
//    return subClass_object;
//}

int printObjectInfo(void * pointer) {
    sub_class * sub_class_pointer;
    sub_class_pointer = (sub_class *)pointer;
    char * p;
    p = sub_class_pointer->super_class.info_first_element;
    // 数组名为数组首元素指针常量(虚拟地址),
    printf("%p %zd\n",
     sub_class_pointer->super_class.info_first_element, sizeof *(sub_class_pointer->super_class.info_first_element));
    // 重要知识点:结构体变量没初始化就使用,会读取到垃圾数据,而且这种错误很难发现。
    printf("%p %zd\n",
     sub_class_pointer->super_class.info, sizeof *(sub_class_pointer->super_class.info));
    for (int i =0; *(p + i) != '\0'; i++) {
        printf("%c", *(p + i));
    }
    printf("\n");
    return 0;
}

// 封装性
// 多态
