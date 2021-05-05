#include <stdio.h>
#include <math.h>
int true_value(void);

int main(void)
{
    const double PI = 3.14159;
    double double_input;
    true_value();
    //while循环经常依赖测试表达式作比较,
    //一般常用的表达式为关系表达式(relational expression)
    //出现在关系表达式中的运算符被称为关系运算符(relational operator)
    // <c primer plus第六版> P328 表6.1 关系运算符
    // absolute value 绝对值
    scanf("%lf", &double_input);
    // fabs函数,返回值为浮点数的绝对值
    // double_input和PI的差的绝对值小于等于0.0001,while循环才会结束
    while (fabs(double_input - PI) > 0.0001){
        printf("No! input again: ");
        scanf("%lf", &double_input);
    }
    return 0;
}

//表达式一定有一个值,关系表达式也不例外
//表达式为真的值是1,表达式为假的值是0
//  while (q){
//      printf("q\n");
//  }
//  测试表达式q的值为真1
//关系表达式为真,求值为1;关系表达式为假,求值为0
//*在C中,所有非零值都为真(1),只有0被视为假,表达式一定有一个值,函数大部分也要返回值(这句话是核心,重点)

int true_value(void)
{
    int a;
    //while(a == 1)
    //    printf("true_value() run!");
    return 0;
}

// == 关系相等运算符:  检查左值右值是否相等(比较)
// =  赋值运算符:     把右值赋给可修改的左值
// 关系运算符用于构建关系表达式
// 5 == n , n == 5是一样的
//
// 总结: 
// 关系表达式真时值为1,关系表达式值为假时值为0
// 在C中,所有非零值为真,0为假,表达式都有一个值,函数大部分都有返回值









