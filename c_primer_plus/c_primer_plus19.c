#include <stdio.h>
#include <iso646.h>
#define SPACE ' '
#define COMMA ','
int char_count(void);
int lower_character(void);

int main(void)
{
    char_count();
    lower_character();
    return 0;
}

int char_count(void)
{
    char ch;
    unsigned int count = 0;

    while ((ch = getchar()) != '.'){
        if (ch != SPACE && ch != COMMA){
            count++;
        }
    }

    printf("character count: %d\n", count);
    ch = getchar();
    printf("function char_count last input(%%d): %d\n", ch);
    return 0;
}

// 逻辑运算符 logical operator
// && 与  左右两边的运算对象都为真,整个表达式的值为真
// || 或  左右两边的运算对象只要有一个为真,整个表达式的值就为真
// !  非  运算对象为真,整个表达式的值为假;运算对象为假,整个表达式的值为真
//
// <c primer plus第六版> P440
//        iso646.h
// && 与    and
// || 或    or
// !  非    not
// iso646.h头文件定义了一批常用运算符的可选拼写(定义了宏)
// 因为不同地区的键盘是有不同的,有的键盘不一定有美式键盘的一些符号
// 但我是直接用美式键盘的,因此对这个无感...
// 目的:解决有的键盘没有这些符号的问题
// alternative n 可供选择的; adj 可供替代的
// spellings   拼写
// 感觉翻译成 可供替代的拼写 更好理解

// 简而言之:非美式键盘与可能没有某些符号键,导致不能输入某些运算符,
//         因此C的iso646.h头文件定义了一组宏,提供了可替代的拼写,代替无法输入的运算符
// 宏的定义有点像符号常量

// <c primer plus第六版> P440
// 逻辑运算符优先级
// !优先级之比圆括号运算符低,与递增运算符相同,(应该+/-正负运算符也是一样的)
// &&和||的优先级比关系运算符低,比赋值运算符高
// &&优先级比||高

// 运算符优先级operator precedence暂时小结(不全):
// ()圆括号 
// >> !逻辑运算符非,+/-正负符号,++/--自增自减运算符
// >> + - * / % 加减乘除 模除 
// >> == != > >= < <= 关系运算符 
// >> &&逻辑运算符与and >> ||逻辑运算符或or
// >> =赋值运算符和+=等组合赋值运算符 
// >> ,逗号运算符comma

// <c primer plus第六版> P440
// *我觉得是很重要的一个知识点:求值顺序
// 两个运算符共享一个运算对象,运算顺序取决与运算符优先级(例如:5+3-2 5+3*2)
// 除了两个运算符共享一个运算对象的情况外,C通常不规定复杂表达式的哪个部分先求值
// a = (5 + 3) * (2 - 1)
// C把先求值5+3,还是先求值2-1的决定权交给编译器的设计者
// 但c保证&&和||的求值顺序从左往右(还有一个是逗号运算符)
// &&或||是一个序列点,左侧项副作用发生完才会执行下一步运算

// C语言的陷阱...
// C只有两个运算符共享一个运算对象,&& || , ?:运算符的求值顺序是确定的
// 因此要多点用(),不然在不同的编译器、操作系统、特定机器下,运算结果可能会有不同
// 多用()才是一个好习惯...

// 短路计算:
// &&  operand1为0假,短路计算,整个逻辑表达式为假
// ||  operand1为1真,短路计算,整个逻辑表达式为真 

// *重要概念
// 优先级: 决定运算对象与相邻两个不同运算符(我感觉更精确的说法是优先级不同的运算符)的结合顺序
// 结合律: 决定运算对象与相邻两个相同优先级运算符的结合顺序
// 3 + 2 * 5    *优先级比+高,2先与5结合
// 3 + 2 - 5    +和-优先级相等,按结合律从左往右结合,先+后-

// 简而言之:两个运算符共享一个运算对象,与运算符优先级高的结合;运算符优先级相等的,根据结合律(从左往右或从右往左)

// a = 2 && 1 < 2 (&&右侧的操作数为1 < 2的值,所以可以把1 < 2看作&&右侧的操作数)
//解析: 根据优先级,操作数2与&&结合,对左侧操作数求值为2
//      c规定&&求值顺序从左往右,&&作为序列点,左侧操作数副作用发生完,再对右侧操作数求值
//      根据优先级,操作数1与<结合,1 < 2子表达式为&&的右操作数,求值结果为1
//      &&表达式结果为1,再把1赋值给a
//
// && || 逻辑运算符,序列点,保证左侧操作数求值完(副作用发生完),再对右侧操作数求值
// , 逗号运算符,序列点,同上
// ; 序列点,左侧语句副作用发生完,再执行右侧语句

int lower_character(void)
{
    char ch;
    int n;
    printf("\na: %d ,z: %d.\n", 'a', 'z');
    printf("lower character:\n");
    for (ch = 'a'; ch <= 'z'; ch++){
    // char,shor int运算时被升级(promotion)成int类型
    // for (ch = 97; ch <= 122; ch++){
        printf("%c ", ch);
    }

    printf("\n");
    for (n = 90; n <= 130; n++){
        if (n >= 'a' && n <= 'z'){
            printf("Lower character, %d, %c\n",
            n, n);
        }
        else {
            printf("Not lower character: %d.\n",
            n);
        }
    }    
    return 0;
}

// <c primer plus第六版> P443
// EBCDIC不像ASCII码那样连续编码和相邻字符一一对应
// 因此不能像ASCII码处理
// 要判断EBCDIC是否为小写字符,用islower()函数来处理
// islower()函数原型声明在ctype.h头文件


