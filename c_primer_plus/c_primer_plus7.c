// ANSI(american national standards institute):美国国家标准学会
// 'x' 一个字符   | x |    |
// "x" 一个字符串 | x | \0 |
// \0 空字符:null character(非打印字符)
//scanf()函数会自动添加空字符
//scnaf() 只会读取fyfa fyfb中的fyfa
//--------------------------------------------------------------
//conversion specification(转换说明) 例如: %d %f
// 1) printf() --> conversion specification表 《c primer plus第六版》P195
//--------------------------------------------------------------
//字符串常量 编译器会添加空字符
#include <stdio.h>
#include <string.h>      /* 该头文件提供strlen()函数 */
//编译程序的时候,程序中的符号常量会被替换成所定义的值(常量),编译时替换(compile-time substitution)
//符号常量后面的内容被用来替换符号常量 《c primer plus第六版》p189
#define C 'A'
#define NAME "Fu YunFeng." /* 定义符号常量 */
#define PI 3.141593         /* 定义符号常量(symbolic constant) */
void code_new_line(void);
void circle_float_arithmetic(void);
void circle_double_arithmetic(void);
void circle_long_double_arithmetic(void);
void define_and_const(void);
void stdio_include_stddef_size_type(void);
void conversion_specification_modifiers_and_flags(void);
void printf_function_stack_a(void);
void printf_function_stack_b(void);
void print_long_string_methods(void);

void main(void)
{
    //c_var[40]是一个可容纳40个字符的数组
    //该字符数组占用内存中连续 1*40个字节byte
    //定义字符类型数组
    char c_var[40];
    //该短整型数组占用内存中连续 2*5个字节byte
    short int si_var[5];
    printf("character string 字符串,string constant Name: %s\n", NAME);
    // \b 光标向左移一位,一个字符占一位 
    printf("Input You Name:__________\b\b\b\b\b\b\b\b\b\b");
    scanf("%s", c_var);
    printf("My Name is:%s\n", c_var);
    //strlen()函数获取字符串的长度,获取空字符(null character)之前的字符串的长度
    // strlen()函数 和 sizeof运算符 返回值为无符号整数类型(unsigned integer)  注:网上说的...不知道对不对
    // 输出返回值用%zd或%u,C99和C11标准用%zd,较早的C用%u
    // sizeof运算符用法示例: 1)sizeof(object);  2)sizeof object;  3)sizeof(type);
    printf("string length, strlen(c_var): %u\n", strlen(c_var));
    printf("string length, strlen(NAME): %u\n", strlen(NAME));
    printf("sizeof(c_var): %u\n", sizeof(c_var));
    //计算机主存每字节都有一个唯一的物理地址(physical address),物理寻址physical addressing
    //&取数组变量的地址(虚拟地址virtual address\虚拟寻址virtual addressing)
    //CPU芯片上的内存管理单元(memory management unit: MMU)将虚拟地址转换成物理地址
    //《深入理解计算机系统第三版》 P560 
    printf("sizeof(&c_var): %u\n", sizeof(&c_var));
    //&c_var是数组第一个字节的虚拟地址(个人理解,待验证)
    printf("lx(&c_var)/64bit virtual address(hexadecimal): %lx\n", &c_var);
    printf("sizeof(si_var): %u\n", sizeof(si_var));
    printf("sizeof(&si_var): %u\n", sizeof(&si_var));

    code_new_line();
    circle_float_arithmetic();
    circle_double_arithmetic();
    circle_long_double_arithmetic();
    define_and_const();
    stdio_include_stddef_size_type();
    conversion_specification_modifiers_and_flags();
    printf_function_stack_a();
    printf_function_stack_b();
    print_long_string_methods();
    return;
}

void code_new_line(void)
{
    printf("233333333333333333333333333333333333333333, This is my name: %s\n", NAME);
    //处理很长的printf()语句的两种方法:
    // 1)
    printf("233333333333333333333333333333333333333333, This is my name: %s\n",
     NAME);
    // 2)
    printf("233333333333333333333333333333333333333333, ");
    printf("This is my name: %s\n", NAME);
    return;
}

