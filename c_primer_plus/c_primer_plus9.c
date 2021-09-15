#include <stdio.h>
//定义符号常量,预编译时后面的字符串替换前面的符号常量(文本)
#define OPERATORS "= + - * /"
#define SECOND_PER_MINUTE 60
void while_block(void);
void addition_substraction_operator(void);
void sign_operator(void);
void sixty_four_game(void);
void multiplication_division_operator(void);
void operator_precedence(void);
void sizeof_operator_and_size_type(void);
void second_to_minute(void);

int main(void)
{
    // operator:运算符; expression:表达式; statement:语句;
    // operand:运算数,操作数;
    // = 赋值运算符(assignment operator)
    //格式字符串中的转换说明%s,后面的待输出项类型和熟练要与转换说明相匹配
    printf("These is operators: %s\n", OPERATORS);
    while_block();
    addition_substraction_operator();
    sign_operator();
    sixty_four_game();
    multiplication_division_operator();
    operator_precedence();
    sizeof_operator_and_size_type();
    second_to_minute();
    return 0;
}

void while_block(void)
{
    //这里的 =运算符 表示 初始化而不是 赋值
    const int ONE = 1;
    
    //把整数值0赋给变量start,赋值表达式
    // 可修改的左值 = 表达式的值(包括常量,变量,可求值的表达式) 
    // 表达式有函数表达式
    int start = 0;
    // C的当前标准
    //(早期C标准的lvalue: left value
    //,rvalue: right value的定义已经不能满足当前的状况)
    // 左:
    //  *modifiable lvalue(可修改的左值)
    //  object locator value(对象定位值)
    // 右:
    //  *value of an expression(表达式的值)
    //  包括常量,变量,可求值的表达式
    //《c primer plus第六版》中文版的定义:
    //赋值语句的目的是把值储存到内存位置,储存值的内存存储区域称为数据对象(data object)
    //我自己根据《c primer plus第六版》英文版的翻译
    //考虑一个赋值语句.它的目的是储存一个值在一个内存位置.
    //数据对象是一个 用于存储整个值的数据存储区域的 通用术语

    while (start<10)/* starting the while loop  */
    //花括号之间的内容是要被重复的内容,用计算机术语说,就是程序循环这些语句
    /* start of block,花括号以及花括号括起来的部分被称为block */
    {                           
    // 目前个人的理解,下面整句为赋值语句,
    // start + 1为表达式的值(可求值的表达式),它是程序计算的一个临时值,之后会被丢弃,应该是赋值给左值后丢弃吧,个人推测... 
    // 常量是由系统在main函数运行前把常量赋值给常量的...(网上的说法,也不知道对错,待以后验证吧...)
    // 只有变量是可以引用内存地址的(个人理解,待验证,目前知识水平有限...)
        start = start + 1;      
    // operand(the item项 to the left of =) = operator operate on
    //    操作数(运算数)[赋值运算符左侧的项]  = 操作数(运算数) 操作符(运算符)操作(运算) 操作数(运算数)
    //    modifiable lvalue(可修改的左值)   =  操作数(运算数) 操作符(运算符)操作(运算) 操作数(运算数)
        printf("%d\n", start);
    }                           /* end of block */
    printf("The End!\n");
    return;
}

//addition operator和subtraction operator称为bianry operator(二次元...哦,不,二元运算符XD)
//即这些运算符需要两个运算数(operand)才能完成运算
void addition_substraction_operator(void)
{
    int ao_i_a, ao_i_b, ao_i_c;
    //assignment statment,赋值语句;assigement operator,赋值运算符;
    //可修改的左值(modifiable lvalue) = 表达式的值(an value of expression)(变量,常量,可求值的表达式)
    ao_i_a = 2;
    ao_i_b = 1;
    // 关键知识点:
    // * ao_i_a + ao_i_b表达式,程序计算的一个临时值,计算完成后会被丢弃,它并不能表示特定的内存位置,
    // * 个人推理:计算出的临时值,应该直接从寄存器直接赋给变量(可修改的左值的内存存储区域:数据对象)了,很合理吧...
    // * 因此不能赋值给它
    ao_i_c = ao_i_a + ao_i_b;
    printf("ao_i_a + ao_i_b = %d\n", ao_i_c);
    ao_i_c = ao_i_a - ao_i_b;
    printf("ao_i_a - ao_i_b = %d\n", ao_i_c);
    return;
}

