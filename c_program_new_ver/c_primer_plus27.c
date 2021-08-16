//  第14章 结构和其他数据形式
//
//  结构和联合这部分内容《c和指针》第10章讲得更深入
//  数组和结构是聚合数据类型
//  联合不被认为是聚合数据类型
//  《c primer plus》语法大而全,但原理部分讲得很浅
//  确实是一本像字典一样的工具书啊...
//  不说了...转到c_and_pointer1.c去了...

#include <stdio.h>
struct struct_a{
    char c1[10];
    float fa;
};
struct struct_b{
    char c2[10];
    int i1;
    float fa;
};

void main(void){
    struct struct_a struct_a1, * struct_a_pointer;
    struct struct_b struct_b1, * struct_b_pointer;
    struct_a_pointer = &struct_a1;
    struct_b_pointer = &struct_b1;

    printf("sizeof(struct struct_a): %zd\n", sizeof(struct struct_a));
    printf("sizeof(struct struct_b): %zd\n", sizeof(struct struct_b));

    printf("&struct_a1: %p\n", &struct_a1);
    printf("&struct_a_pointer: %p\n", struct_a_pointer);
    printf("&struct_a_pointer + 1: %p\n", struct_a_pointer + 1);
    printf("sizeof(struct_a1): %zd\n", sizeof(struct_a1));

    //printf("&struct_b1: %p\n", &struct_b1);
    //printf("&struct_b_pointer: %p\n", struct_b_pointer);
    //printf("&struct_b_pointer + 1: %p\n", struct_b_pointer + 1);
    printf("sizeof(struct_b1): %zd\n", sizeof(struct_b1));

    //个人笔记:
    //一个重点:结构变量占用的存储空间并不等于结构个成员储存空间之和
    //         通过sizeof运算符可得验证
    //网上资料:想知道结构(网上一般叫结构体...)的特定成员(在结构体)的位置
    //         则使用offsetof宏(定义位于stddef.h)
    return;
}

//  第14章 结构和其他数据形式
//  关键字: struct,union,typedef
//  运算符: .   ->
//  表示数据的方法,简单变量甚至数组还不够
//  C提供了结构变量(struct variable)

//  14.1 示例问题:创建图书目录
//  pass

//  14.2 建立结构声明
//  结构声明(struct declaration)描述了一个结构的组织布局
//  (有时我们把结构声明成为模板,它勾勒出结构是如何储存数据的)
//  struct book{
//      char title[100];
//      char author[10];
//      float value;
//  };
//  book为标签(label),程序中使用标签引用该结构
//  struct book a
//  声明a为book结构变量(使用book结构布局的的结构变量)
//  在结构声明中,用一对花括号括起来的是结构成员列表
//  每个成员都用自己的声明来描述(就是简单的变量声明)
//  成员可以是任意的C数据类型,甚至可以是其它结构
//  右边花括号的;分号是必须的,表示结构布局定义结束
//      (结构声明结束会不会更容易理解呢...)
// 结构声明放在所有函数外部,声明之后的所有函数都能通过
// 标签使用它
// 结构声明放在函数内部,它的标签只限于函数内部使用
// 附加:标签是可选项,但要在其它地方声明该结构变量必须有标签
//      另一种声明结构变量的方式,结构声明右花括号后直接加结
//      构变量的变量名

// 14.3 定义结构变量
// 结构有两层含义:
//  1.一层含义是"结构布局(struct design)"
//      结构布局告诉编译器如何表示数据,
//      但并未让编译器为数据分配空间
//  2.创建一个结构变量,既是结构的另一层含义
//  struct book a;
//  编译器使用book模板(template)为a变量(结构变量)分配空间
//      
//  

// 14.6.1 声明和初始化结构指针
//  *在有些系统中,一个结构的大小可能大于它各成员大小之和.
//  这是因为系统对数据进行校准的过程中产生了一些"缝隙".
//  

// 14.10 联合简介
// 联合(union)是一种数据类型,它能在同一个内存空间中储存不同的数据类型(不是同时储存)
//







// 14.14 函数和指针
// 重点：函数指针的知识点
//