//格式说明符(format specific) 
//注:long double类型有点特殊,需要考虑硬件,操作系统等因素,虽然编译器有定义这个类型,我暂时用不到就不折腾了...
// [1] scanf()
//     float: %f %e %a
//     double: %lf %le %la
//     long double: %Lf %Le %La
// [2] printf()
//     %f %e 默认保留小数点后六位
//     float: %f %e %a
//     double: %f %e %a
//     long double: %f %e %a  
// 浮点数不加后缀,默认double类型
void circle_float_arithmetic(void)
{
    float r, l, a;
    printf("sizeof(r): %zd, sizeof(PI): %zd\n",
     sizeof(r), sizeof(PI));
    printf("input r(floating-point number):______\b\b\b\b\b\b");
    scanf("%f", &r);
    l = 2.0 * PI * r;
    a = PI * r * r;
    printf("circle_l(f): %f, circle_a(f): %f\n", l, a);
    printf("circle_l(e): %e, circle_a(e): %e\n", l, a);
    printf("circle_l(a): %a, circle_a(a): %a\n", l, a);
    return;
}

void circle_double_arithmetic(void)
{
    double d_r, d_l, d_a;
    printf("sizeof(d_r): %zd,sizeof(PI): %zd\n",
     sizeof(d_r), sizeof(PI));
    printf("input d_r(floating-point number):______\b\b\b\b\b\b");
    scanf("%lf", &d_r);
    d_l = 2.0 * PI * d_r;
    d_a = PI * d_r * d_r;
    printf("circle_l(f): %f, circle_a(f): %f\n", d_l, d_a);
    printf("circle_l(e): %e, circle_a(e): %e\n", d_l, d_a);
    printf("circle_l(a): %a, circle_a(a): %a\n", d_l, d_a);
    return;
}

void circle_long_double_arithmetic(void)
{
    float f_a = 1.3F;
    double d_a = 1.3;
    printf("sizeof(f_a): %zd\n", sizeof(f_a));
    printf("%.60f\n", f_a);
    printf("%.60e\n", f_a);
    printf("%.60a\n", f_a);
    printf("sizeof(d_a): %zd\n", sizeof(d_a));
    printf("%.60f\n", d_a);
    printf("%.60e\n", d_a);
    printf("%.60a\n", d_a);
    return;
}

void define_and_const(void)
{
    //const关键字(key woird)限定一个变量为只读,赋值编译器会报错
    // short long signed unsigned const 限定符
    //用法比define更灵活
    // PI = 5.555; 符号常量不能更改其内容
    // csi_b = 88; const限定变量只读,不可更改
    const short int csi_a = 55, csi_b = 66;
    printf("csi_a(%%hd)%hd\n", csi_a);
    printf("csi_b(%%hd)%hd\n", csi_b);
    // 计算机中储存的是 3.14159的近似值
    // %%   printf()转换说明 打印一个百分号
    printf("PI(%%f): %f\n", PI);
    printf("PI(%%.10f): %.10e\n", PI);
    // double类型 尾数52位,因此只能计算最长值 %.13a,超过这个长度后面只是填充0而已
    printf("PI(%%.13a): %.13a\n", PI);
    printf("PI(%%.15a): %.15a\n", PI);
    return;
}
// printf("格式化字符串/转换说明", 待打印列表)
// 待打印列表项: 常量,变量,表达式的值
// 《c primer plus第六版》P200 表4.5 转换说明修饰符
// 需要注意的: l和整数转换说明使用,L和浮点数转换说明使用