// sign operator(符号运算符): + 和 -
// unary operator(一元运算符),完成运算只需要一个运算数(operand)
void sign_operator(void)
{
    int so_i_a, so_i_b;
    so_i_a = 5;
    so_i_b = -so_i_a;
    printf("so_i_b = -so_i_a = %d\n", so_i_b);
    return;
}

// count初始化等于1
// while循环,循环一次,count+1
// 循环1:  count = 2
// 循环2:  count = 3
//  ... ...
// 循环63: count = 64
// 循环条件count<64,语句块循环了63次,count=64,循环停止
void sixty_four_game(void)
{
    int count = 1;
    double number = 1.0, total = 1.0;
    printf("count                ");
    printf("number                     ");
    printf("total\n");
    printf("%3d. %22.1f %25.1f\n", count, number, total);
    while (count<64)
    {
        count = count + 1;
        // * multiplication operator乘法运算符
        number = 2.0 * number;
        total = total + number;
        printf("%3d. %22.1f %25.1f\n", count, number, total);
    }
    printf("The Max of number: %22.1f\n", number);
    printf("The Max of total:  %23.1f\n", total);
    printf("The End!\n");
    return;
}

//*打通数学的任督二脉...
//数学知识温习,前面的c文件也有,但有点难找,懒得翻回去找了...
//数学源于生活-->形象-->抽象
//形象:
// 9 / 3 = 3      1. 9根辣条,分成3份,每份3根
// 9 / 1 = 9      1. 9根辣条,分成1份,每份9根
// 9 / 1/9 = 81   1. 9跟辣条,分成1/9份,每份81根(9根就是1/9份,因此,一份就是81!!!)  
//                   (9除以1/9这个我想了挺久,我感觉这个形象最靠谱...)
//抽象: 
// 在代数体系中,除法,减法的定义
// 除于一个数等于乘于这个数的乘法逆元(倒数)
// 减去一个数等于加上这个数的加法逆元(相反数)
//division operator除法运算符 /
void multiplication_division_operator(void)
{
    int var;
    //整数除法
    //在C语言中,整数除法的计算结果小数部分会被丢弃,称为截断(truncation)
    //C99规定 趋零截断
    printf("7/4 = (%%d): %d\n", 7/4);
    printf("7/4 = (hexadecimal): %x \n", 7/4);
    printf("var = 7/4 = (hexadecimal): %x \n", var = 7/4);
    //欠7根辣条,分成4份,每份欠1.75根
    printf("-7/4 = (integer): %d \n", -7/4);
    printf("-7/4 = (hexadecimal): %x \n", -7/4);
    printf("var = -7/4 = (hexadecimal): %x \n", var = -7/4);
    //  7 4bit two's complement: 0111
    // -7 4bit two's complement: 1001
    //  4 4bit two's complement: 0100
    // -4 4bit two's complement: 1100
    //  7/-4  --> 0111/1100 --> 0111/0100 -->
    //           1.11
    //       ____________
    // 0100_/ 0111
    //        0100               下面的注释:除了写明是十进制的,其余的都是二进制数
    //     --------------
    //          11 0         <-- 11 拆成 110份 每份 (1/2)10
    //          10 0
    //     --------------
    //           1 00
    //           1 00        <-- 10份(1/2)10 拆成10份 (1/4)10
    //     --------------
    //              0  
    //    1.11小数部分会被截断(truncation),小数部分丢弃
    //    --> 1 --> 0001 --> 有一个运算数为负数(二补数编码最高位为1) --> 1111
    printf("7/-4 = (%%d): %d\n", 7/-4);
    printf("-7/-4 = (%%d): %d\n", -7/-4);
    
    //浮点数除法
    //浮点数常量为双精度浮点类型double
    printf("sizeof(7.0)(%%zd): %zd\n", sizeof(7.0));
    printf("7.0 = (%%lx):%lx\n", 7.0);
    printf("4.0 = (%%lx):%lx\n", 4.0);
    printf("7.0/4.0 = (%%f) %f\n", 7.0/4.0);
    printf("7.0/4.0 = (%%lx) %lx\n", 7.0/4.0);
    // operand_1: 
    // 7.0 --> 111 * (2^0)10 --规格化--> 1.11 * (2^2)10
    // exponent:  bias_1023 --> 2 + 1023 = 1025 
    //             00000000010      阶码进行二补数运算(非二补数编码运算)
    //          +  01111111111
    //         -----------------
    //             10000000001
    // mantissa: 1.11 --隐含1.--> 1100 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
    // sign   exponent                        mantissa
    //  0   10000000001  1100000000000000000000000000000000000000000000000000     
    // hexadecimal: 401c000000000000
    //
    // operand_2:
    // 4.0 --> 100 * (2^0)10 --规格化--> 1.00 * (2^2)10
    // exponent:  bias_1023 --> 2 + 1023 = 1025 
    //             00000000010      阶码进行二补数运算(非二补数编码运算)
    //          +  01111111111
    //         -----------------
    //             10000000001
    // mantissa: 1.00 --隐含1.--> 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
    // sign   exponent                        mantissa
    //  0   10000000001  0000000000000000000000000000000000000000000000000000     
    // hexadecimal: 4010000000000000
    //
    // operand_1 / operand_2:
    //   1.11 * (2^2)10 / 1.00 * (2^2)10
    // = 111 / 100 = 1.11  -->  1.11 * (2^0)10
    // exponent:  bias_1023 --> 0 + 1023 = 1023 
    //             00000000000      阶码进行二补数运算(非二补数编码运算)
    //          +  01111111111
    //         -----------------
    //             01111111111
    // mantissa: 1.11 --隐含1.--> 1100 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
    // sign   exponent                        mantissa
    //  0   01111111111  1100000000000000000000000000000000000000000000000000     
    // hexadecimal: 3ffc000000000000
    //
    // * 整数和浮点数乘除法:
    // * 关于sign的问题,乘法或除法,有一个operand为负,则运算结果sign为1;
    // *               两个operand都为正或都为负,则运算结果sign为0;
    // * 乘除法: 直接乘除
    // * 加减法: exponent转换成与大的expoent一致,尾数进行加减运算
    //CPU ALU(算术逻辑单元)必须按这个数学运算规则来实现乘除运算
    //只能根据C标准的浮点数存储格式和算法算出结果,但运算过程怎么实现的目前还不知道
    //(数字电路还没学,只有一点浅薄的硬件知识,理解未必正确或精准)
    //
    //            ______
    //      1.1 _/ 11.01
    //   11.01/1.1 = 11.01*10/1.1*10 = 110.1/11
    //
    printf("-7.0/4.0 = %f\n", -7.0/4.0);
    printf("-7.0/4.0 = %lx\n", -7.0/4.0);
    printf("7.0/-4.0 = %f\n", 7.0/-4.0);
    printf("7.0/-4.0 = %lx\n", 7.0/-4.0);
    printf("-7.0/-4.0 = %f\n", -7.0/-4.0);
    printf("-7.0/-4.0 = %lx\n", -7.0/-4.0);
    //浮点数整数混合,一般情况下,还是要避免这种情况
    //计算机并不能真正浮点数和整数相除,浮动数和整数在内存中的存储方式完全不同
    //下面两句代码中,在进行除法运算前,编译器会把整数转换为浮点数
    printf("6.0/3 = %f\n", 6.0/3);
    printf("6/3.0 = %f\n", 6/3.0);
    return;
}

