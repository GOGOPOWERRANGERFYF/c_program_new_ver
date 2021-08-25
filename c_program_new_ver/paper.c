#include <stdio.h>
int func_1(int *);
float func_2(int);
// 声明函数指针，全局变量
// 可以把类型匹配的函数地址赋值给函数指针变量
// int function_signature(int *); 
// 除掉函数名function_signature剩下的为函数签名
//
// (*function_signature)要用圆括号运算符,圆括号运算符用来控制表达式运算优先级
// 不然根据运算符结合律，*间接运算符于左边的运算对象int先结合
// 则函数原型声明为函数返回值类型为整型指针类型
//
// 重点，其实理解了计算机组成原理的寻址方式
// 立即寻址，直接寻址，间接寻址就很容易理解
// 个人的理解心得：函数名，机器指令中直接给出函数地址，直接寻址
//               *函数指针，机器指令中给出函数指针的地址，先读取函数指针，再访问函数，间接寻址
int (*function_signature)(int *);

typedef struct fyf_object{
    int fyf_object_int;
    // 函数指针类型成员
    float (*fyf_object_function_pointer)(int);
} fyf_object;

// 了解内容(网络内容)：void 无类型；void * 无类型指针，可以指向任何类型的指针
void main(void){
    // function_signature = func_2;
    // 无效赋值，函数签名中的函数返回值类型和函数形参类型都不匹配
    // function_signature = func_1();
    // 无效赋值，func_1()不是函数地址，而是函数的返回值

    function_signature = func_1;
    // & 取地址运算符；* 间接运算符 
    // &*p 两个运算符相互抵消，*通过指针访问，然后&再取指针
    printf("function_signature:%p\n", function_signature);
    printf("func_1:%p\n", func_1);

    fyf_object fyf_object_1;
    fyf_object_1.fyf_object_function_pointer = func_2;
    printf("fyf_object_1.fyf_object_function_pointer:%p\n",
     fyf_object_1.fyf_object_function_pointer);
    printf("func_2:%p\n", func_2);

    return;
}

int func_1(int * temp){
    printf("func_1\n");
    return 0;
}

float func_2(int temp){
    printf("func_2\n");
    return 0.0f;
}