void stdio_include_stddef_size_type(void)
{
    int i_a = 111;
    float f_a = 1.0, f_b = 2.0, f_var_a = 1.0, f_var_b;
    double d_var_a = 1.0;
    size_t size_type_a;
    // long unsigned int
    //       |
    //       V
    // __SIZE_TYPE__  
    //       |------------> 定义size_t类型(underlying type:底层类型) 
    //                      具体怎么定义的要看头文件源码,目前水平有限,暂时理解到这了...
    // 
    // stddef.h(在包含stdio.h时已包含其中,书本上说的,具体怎么实现我目前还不懂。。。)头文件中, 
    // C标准只规定了sizeof返回值类型为无符号整数类型
    // #define __SIZE_TYPE__ long unsigned int 
    // (可移植性更好 sizeof返回值类型,不同编译器,
    // unsigned int, unsigned long, unsigned long long都有可能)
    // z修饰符和整数转换说明一起使用,表示size_t类型的值
    // printf() conversion specification modifiers 输出函数转换说明修饰符
    printf("sizeof(int): %zd\n", sizeof(int));
    printf("sizeof(size_t): %zd --> long unsigned int\n", sizeof(size_t));
    printf("sizeof(sizeof(int)): %zd --> long unsigned int\n",
     sizeof(sizeof(int)));
    printf("sizeof(float): %zd\n", sizeof(float));
    printf("sizeof(double): %zd\n", sizeof(double));
    printf("sizeof(1.0): %zd\n", sizeof(1.0));
    printf("sizeof(f_a): %zd\n", sizeof(f_a));
    printf("constant 99.99 (x): %x\n", 99.99);
    printf("sizeof(f_b): %zd\n", sizeof(f_b));
    //printf() 的浮点数转换说明为什么只有 %f
    //历史遗留问题,为了兼容
    //因为在K&R C中,表达式或参数中的float类型会被自动转换成double类型
    //具体看《c primer plus第六版》P201
    // f_a*f_b表达式返回值打印结果可看出,一般而言,ANSI C不会自动把float转换成double
    //《c primer plus第六版》P201 第8行
    //从f_var_a和d_var_a两个变量的打印结果可印证,printf()的float仍自动转换成double
    //所以没有float类型的专用转换说明,float和double类型都是用%f
    printf("sizeof(f_a*f_b): %zd\n", sizeof(f_a*f_b));
    printf("sizeof(f_a*2.0): %zd\n", sizeof(f_a*2.0));
    printf("sizeof(f_a*d_var_a): %zd\n", sizeof(f_a*d_var_a));
    printf("f_var_a=1.0 (a): %a\n", f_var_a);
    printf("d_var_a=1.0 (a): %a\n", d_var_a);
    printf("f_var_a=1.0 (x): %x\n", f_var_a);
    printf("f_var_a=1.0 (lx): %lx\n", f_var_a);
    printf("d_var_a=1.0 (x): %x\n", d_var_a);
    printf("d_var_a=1.0 (lx): %lx\n", d_var_a);
    //《c primer plus第六版》P201 表4.5 printf()中的标记(flags)
    // +标记  值为正,则前面显示+号;值为负,则前面显示-号
    printf("f_a(%%+.2f): %+.2f\n", f_a);
    // (一个空格)标记  值为正,则前面显示一个空格;值为负,则前面显示-号
    printf("f_a(%% .2f): % .2f\n", f_a);
    // %10d 整数字段宽度10(个人感觉10个字符宽度更容易理解)
    printf("i_a(%%10d): *%10d*\n", i_a);
    // %010d 整数字段宽度为10,数值位数不足的前面填充0
    printf("i_a(%%010d): *%010d*\n", i_a);
    // %-10d 整数字段宽度10, -标记 左对齐
    printf("i_a(%%-10d): *%-10d*\n", i_a);
    // 浮点数类型的修饰符和标记也是相同原理
    // %10.2f 表示字段宽度10,保留小数点后两位,其它的就全部展示了
    // 要了解看《c primer plus第六版》P203就好了
    printf("11.3(%%e): *%e*\n", 11.3);
    printf("11.3(%%.2e): *%.2e*\n", 11.3);
    // rounding 舍入
    printf("11.3(%%.1e): *%.1e*\n", 11.3);
    printf("11.4(%%.1e): *%.1e*\n", 11.4);
    printf("11.5(%%.1e): *%.1e*\n", 11.5);
    printf("11.3(%%10.2e): *%10.2e*\n", 11.3);
    printf("1.3(%%10.2e): *%10.2e*\n", 1.3);
    // 下面的两种情况会对结果进行舍入rounding
    printf("1.399(%%10.2e): *%10.2e*\n", 1.399);
    printf("1.399(%%10.1e): *%10.1e*\n", 1.399);
    return;
}

void conversion_specification_modifiers_and_flags(void)
{
    const double cd_a = 123456.789;
    float f_a = 3.0;
    double d_a = 3.4e39;
    printf("cd_a(%%.3f): %.3f\n", cd_a);
    // %E e输出变大写字母E
    printf("cd_a(%%E): %E\n", cd_a);
    // flags # 显示前缀
    printf("cd_a(%%#lx): %#lx\n", cd_a);
    // %X 十六进制中的字母输出大写字母格式
    printf("cd_a(%%#lX): %#lX\n", cd_a);
    // .3d 整数数值位数不够的前面填充0 
    // 5d  整数数值位数不够的前面填充空格
    // 相同点,整数数值位数足够或超过的,以原值为准输出
    // 10d 字段宽度10
    printf("6(*%%10.3d*): *%10.3d*\n", 6);
    // character string 字符串 flags 标记
    printf("NAME([%%s]): [%s]\n", NAME);
    // %.5s 只输出字符串前面5个字符
    printf("NAME([%%.5s]): [%.5s]\n", NAME);
    // %30s 输出字符串宽度30,字符数不足的前面填充空格
    printf("NAME([%%30s]): [%30s]\n", NAME);
    printf("f_a(%%ld): %ld\n", f_a);
    printf("d_a(%%ld): %ld\n", d_a);
    return;
}

