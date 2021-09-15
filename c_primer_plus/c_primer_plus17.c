#include <stdio.h>
#include <ctype.h>
int getchar_putchar(void);
int isalpha_function(void);

int main(void)
{
    const double pass_line = 60.0;
    double score;
    int pass_count = 0, input_count = 0;

    printf("Input score:\n");
    // 输入int,scanf函数会把输入值promotion升级为double类型
    while (scanf("%lf", &score) == 1){
        input_count++;
        if (score >= pass_line){
            pass_count++;
        }
    }

    //if (input_count != 0){
    //    printf("How many scores: %d, ", input_count);
    //    printf("How many pass: %d", pass_count);
    //}
    //if (input_count == 0){
    //    printf("No score!");
    //}

    if (input_count != 0){
        printf("How many scores: %d, ", input_count);
        printf("How many pass: %d\n", pass_count);
    }
    else {
        printf("No score!\n");
    }

    getchar_putchar();
    isalpha_function();
    return 0;
}

// if语句被称为branching statement分支语句或selection statement选择语句
// if (expression)
//     statement
//
// if (expression)
//     statement
// else
//     statement
//
// if (expression){
//     statement
// }
// else {
//     statement
// }
//
// statement可以是简单语句或复合语句
// 复合语句必须用花括号括起来成为一个块,跟循环语句是一样的

// getchar()和putchar()函数只处理字符 (它们通常是预处理宏,不是真正的函数,第16章有函数的宏的知识点)
// ch = getchar()与scanf("%c", &ch)效果相同
// putchar(ch)与printf("%c", ch)效果相同
// 不需要转换说明,比scanf()和printf()更快,更简洁
int getchar_putchar(void)
{
    char ch;
    // getchar函数返回值为成功读取的字符
    ch = getchar();
    putchar(ch);
    ch = getchar();
    putchar(ch);
    printf("enter key(ASCII): %d;", ch);
    // escape character 转义字符
    // escape sequence  转义序列
    /* '\' 续行符和转义字符; '\\' 把\转义为符号字符 */
    printf("\\n(ASCII): %d.\n", '\n');
    // short和character会被自动转换(隐式转换)为int,升级(promotion)
    // 所以ch+1为int运算,只是把结果存入ch时会产生溢出截断

    //ch = getchar();
    //while (ch != '\n'){
    //    if (ch == ' '){
    //        putchar(ch);
    //        ch = getchar();
    //    }
    //    else {
    //        putchar(ch + 1);
    //        ch = getchar();
    //    }
    //}
    //把读取输入字符放在while循环测试条件里执行,代码更简洁
    while ((ch = getchar()) != '\n'){
        if (ch == ' '){
            putchar(ch);
        }
        else {
            putchar(ch + 1);
        }
    }
    printf("\n%d\n", ch);
    return 0;
}

// 组合赋值运算符: += -= *= /= (运算符优先级与赋值运算符相等,结合律从右到左)
// 关系运算符:  == != > >= < <= (运算符优先级,大于赋值运算符,小于算术运算符)

// alpha 希腊字母第一个字母. 在字母解释法中,也代表字母A
// ctype.h头文件包含一系列处理字符的函数,参数为特定类型字符,函数返回值为真1或非0,反之为假0
// isalpha()函数的原型声明在ctype.h头文件中
// isalpha()函数接受一个字符作为参数
// 字母字符,函数返回值为真(非0值); 非字母字符,函数返回值为0
int isalpha_function(void)
{
    char ch;
    printf("isalpha('A'): %d\n", isalpha('A'));
    printf("isalpha('f'): %d\n", isalpha('f'));
    printf("isalpha(','): %d\n", isalpha(','));
    // ch = getchar() 读取输入字符并赋给ch字符类型变量
    while ((ch = getchar()) != '\n'){
        if (isalpha(ch)){
            putchar(ch + 1);
        }
        else {
            putchar(ch);
        }
    }
    putchar(ch);
    printf("ASCII: %d\n", ch);
    printf("game over!");
    return 0;
}
// <c primer plus第六版> P421 表7.1 ctype.h头文件中处理字符的函数
// 字符测试函数 测试特定类型字符,是特定类型字符,返回值为真,反之为假0
// 字符映射函数 返回值为修改后的值,但不修改原值

