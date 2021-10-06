// 类型转换(type conversions)
// 掌握两个重点:
//  1. 类型转换(type conversion)和转换说明(conversion specification) 
//     这个是我个人学习时弄混的点...仅限个人...
//  2. 通常,在表达式和语句中应使用相同类型的常量和变量(我去年买了个表...┗( ▔, ▔ )┛)
//     但还是要了解类型转换规则的,不然出错了都不知道...ヽ(ー_ー)ノ
#include <stdio.h>
void type_conversion_in_expression(void);
void type_conversion_in_assignment_statement(void);
void type_conversion_in_function_argument(void);
void type_conversion_ranking(void);
void type_conversion_example(void);
void type_conversion_cast_operator(void);

void main(void)
{
    //每一个表达式都有一个值
    //函数表达式: 函数调用(有返回值,哪怕是空值)
    type_conversion_in_expression();
    type_conversion_in_assignment_statement();
    type_conversion_in_function_argument();
    type_conversion_ranking();
    type_conversion_example();
    type_conversion_cast_operator();
    return;
}

void type_conversion_in_expression(void)
{
    // 1.当类型转换出现在表达式,无论signed或unsigned的char和short,都会转换成int
    // 较小类型转换为较大类型(size小->大),这些转换称为升级(promotion)
    short int a = 1;
    unsigned short int b = 1;
    // american standard code for information interchange 美国信息交换标准码
    //'A'字符(character)ascii码 十进制:65 
    char c = 'A';

    printf("sizeof(a) %%zd: %zd\n", sizeof(a));
    //短整型变量a,出现在表达式(expression,表达式由运算符和运算对象组成)会被自动转换成int
    printf("sizeof(-a) %%zd: %zd\n", sizeof(-a));
    printf("sizeof(a+1) %%zd: %zd\n", sizeof(a+1));
    
    printf("sizeof(b) %%zd: %zd\n", sizeof(b));
    printf("sizeof(-b) %%zd: %zd\n", sizeof(-b));
    printf("sizeof(b+1) %%zd: %zd\n", sizeof(b+1));
    
    printf("sizeof(c) %%zd: %zd\n", sizeof(c));
    printf("sizeof(c) %%zd: %zd\n", sizeof(-c));
    printf("sizeof(c) %%zd: %zd\n", sizeof(c+1));
    printf("expression: c+1 %%c: %c\n", c+1);
    printf("ascii(decimal:126) %%c: %c\n", 126);

    // unsigned int constant
    // 2^10 = 1024
    printf("sizeof(2147483648U) %%zd : %zd\n", sizeof(2147483648U));
    printf("2147483648U %%x : %x\n", 2147483648U);
    printf("2147483648U %%u : %u\n", 2147483648U);
    printf("2147483648U %%d : %d\n", 2147483648U);
    //<深入理解计算机系统第三版>P79 非规格化的值: mantissa尾数是不隐含1的
    //当exponent阶码全为0时,表示的是浮点数的非规格化形式
    // B2U binary当做unsigned --mapper映射--> 真值true value
    // printf()会把float参数转换成double,因此 %f和%lf在printf函数是一样的,在scanf函数才会区分
    //*非规格化值的用途之一: 表示浮点数的0 (规格化值尾数隐含1.所以无法表达浮点数0)
    //*非规格化值exponent: 0000 0000 000(double); 0000 0000(float)
    //*规格化值的setoff/bias偏置值: bias_1024 , bias_255
    //*非规格化值mantissa尾数全为0: 直接2^0,不用再减去偏置值; 浮点数的0有正负之分 
    //*非规格化值mantissa尾数非全0: 
    //   阶码exponent要减去偏置值(二补数运算,非二补数编码运算,我自己为了方便理解乱创的概念,别较真...)
    printf("9223372036854775808LU %%f: %f\n", 9223372036854775808LU);
    printf("9223372036854775808LU %%e: %e\n", 9223372036854775808LU);
    printf("9223372036854775808LU %%a: %a\n", 9223372036854775808LU);
    printf("---------------- size: 16 character\n");
    printf("%16lx (%%16lx):2251799813685248LU\n", 2251799813685248LU);
    printf("2251799813685248LU %%f: %f\n", 2251799813685248LU);
    printf("2251799813685248LU %%a: %a\n", 2251799813685248LU);
    return;
}

