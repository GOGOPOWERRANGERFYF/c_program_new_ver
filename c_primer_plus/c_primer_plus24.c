// 第11章 字符串和字符串函数
// 第4章介绍过,字符串是以'/0'空字符结尾的字符数组
//                   (一个或多个字符的序列)

// 附加知识:
// 'a'字符
// L'a'宽字符
// "abc123"字符串(character string)用utf-8编码
// L"abc123"宽字符串(wide character string)用unicode编码

// 11.1.1 在程序中定义字符串
// 1.字符串字面量(字符串常量)
//  "string literal" 字符串字面量,也叫做字符串常量(string constant)
//  *计算机中储存的是字符串字面量/字符串常量的编码
//  c语言中,宽字符串采用unicode字符集的编码,字符串采用utf-8编码
//
//  网上资料  
//  [扩展,python]:python字符和字符串以unicode为基础
//                可用encode()函数编码
//  [扩展,socket]:字节流(互联网应用最广泛的是utf-8格式编码)
// 
// 变量 
// 常量/字面量
// 编码:
//  字符/字符串的编码:unicode utf-8 utf-16 utf-32 gbk
//  整数: 二补码 (IEEE规定的编码标准)
//  浮点数: 就浮点数的编码啊... (IEEE规定的编码标准)

#include <stdio.h>
#include <stdint.h>
#include <wchar.h>
void big_little_endian(void);
void character_string(void);
void width_character_string(void);

void main(void){
    // stdint.h头文件
    // 8bit unsigned integer type
    // uint8_t uint16_t uint32_t uint64_t
    // uint8_t只是为unsigned char定义的别名...
    // _t typedef定义的类型别名
    uint8_t ui8;
    uint16_t ui16;
    uint32_t ui32;
    uint64_t ui64;
    //printf("size of uint8_t type: %zd\n", sizeof(ui8));
    //printf("size of uint16_t type: %zd\n", sizeof(ui16));
    //printf("size of uint32_t type: %zd\n", sizeof(ui32));
    //printf("size of uint64_t type: %zd\n", sizeof(ui64));
    int8_t i8;
    int16_t i16;
    int32_t i32;
    int64_t i64;

    // wchart.h头文件
    wchar_t width_character;
    //printf("sizeof(width_character): %zd\n", sizeof(width_character));

    big_little_endian();
    //character_string();
    //width_character_string();
    return;
}

//联合是一种数据类型,可以在同一位置不同时刻储存不同类型的的数据
//储存一个int类型数据
//然后把数据当char类型读取
//关键点一:联合的成员使用同一位置
//以我目前极低的知识水平:程序除了栈区的数据存储数据应该都是从低地址向高地址...
void big_little_endian(void){
    //*理解union联合的核心思想:同一内存位置在不同时刻储存不同类型数据
    //要验证大端序和小端序需要用到union联合的知识
    //要回第14章填union的坑了...偷懒是不行滴~~~555
    //与struct不同,给union成员分配的空间是重叠的
    //union类型变量的存储长度以成员中存储长度最长的为准
    typedef union endian {
        //结构成员变量
        //字符数组类型(聚合数据类型)
        char c[2];
        //短整型(标量数据类型)
        short int si;
    } endian;
    endian var_test_endian;
    //var_test_endian.i = 1;
    // 0b前缀 二进制常量
    //                     高序字节 低序字节
    var_test_endian.si = 0b0000001000000001;
    // 内存存储空间: 低地址 --> 高地址
    printf("var_test_endian.si: %hx\n", var_test_endian.si);
    //这里打印的是短整型的字面量(十六进制)
    //所以无法直接判断这个变量在内存中的编码储存是大端序还是小端序
    //但我们通过联合来间接打印该变量的第一个字节,得出结论是小端序
    printf("var_test_endian.c[0]: %hx\n", var_test_endian.c[0]);
    printf("var_test_endian.c[1]: %hx\n", var_test_endian.c[1]);
    printf("\n");

    char * char_pointer;
    short int * short_int_pointer;
    //下面两句代码是错误的,指针类型不匹配
    //char_pointer = &var_test_endian;
    //short_int_pointer = &var_test_endian;
    char_pointer = &var_test_endian.c[0];
    short_int_pointer = &var_test_endian.si;
    printf("char_pointer: %p==> %hx\n", char_pointer, *char_pointer);
    printf("char_pointer + 1: %p\n", char_pointer + 1);
    printf("short_int_pointer: %p==> %hx\n",
     short_int_pointer, *short_int_pointer);
    //运行程序后可以看出,00000000实际上是储存在低地址的
    //所以验证了x86 CPU是小端序的(低字节存放在低地址)
    return;
}

// 网上查询的资料:
//  unicode仅仅是一个字符集,它仅仅规定了符号的二进制代码,但是
//  unicode并没有规定符号的二进制代码怎么存储
//  因此出现问题:unicode出现了多种存储方式
//  (unicode很长时间内无法推广,直到互联网的出现)
//  互联网的普及,强烈要求一种统一编码
//  utf-8是互联网上使用最广的一种unicode的实现方式
//  (utf-16 utf-32互联网基本不用)
void character_string(void){
    char char_array[] = "大肉云吞";
    //int char_array[] = "大肉云吞";
    int n, m;
    for (n = 0; n < sizeof(char_array); n++){
        //字符数组第[n]个元素的值为'\0'空字符(字符串的结束符)
        if (char_array[n] == '\0') break;
        //if ((int)char_array[n] == 0) break;
    }
    printf("大肉云吞utf-8: ");
    for (m = 0; m < n; m++){
        printf("%hx ", char_array[m]);
    }
    printf("\n");
    return;
}