//标记: printf() --> - 左对齐; + 正数加正号,负数加负号;  空格; 0 填充0; # 前缀
//  注: %.5d(输出整数位数最少为5,不足补0)
//      %.5f(保留小数点后5位)
//      %.5s(输出字符串前5个字符)
//      %5d %5f %5s (输出字段宽度为5)
//
// 转换说明的意义:
//    转换说明实际上是翻译说明,
//    把计算机中储存的二进制数"转换"(翻译)成文本(字符/字符串)打印出来
//    并不改变计算机中储存的数据(原始值)
//
//温故知新: binary division 二进制除法
//           _____        
//     1000_/ 1101 
// 1) 最高位1不能分成1000份
// 2) 先把1拆成10份,10就是10份个1,加上后一位的1份,就是10+1=11
// 3) 后面同理,懒得写了...
// 这里我不转换成十进制来读,十进制来理解原理就好
// 

void printf_function_stack_a(void)
{
    unsigned short int usi_a = 16352U, usi_b = 49120U;
    // 16352U                     0011 1111 1110 0000
    // 16352  0000 0000 0000 0000 0011 1111 1110 0000
    // 49120U                     1011 1111 1110 0000
    // 49120  0000 0000 0000 0000 1011 1111 1110 0000
    unsigned int ui_a = 3220176896, ui_b = 3220176896U;
    unsigned long int uli_a;
    double d_a = 1.0;
    printf("ui_a(%%u): %u\n", ui_a);
    //有符号整数常量4byte, 32bit编码储存不了有符号数3220176896,编译器转换成64bit储存
    printf("int constant 3220176896(%%x): %x, sizeof(3220176896): %zd\n",
     3220176896, sizeof(3220176896));
    printf("int constant 3220176896U(%%x): %x, sizeof(3220176896U): %zd\n",
     3220176896U, sizeof(3220176896U));
    //为正数时前面的0输出是被省略了,输出负数时就可以看出前面是有填充1的
    printf("int constant 3220176896(%%lx): %lx\n", 3220176896);
    printf("int constant -3220176896(%%lx): %lx\n", -3220176896);
    printf("int constant -3220176896(%%x): %x\n", -3220176896);
    printf("3220176896U(%%lx): %lx\n", 3220176896U);
    printf("usi_a(%%hu): %hu\n", usi_a);
    printf("usi_a(%%a): %a\n", usi_a);
    printf("usi_a(%%e): %e\n", usi_a);
    printf("usi_a(%%x): %x\n", usi_a);
    printf("usi_a(%%lx): %lx\n", usi_a);
    printf("d_a(%%lx): %lx\n", d_a);
    printf("1) 16.125(%%f):  %f\n", 16.125);
    printf("2) 16.125(%%lx): %lx\n", 16.125);
    printf("3) 16.125(%%a):  %a\n", 16.125);
    printf("4) 16.125(%%e):  %e\n", 16.125);
    /*
    exponent
   true value  binary    two's complement      excess_3
        3     [ 011]--|     |-- 011 --|      |--  110 --|            |-- 1 011
        2     [ 010]  |     |   010   |      |    101   |            |   1 010
        1     [ 001]  |     |   001   |      |    100   |            |   1 001
        0     [ 000]  | map |   000   | +011 |    011   | -011(+101) |   1 000
       -1     [-001]  |     |   111   |      |  1 010   |            |     111
       -2     [-010]  |     |   110   |      |  1 001   |            |     110
       -3     [-011]  |     |   101   |      |  1 000   |            |     101
       -4     [-100]--|     |-- 100 --|      |--  111 --|            |-- 1 100
    binary --> two's complement -- +011 --> excess_3 
    binary 000(包括000)以上+011为正数加正数
           这运算结果区间都为正数(这区间的结果并不是结果的二补数编码,因为编码位数不够,最高位符号位为1,会有溢出)
    binary -001(包括-001)以下+011为负数加正数,这里负数转换为二补数进行加法运算
           运算结果为正,则modulo模除1000得到正确结果;运算结果为负,则得到结果的绝对值的二补数
    excess_3 000(包括000)以上非负数,111唯一负数的二补数,
             -011转换成+101二补数运算
             结果000(包括000)以上,结果为正,模除1000得到正确结果
             [101,111]负数结果区间,得到正确结果绝对值的二补数
             1 100由于两个负数相减,转换成二补数运算,相当于加了两次1000,所以模除1000后得到正确结果绝对值的二补数
    阶码:二补数运算。 有符号整数:二补数编码运算
    */
    return;
}