void type_conversion_in_assignment_statement(void)
{
    short int astc_a, astc_x = 10;
    int astc_b = 2147483647, astc_y;
    //4.在赋值表达式语句中,运算结果会转换成 被赋值变量 的类型
    //赋值表达式运算结果降级(demotion)的情况: 存储长度长的赋值给存储长度短的 截断
    printf("sizeof(astc_b) %%zd : %zd\n", sizeof(astc_b));
    printf("sizeof(astc_a) %%zd : %zd\n", sizeof(astc_a));
    printf("sizeof(astc_a = astc_b) %%zd :%zd\n", sizeof(astc_a = astc_b));
    printf("astc_b %%x : %x\n", astc_b);
    astc_a = astc_b;
    printf("astc_a %%hd : %hd\n", astc_a);
    //赋值表达式运算结果升级(promotion)的情况: 存储长度短的赋值给存储长度长的
    printf("sizeof(astc_x) %%zd : %zd\n", sizeof(astc_x));
    printf("sizeof(astc_y) %%zd : %zd\n", sizeof(astc_y));
    printf("sizeof(astc_y = astc_x) %%zd :%zd\n", sizeof(astc_y = astc_x));
    return;
}

void type_conversion_in_function_argument(void)
{
    //5.做为函数参数传递时:
    //  a. char和short被转换成int 暂时还不知道怎么证明,先死记硬背吧...
    //  b. float被转换成double   (scanf函数除外)
    char tcfa_a;
    short int tcfa_b;
    float tcfa_c = 1.5;
    double tcfa_d = 1.5;
    //                 S         E                                  M
    // (float)1.5  --> 0       0111 1111   1000 0000 0000 0000 0000 000
    // (double)1.5 --> 0   011 1111 1111   1000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
    // 下面这行代码输出0,说明tcfa_c类型转换成double
    printf("tcfa_c %%x: %x\n", tcfa_c);
    printf("tcfa_d %%lx: %lx\n", tcfa_d);
    return;
}

void type_conversion_ranking(void)
{
    //3.类型的级别高->低:
    // long double > double > float >
    // unsigned long long int > long long int > unsigned long int > long int >
    // unsigned int > int
    // * short和char没有列出来是因为它们会被升级到 int 或 unsigned int:
    // *   1. 在表达式中
    // *   2. 作为函数的参数传递
    int tcr_a;
    unsigned int tcr_ua;
    long int tcr_b;
    unsigned long int tcr_ub;
    long long int tcr_c;
    unsigned long long int tcr_uc;
    
    float tcr_d;
    double tcr_e;
    long double tcr_f;
    // 总体,浮点数 > 整数(整数之中,相同类型,unsigned > signed.整数类型默认都是signed)
    
    printf("sizeof(tcr_a) %%zd : %zd\n", sizeof(tcr_a));
    printf("sizeof(tcr_ua) %%zd : %zd\n", sizeof(tcr_ua));
    printf("sizeof(tcr_b) %%zd : %zd\n", sizeof(tcr_b));
    printf("sizeof(tcr_ub) %%zd : %zd\n", sizeof(tcr_ub));
    printf("sizeof(tcr_c) %%zd : %zd\n", sizeof(tcr_c));
    printf("sizeof(tcr_uc) %%zd : %zd\n", sizeof(tcr_uc));
    
    printf("sizeof(tcr_d) %%zd : %zd\n", sizeof(tcr_d));
    printf("sizeof(tcr_e) %%zd : %zd\n", sizeof(tcr_e));
    printf("sizeof(tcr_f) %%zd : %zd\n", sizeof(tcr_f));
    return;
}