// *乘法与除法运算,同号为正,异号为负(不深究的话其实记住这个就足够了)
//如果要刨根问底,这就说来话长了...
//
//预备知识:
//  N自然数包括 0,正整数 (N*,N+非零自然数,正整数)
//  Z整数包括 负整数,0,正整数
//     N+正整数集合,在加法运算下是封闭的,即两个正整数相加还是正整数
//     负整数是有了0之后,从正整数集拓展出来的数(可以看作正整数集关于零的对称集)
//  实数包括 有理数和无理数
//     有理数:包括所有分数,整数, 总能写成整数,有限小数,无限循环小数
//     无理数:无限不循环小数,例如:圆周率,根号2
//
//从自然数集说起...
//自然数集N
//自然数集规定了加法和乘法以后,可以证明:
// 加法对称性: 
// 加法结合律: (1 + 2) + 3 = 1 + (2 + 3)
// 乘法对称性: 
// 乘法结合律: (1 * 2) * 3 = 1 * (2 * 3)
// 乘法对加法的左右分配律:  (2 + 5)*2 = 2*2 + 5*2
//   2  2  --> 两个2=4  --|
//                        |--> 两个2加两个5 = 14
//   5  5  --> 两个5=10 --|
//   |  |
//   7  7  --> 两个7相加 = 14
//
//非零自然数n的加法逆元是-n,称为"负整数"
//非零自然数称为"正整数"
//  a + (-b) 简记成 a-b
//减法其实就是加法运算和取逆运算的一个复合
//
//人们希望 加法具有 对称性 和 (乘法)对加法的左右分配律
// x = (-a)*b
//  x + a*b
//= (-a)*b + a*b
//= (-a + a)*b
//= 0*b
//= 0
//人们把(-a)*b定义为a*b的加法逆元,也就是-(a*b)
//异号为负,(-a)*b=a*(-b)=-(a*b)
// x = (-a)*(-b)
//  x + a*b
//= (-a)*(-b) + a*b
//= [(-a)*(-1) + a]*b     --> (-1)*b = -b 结果是b的加法逆元 --> (-1)*(-a) = -(-a) 结果是(-a)的加法逆元
//= [-(-a) + a]b
//= (a + a)b
//= ab + ab
//因此把(-a)*(-b)定义为a*b???这个是我自己推论的,不知道对不对,上面的是知乎大佬的原文...
//啊...不纠结这个了...先跳过这里,以后再深究...
//目前记住乘法和除法同号为正,异号为负就行了... 20200227

