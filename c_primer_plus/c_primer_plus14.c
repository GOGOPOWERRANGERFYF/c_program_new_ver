#include <stdio.h>
int while_null_statement(void);
//scanf()函数返回值,读取成功返回1,读取失败返回0
int main(void)
{
    //这里用long int类型常量(constant)0L,
    //用0其实也没问题(int类型常量0会隐式转换为long int)
    //但还是建议保持数据类型的一致性
    long int num, sum = 0L;
    unsigned short int status;
    
    printf("input integer:");
    status = scanf("%ld", &num);
    printf("status: %hu\n", status);
    //该while循环的测试条件(test condition)为如下表达式(expression),也是(full expression)
    // status == 1 (这表达式结束就是一个序列点sequence point)
    // == 相等运算符(equality operator)
    // status == 1 status是否等于1
    // status = 1  赋值1给变量status
    while (status == 1){
    //只有对测试条件求值时,才决定继续还是终止循环
        sum = num + sum;
        printf("sum: %ld\n", sum);
        printf("input integer:");
        status = scanf("%ld", &num);
    }
    while_null_statement();
    printf("Game Over!\n");
    return 0;
}

// 数学小知识点:
//    -1000 - 0001 = -1001  
//    减去一个数,加上它的二补数
// =  10000 - 1000 + 10000 - 0001    
// = 100000 - 1001
// =  10111
// 假设位宽为4bit,结果为0111
// B2T(0111)= 7
// B2T(10111)= -16 + 7 = -8    最高位位权: -2^4
// 7 + (-2^4) = 8
//
// * clang是llvm编译系统(low level virtual machine)的前端
//   llvm  objdump -d -x86-asm-syntax=intel
//   与gcc objdump -d -m intel 不相同

// iteration 迭代
// multiplexer 多路复用器

// while循环的通用形式:
//     while (expression)        
//        statement
// statement可以是以分号结束的简单语句,也可以是花括号括起来的复合语句
//
// expression都是使用关系表达式,expression的值为非零(真),执行statement部分一次
// 再判断expression
// 直到expression值为0(假),循环结束
// 每次循环都称为一次迭代(iteration)
//

// entry condition 入口(进入)条件
// while (expression)           这里的expression(表达式)是一个入口条件
// 必须满足条件才会进入循环体
// infinite loop 无限循环

// 1.
// while (n < 3);
// 2.
// while (n < 3)
// ;
// 推荐用第二种方式
// 测试条件后面的语句
// ; null statement空语句
//
// *不同系统对回车的处理是不同的:
//    1. windows /r/n   ascii(decimal): 13 10
//    2. linux   /n     ascii(decimal): 10
//    3. mac     运行下面这段代码可得出结果
//    (对不对还要写代码验证,网上查是这么说的...)
// 换行 ascii 10
// 回车 ascii 13
// q ascii 113
int while_null_statement(void)
{
    char var, char_a;
    // char,short类型自动转换为int
    scanf("%c", &var);
    printf("c_0: %hd\n", var);
    //%c scanf函数的conversion specification会读取键盘的enter字符
    while (scanf("%c", &char_a) == 1){
        printf("c_1: %hd;\n input: ", char_a);
        scanf("%c", &var);
        printf("c_2: %hd\n", var);
    }
    return 0;
}