void type_conversion_example(void)
{
    // *** 注意: 类型转换的 升级 和 降级(表达式,赋值表达式,函数的参数) 
    // *** 不要与 常量,变量 在 输出函数的不同转换说明下的输出混为一谈(对数据对象做不同形式的输出而已)
    // *** 目前我的理解:类型转换和转换说明的区别,会修改数据对象(data object)和不会修改数据对象
    // ***            type conversion 和 conversion specification

    // int 类型转换 float: 很简单粗暴...   65 --> 65.0  
    // 我刚开始想得有点太复杂了(￣ェ￣;)
    // 这是转换结果,转换过程(在计算机中怎么实现)就不懂了...
    
    unsigned int tce_ua;
    int tce_a = 65, tce_b = -65;
    float tce_fb;
    //float tce_fb = tce_a;
    double tce_c = 201.5;

    //tce_fb = tce_a;
    printf("tce_fb %%.2f : %.2f\n", tce_fb);
    printf("tce_fb = 65 %%.2f : %.2f\n", tce_fb = 65);

    //赋值表达式语句,表达式求值结果的类型与被赋值变量的类型一致
    //这里是降级(demotion)
    // double 类型转换 int: 同样也是简单粗暴...直接去掉小数部分(包括小数点)就行了...
    tce_a = tce_c;
    printf("sizeof(tce_a) %%zd : %zd\n", sizeof(tce_a)); 
    printf("tce_a %%d : %d\n", tce_a); 
    printf("tce_a %%x : %x\n", tce_a); 
    printf("tce_a %%ld : %ld\n", tce_a);

    tce_ua = tce_b;
    printf("tce_ua %%u : %u\n", tce_ua);
    printf("tce_ua %%d : %d\n", tce_ua);
    return;
}

// <c primer plus第六版> P288 convert.c 程序很全面,看懂了感觉类型转换基本没啥问题了...
// 当 ch = 1107我的编译器gcc9.2.0会有溢出overflow报错... int --> char
// char 默认是 signed char 还是 unsigned char 取决于编译器...

//*类型转换: 升级通常没有什么问题,降级则可能会有溢出的问题
// 例如: 
//         char a;
//         a = 12.90;  --> 降级demotion,double类型转换char
//         a = 256.90; --> 降级demotion,double类型转换char时发生溢出overflow错误
// unsigned char [0,255],signed char [-128,127],无论整数或浮点数,值不超过[-128,255]这区间就不会发生溢出
//
//总结: 
//  1. 发生类型转换在表达式,作为函数参数(升级或降级)
//  2. 赋值表达式,表达式求值结果的类型与被赋值变量类型一致
//  3. 类型级别高到低,char和short int类型转换成int,作为函数参数float类型转换成double
//  弄清这三点就差不多了

// 以上都是自动类型转换,通常我们要避免自动类型转换,特别是类型降级
// (如果小心使用的话,自动类型转换还是很方便的,存在即合理嘛...)
// 
// 有时我们想转换成自己想要的类型,咋办呢~别急,下面我跟你讲嚯~
// (cast operator) 强制类型转换运算符.   cast:铸模,模子
void type_conversion_cast_operator(void)
{
    // 3.3 -> 3 真值的截断(发生在类型转换type conversion)
    // 与计算机存储的数据(binary)的截断不一样(发生在转换说明conversion specification)
    int tcco_a;
    float tcco_b;

    tcco_a = 1.6 + 1.7;
    printf("tcco_a %%d : %d\n", tcco_a);
    tcco_a = (int)1.6 + (int)1.7;
    printf("tcco_a %%d : %d\n", tcco_a);

    tcco_b = 5 + 5;
    printf("tcco_b %%.1f : %.1f\n", tcco_b);
    tcco_b = (float)5 + (float)5;
    printf("tcco_b %%.1f : %.1f\n", tcco_b);
    return;
}

// 总结C语言的一些运算符 <c primer plus> P291

