/*
    第16章 C预处理器和C库
    ...

    16.1 翻译程序的第一步
        ...
    
    16.2 明示常量: #define
        ...

    16.3 在#define中使用参数
                   (宏参数)
                      |
        #define POWER(n) (n) * (n)
                        |  替换体  |
        为什么(n) * (n)参数n要使用圆括号括起来,因为如果没有圆括号
        传入的实参n = 2 + 3时,编译器预编译时进行文本替换,
        替换结果为2 + 3 * 2 + 3,运算结果则与预想的完全不一样。。。

        ...
    
    16.5 文件包含: #include
        #include <stdio.h> 文件名在尖括号中 查找系统目录
        #include "fyf.h"   文件名在双引号中 查找当前工作目录
        #include "/home/fyf/fyf.h"        查找绝对路径目录
    
    16.6 其它指令
        ...

    16.6.3 条件编译
        conditinal compilation
        使用指令告诉编译器根据编译时的条件执行或忽略代码块。
        1. #ifdef #else #enif 指令
        ...

    16.6.4 预定义宏
        C标准规定了一些预定义宏,表16.1
        宏                      含义
        __DATE__            预处理的日期("Mmm dd YYYY"形式的字符串字面量,如Nov 23 2014)
        __FILE__            表示当前源代码文件名的字符串字面量
        __LINE__            表示当前源代码文件中行号的整型常量
        __STDC__            设置为1时,表明实现遵循C标准
        __STDC_HOSTED__     本机环境设置为1; 否则设置为0
        __STDC_VERSION__    支持C99标准,设置199901L;支持C11标准,设置为201112L
        __TIME__            翻译代码的时间,格式为"hh:mm:ss"

        C99标准提供了一个名为__func__的预定义标识符,它展开为一个代表函数名的字符串(该函数
        包含该标识符).那么,__func__必须具有函数作用域,而从本质上看宏具有文件作用域,因此,
        __func__是C语言的预定义标识符,而不是预定义宏.
        (个人理解:就是__func__不会在预编译(文本)阶段被替换掉,而是会被放在语义分析阶段生成的局部(例如函数)符号表里,
        所以__func__它是个预定义的标识符,这就是所谓的具有函数作用域,知道点编译原理就是好啊,这放在以前肯定看得一脸
        懵逼...在补充一点,__func__的值为它所在的函数的函数名,
        再来点实际的, gcc -E x.c -o x.i gcc的预编译命令.)

        一些预定义宏和预定义标识符,注意,其中一些是C99新增的,所以不支持C99的编译器可能无法识别它们.
        如果使用GCC,必须设置-std=c99或-std=c11.

        ...


        ...

        16.12 断言库
        (提示:别管这么多,反正只要提到宏,不管长啥样,这玩意就是会在预编译(文本)阶段就被替换掉)
        assert.h头文件支持的断言库是一个用于辅助调试程序的小型库.它由assert()宏组成,接受
        一个整形表达式作为参数.如果表达式求值为假(非零),assert()宏就在标准错误流(stderr)
        中写入一条错误信息,并调用abort()函数中止程序(abort()函数的原型在stdlib.h头文件中).
        assert()宏是为了标识出程序中某些条件为真的关键位置,如果其中的一个具体条件为假,就用
        assert()语句终止程序.通常assert()的参数是一个条件表达式或逻辑表达式.如果assert()
        中止了程序,它首先会现实失败的测试、包含测试的文件名和行号。
        (
            assert.h assert()宏
            stdlib.h abort() 中止函数
        )

        16.12.1 assert的用法
        ...

*/