//地址总线
//数据总线
//控制总线
//
//大小端序为什么由cpu决定的原因:
//个人总结网上的一篇教程(个人为了更容易理解而建的一个模型,32位总线)
//
//          |       |       |       |       |   0x000100
//          |       |       |       |       |   0x000011
//          |       |       |       |       |   0x000010
//          |       |       |       |       |   0x000001
//          |       |       |       |       |   0x000000
//             00      10       10      11
// 00 01 10 11 为两条没有连接内存地址线的地址总线低地址线的信号
// 0x000000 00
// 0x000000 01
// 0x000000 10
// 0x000000 11
// 补充:既然是从硬件来进行研究,这里的地址指的是硬件地址
// 上面四个地址读取的是相同的四个字节(32bit)数据,
// 所以并不存在00 01 10 11到底对应哪个字节的问题...
// 所以这四个字节高序字节和低序字节由cpu决定...
// 其实到这里我又有疑问了(啊!我是杠精...我的头发),cpu里又是怎样处理的呢...
// 还要去找谷哥继续寻找答案啊...
// 不过到这里我有点能理解内存对齐问题了,内存不对齐的话,一个数据就要分两次读取,速度就慢了
// (仅为个人猜测)所以硬盘分区时的4k对齐也是这么个原理吧...
// 个人关于cpu处理大端序小端序的问题推理(不保证对啊!):取决于cpu从哪个字节开始读数据...

//alignment对齐
//学习一下大端序小端序(字节序)的知识点:
//注:不管是大端序还是小端序,计算机在内存中存放数据的顺序都是从低地址到高地址(栈是例外?)
//   大端序和小端序指的是字节在内存中存储时的排列规则,不是在寄存器运算时的排列顺序(与编码一致)
//1. big endian
//2. little endian
//  高序字节    低序字节
// 0000 0001  0000 0010
//          内存低地址 -----> 高地址
// 大端序    0000 0001  0000 0010
// 小端序    0000 0010  0000 0001
//
// 地址由低向高
// 大端序: 高字节 低地址-->高地址
// 小端序: 低字节 低地址-->高地址
// X86 CPU采用小端序
// 采用小端序,int类型转换成char类型,变量的指针不变
void width_character_string(void){
    // 在C语言里:
    // ''字符
    // L''宽字符
    // ""字符串(character string)用utf-8编码
    // L""宽字符串(wide character string)用unicode编码
    //注意: wchar_t为int的别名,unicode编码的长度为4个字节
    //      但它们之间并不是类型等价关系
    //      unicode只是最常见的宽字符编码方式(严格来说unicode是一个字符集)
    //      字符集和字符编码不是一个概念...尼玛...到底要怎样...
    //声明不完整类型数组
    //宽字符串 L"wide character string"
    wchar_t widechar[] = L"大肉云吞";
    //int widechar[] = L"大肉云吞";

    printf("大肉云吞unicode: ");
    // typedef unsigned char uint8_t
    uint8_t n;
    // wcslen() wide character length function
    for (n = 0; n <= wcslen(widechar); n++){
        if (widechar[n] != 0) 
            printf("%p==>", &widechar[n]);
            printf("U+%x; ", widechar[n]);
    }
    printf("\n");
    return;
}

/* 字符集:为每一个字符分配一个码位(通俗来讲就像id,身份证号...) */
// ASCII american standard code for information interchange
//         美国     标准    码          信息        交换
// 美国标准信息交换码
//
// unicode 统一码 
//
// 从unicode到utf-8通过算法和规则来转换
// 编码规则:
//---------------------------------------------------------------------------------
//  |  Unicode符号范围       |  UTF-8编码方式  
//n |  (十六进制)            | (二进制)  
//--+-----------------------+------------------------------------------------------
//1 | 0000 0000 - 0000 007F |                                              0xxxxxxx  
//2 | 0000 0080 - 0000 07FF |                                     110xxxxx 10xxxxxx  
//3 | 0000 0800 - 0000 FFFF |                            1110xxxx 10xxxxxx 10xxxxxx  
//4 | 0001 0000 - 0010 FFFF |                   11110xxx 10xxxxxx 10xxxxxx 10xxxxxx  
//5 | 0020 0000 - 03FF FFFF |          111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx  
//6 | 0400 0000 - 7FFF FFFF | 1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
//---------------------------------------------------------------------------------
// 编码时多出来的x位补0 
// unicode U+7F U+7FF
// c大佬对不起...在你的地盘我要插入一些python的代码...
// str = '符'
// str.encode('utf-8') 字符串编码(utf-8) 
// bytes = b'\xe7\xac\xa6'
// bytes.decode('utf-8') 字节串解码(utf-8)
//
// 零宽度非换行空格 zero width no-break space
// unicode规范中,文件前加一个表示编码顺序的字符
// big endian(FEFF) 大端序
// little endian(FFFE) 小端序
// FEFF FFFE 每个字符占用两个字节
// 
//
/* 编码规则:将码位转换为字节序列的规则(编码/解码) */
// utf-8 (还有utf-16 utf-32)
// 8bit unicode transformation format 
