#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define INPUT_FINISH_FLAG '|'
#define LINE_FLAG '\n'

int text_counter(void);
int conditional_operator(void);
int max_integer(void);
int cans_of_paint(void);
int loop_continue(void);
int loop_break(void);

int main(void)
{
    _Bool bool_a;
    bool bool_b;
    int int_a;

    printf("sizeof(int_a):%zd\n", sizeof(int_a));
    printf("sizeof(bool_a):%zd sizeof(bool_a):%zd\n",
     sizeof(bool_a), sizeof(bool_b));
    printf("true:%d false:%d\n", true, false);

    //text_counter();
    //conditional_operator();
    //max_integer();
    //cans_of_paint();

    loop_continue();
    loop_break();
    return 0;
}

// 空白字符(空格,制表符,换行符): ' '，'\t','\n'
// 排除空白字符: c != ' ' && c != '\t' && c != '\n'
// 检查空白字符: c != ' ' || c != '\t' || c != '\n'
//
// c提供了检查空白字符的函数isspace(),函数原型声明在ctype.h头文件
// isspace(c),c为空白字符,函数返回值为真,c为非空白字符,函数返回值为假

int text_counter(void)
{
    bool word_flag = false;
    char ch;
    int lines_counter = 0;    
    int words_counter = 0;

    while ((ch = getchar()) != INPUT_FINISH_FLAG){
        // lines
        if (ch == '\n'){
            lines_counter++;
        }
        // words
        // 遇到第一个非空白字符
        // 如果 字符为非空白字符 且 单词标记为假(伪代码,大白话...)
        if (!isspace(ch) && !word_flag){
            words_counter++;            
            word_flag = true;
        }
        // 读取非空白字符之后读取到的首个空白字符
        // 重置word_flag为假
        // 如果 字符为空白字符 且 单词标记为真
        if (isspace(ch) && word_flag){
            word_flag = false;
        }
    }

    printf("words number:%d\n", words_counter);
    printf("lines number:%d\n", lines_counter);
    return 0;
}

// 条件运算符(唯一一个三元运算符) ?:
// 条件表达式: expression1 ? expression2 : expression3
//     如果expression1的值为真,整个条件表达式的值为expression2的值
//     如果expression1的值为假,整个条件表达式的值为expression3的值
// 非0为真,0为假
// 相当于:
//     if (y >= 0)
//          x = -y;
//     else
//          x = -y;
int conditional_operator(void)
{
    int x, y;
    printf("input y:");
    while (scanf("%d", &y) == 1){
        x = (y >= 0) ? -y : -y;
        printf("x=%d y=%d\n", x, y);
    }
    return 0;
}

int max_integer(void)
{
    int a, b, max;
    while (scanf(" %d %d", &a, &b) == 2){
        max = (a > b) ? a : b;
        // a > b  a为最大值:取a值
        // 以下为!(a > b)的两种情况:取b值
        // a = b  a和b都为最大值,因此取a值或b值都是一样的
        // a < b  b为最大值
        printf("max=%d\n", max);
        
        //条件运算符的第2和第3个运算对象可以是字符串        
        printf("%s", (a > b) ? "a > b" : "a <= b");
        //printf("%s", a > b ? "a > b" : "a <= b");
        //条件运算符优先级比关系运算符低,因此下面的语句效果也是一样的,
        //但上一句可读性更高
    }
}

int cans_of_paint(void)
{
    const int can_area = 20;
    int paint_area, cans;

    printf("tips: input number of paint area\n");
    while (scanf("%d", &paint_area) == 1){
        cans = paint_area / can_area;
        cans += (paint_area % can_area == 0) ? 0 : 1;
        printf("cans of paint: %d\n", cans);
    };
    printf("over!\n");
    return 0;
}

// ?: 条件运算符 是 三元运算符
// 需要三个运算对象,每个运算对象都是一个表达式
// expression1 ? expression2 : expression3 (条件表达式)
// expression1的值为真,则整个表达式的值为expression2的值
// expression1的值为假,则整个表达式的值为expression3的值
// 《c primer plus 第六版 中文版》P453

// 循环辅助: continue和break
int loop_continue(void){
    int array[] = {1, 2, 3, 4, 5}, i;
    for (i = 0; i <= 4; i++){
        if (array[i] <= 3){
            continue;
        }
        printf("%d\n", array[i]);
    }
    return 0;
}

int loop_break(void){
    int array[] = {1, 2, 3, 4, 5}, i;
    for (i = 0; i <= 4; i++){
        if (array[i] >= 3){
            break;
        }
        printf("%d\n", array[i]);
    }
    return 0;
}

// 7.6
// ......
/*
    7.7 多重选择:switch和break
    
*/
// 7.12