void printf_function_stack_b(void)
{
    //参数传递 stack栈 《c primer plus第六版》P212
    //程序把传入的值放入被称为栈的内存区域
    //计算机根据变量类型把这些值放入栈中
    //参数传递机制因编译器实现而异
    //书本中可能编译器的版本问题
    //目前我用的编译器并未出现里面所介绍的输出错误
    float n1 = 3.0;
    double n2 = 3.0;
    short int si_return_value;
    int i_return_value;
    long int n3 = 2000000000;
    long int n4 = 1234567890;
    printf("n1(%%ld): %ld,n2(%%ld): %ld,n3(%%ld): %ld,n4(%%ld): %ld\n",
     n1, n2, n3, n4);
    printf("n1(%%d): %d,n2(%%d): %d,n3(%%d): %d,n4(%%d): %d\n",
     n1, n2, n3, n4);
    // 大部分C函数都有一个返回值
    // 可赋值给变量,可作为参数传递,可参与运算
    // *总之,就是可以把返回值当作其它数值一样使用
    //下面两句代码,输出且把返回值赋值给变量
    si_return_value = printf("12345 67890: %f\n", n2);
    i_return_value = printf("12345 67890: %f\n", n2);
    // 标准C库函数printf()返回值为打印字符的个数
    // 由运行输出结果可得到printf()函数返回值,
    // 有结果可知计算字符个数结果包括:空格,转义序列(转义字符)
    printf("return value of printf function (%%hd): %hd\n", si_return_value);
    printf("return value of printf function (%%hd): %d\n", i_return_value);
    printf("sizeof(si_return_value): %zd\n", sizeof(si_return_value));
    printf("sizeof(si_return_value): %zd\n", sizeof(i_return_value));
    // printf()返回值是一个整数类型,size: 4byte
    // 是int还是unsigned int还要验证...
    printf("sizeof(printf function return value): %zd\n",
     sizeof(printf("12345 67890,%f\n", n2)));
    return;
}

void print_long_string_methods(void)
{
    // 打印较长字符串的三种方法:
    // [1]
    printf("abcd");
    printf("efg\n");
    
    // [2]
    // ANSI c引入的字符串连接
    // 两个双引号括起来的字符串之间用空格隔开
    // C编译器会把这两个字符串看作是一个字符串
    // 多个字符串也一样
    // 比较容易记的说法: C编译器把多个用空格隔开的字符串看作一个字符串
    printf("a"     "b"            "c\n"); /*本质*/
    printf("abcd"
    "efg\n");
    printf("123"
    "456"
    "789\n");

    // [3] 注:字符串的第二行代码必须从最左边开始,
    //        不然前面的空格会成为字符串一部分,输出的字符串就会包含空格
    /* 
        printf函数中的字符串常量不能含有enter回车键产生的换行符
        包含的话编译器会报错
        示例:
            printf("abcd
            efg\n"); 
    */
    // 反斜杠\ 加 enter(回车)的组合 -->  \换行符
    printf("a\
bcd\n");
    //通过输出结果可知字符串代码第二行前面的空格是两个非显示字符
    //*字符串在内存的存储并非我想的那么简单,目前水平有限,先跳过。。。--'
    printf("%zd\n", printf("a\
    bc\n"));
    printf("%lx\n", "a\
    bc\n");
    
    printf("%zd\n", printf("a\
    b\n"));
    printf("%lx\n", "a\
    b\n");
    return;
}

// 补充: 4.2 字符串简介(character string)
// 4.2.1 char类型数组和null字符
// C语言没有专门用于储存字符串的变量类型,字符串都被储存在char类型的数组中。
// *"character string"
// 在C中字符串常量就是字符数组首元素的指针(数组名就是数组首元素的指针)