// operator precedence 运算符优先级
void operator_precedence(void)
{
    int result;
    //跟数学四则运算规则是一样的,那必须的,要不然有啥意义呢...
    // 优先级: 小括号() > +/-正负符号 > 乘法/除法 > 加法/减法 > =赋值运算符
    // 优先级相同,顺序从左到右 (=运算符除外)
    result = 5 + 2*8/4;
    printf("result(%%d): %d\n", result);
    printf("5 + 2*8/4 =(%%d): %d\n", 5 + 2*8/4);
    printf("5 + 2*8/-4 =(%%d): %d\n", 5 + 2*8/-4);
    printf("%d\n", -(3+2)*6+(4+3*(8+5)));
    //  -(3+2)*6+(4+3*(8+5))
    //= -5*6+(4+3*(8+5))
    //= -5*6+(4+3*13)
    //= -5*6+(4+39)
    //= -5*6+43
    //= -30+43
    //= 13
    return;
}

void sizeof_operator_and_size_type(void)
{
    // size_t类型
    // 文件test7.c中,stdio_include_stddef_size_type()函数的注释中有介绍
    // 目前我正在用的编译器,size_t类型是long unsigned int的底层类型
    // size_t类型让程序的移植性更好,不同编译器的size_t类型的
    // (上层类型不相同,为了更容易描述我自己定义的,并没有上层类型这个概念)
    size_t st;
    printf("sizeof(st): %zd\n", sizeof(st));
    // typedef关键字 可为现有类型创建别名,例如:
    // typedef int integer
    // integer n = 3;
    // 使用size_t类型时,头文件可用typedef关键字根据不同系统替换标准的类型
    return;
}

// % modulus operator求模运算符
// 求模运算符只用于整数
// 左侧整数除以右侧整数的余数
void second_to_minute(void)
{
    int second, min, sec;
    printf("input second(negative number->quit): ");
    // 空白字符包括转换说明前无空白字符的情况(%c除外)
    // 读取输入缓冲区时会自动跳过 非符号字符 和 数字字符
    scanf("%d", &second);
    // * 记住一个重点: 整数常量是有符号整数!!!(无符号整数常量要加后缀u或U)
    //   这样就能清楚知道,整数常量在内存中的储存方式
    //   条件表达式看变量的类型,根据以下规则判断大小即可,OK了~
    // 无符号整数0000最小,1111最大
    // 突然有点明白java为什么没有无符号整型了...
    // 有符号整数0111最大,0000,1000最小
    //    1. 符号位0>1
    //    2. 符号位0,111-->000 由大到小
    //    3. 符号位1,111-->000 由大到小
    //数值位由高位向低位比较,因为1000>0111,
    //因为 后面位值最小的情况 也比 后面位值最大的情况 大
    //所以高位数值大的数,它的值就大
    while (second >= 0)
    {
        // 结果小数截断(truncation)
        // 数学上的除法理解为拆分成60份
        // 这里的除法可以形象化为60一份,最大可以分几份,最小单元为1,不拆分
        min = second / SECOND_PER_MINUTE;
        // 结果为余数
        // 拆分60一份,余下不足60的数
        // / 运算,同号为正,异号为负.  
        // % 运算,第一个运算数为正,则结果为正
        //        第一个运算数为负,则结果为负
        // * C标准规定,可通过 a-(a/b)*b 来计算 a%b  (a,b为整数)
        // 这里的取模运算可以形象化为60一份,最大可以分几份,最小单元为1,不拆分
        // 剩余不足60的余数就是结果
        sec = second % SECOND_PER_MINUTE;
        printf("(minute:second) %d:%d\n", min, sec);
        printf("input second(negative number->quit): ");
        scanf("%d", &second);        
    }
    printf("The End\n");
    return;
}




