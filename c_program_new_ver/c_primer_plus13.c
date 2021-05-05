//带参数的函数 <c primer plus> P293
#include <stdio.h>
/* 有兴趣的可以详细了解:ANSI C之前,C的函数声明不是函数原型,只显示函数名和返回值类型(无参数类型) <c primer plus> P295 */
//
//原型(prototype),即函数的声明(function declaration),描述函数的返回值和参数(形参parameter)
//  1.该函数没有返回值(void空)
//  2.声明int类型的参数
void while_loop_function(int n); /* 函数原型声明function prototype declaration */
//int while_loop_function(int n); 函数返回值类型为int

//全局变量(global variable)
int gv_a = 0;

//主函数,程序入口
void main(void)
{
    //局部变量(local variable)
    char c;
    int a;
    float f;
    //自动类型转换
    c = 'A';
    a = 5.5F;
    f = 10;
    while_loop_function(c);
    while_loop_function(a);
    while_loop_function(f);
    while_loop_function(10);
    return;
}

// 函数头圆括号中包含了一个int类型变量n的声明
// 该函数接受一个int类型的参数
void while_loop_function(int n)
{
    while (n-- > 0){
        printf("-");
    }
    printf("\n");
    return;
}

// formal argument / formal parameter 形参(形式参数)
// actual argument / actual parameter 实参(实际参数)
// C99标准中:
//    actual argument / actual parameter term术语 argument实参
//    formal argument / formal parameter term术语 parameter形参
// 1.形参是函数头圆括号中声明的变量,
//   例如: 上面程序的变量n
// 2.实参是函数调用时提供(传递)的值,然后赋给形参
//   例如: 上面程序的 变量c,a,f;
//                   常量10;
//                   表达式也可以,比如 c+1
//
// void while_loop_function(int n) 函数头
// 圆括号中的变量声明创建了称为形参的变量n
//
// while_loop_function(10); 函数调用(function call)
// 把实参10传递给函数
//
// while_loop_function(a);
// 把a的值5赋给n
//
// * 变量名(局部变量local variable)是函数私有的,所以相同变量名在不同函数中是不冲突的
// const 恒定的,不变的
//
// 强制类型转换 --> 显式转换
// 自动类型转换 --> 隐式转换
// 结合律(求值顺序从左到右或从右到左)
// while语句是一种迭代语句
//