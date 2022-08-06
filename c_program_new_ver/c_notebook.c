// 学习笔记
// 20211003:
//  C逻辑运算符： && || ！与 或 非
//              &  |  ^  按位与 按位或 按位异或
//              ~ 按位取反
//  python逻辑运算符： and or not 与 或 非            
//
// 20200626:
//  浮点数运算复习
//      加法: 阶码算成与大的阶码一致,尾数相加
//      减法: 阶码算成与大的阶码一致,尾数大-尾数小 --> 尾数大+尾数小的二补数 --> 模除 --> 得到尾数运算结果再规格化
//      乘法: 阶码相乘*尾数相乘 重点:小数点的移位
//            小数点移位示例: 1.011 * 1.111 = 1.011 * 1000 * 1.111 * 1000  = 1011 * 1111
//                                            ____________   ____________    ____   ____
//                                                1000            1000       1000   1000
//                                                                           
//                             1111 / 10 = 111.1   (2)10 = (10)2
//                             (1000/10)2 = (8/2)10 --> (0100)2 (4)10
//  提示: 这只是数学理论的运算,cpu怎么实现目前知识水平有限还不了解...

// date： 20200722
// 运算符优先级operator precedence暂时小结(不全):
// ()圆括号 
// !逻辑运算符非,+/-正负符号,++/--自增自减运算符
// + - * / % 加减乘除 模除 
// == != > >= < <= 关系运算符 
// &&逻辑运算符与and 优先级高于 ||逻辑运算符或or
// =赋值运算符和+=等组合赋值运算符 
// ,逗号运算符comma

// \ 转移字符 escape character
// \b等 转移序列
// c语言代码语句太长时,加\后可继续另起一行的原因,个人查阅网上资料后的理解:
// \ 后加 enter键(ascii[decimal:10],为非显示字符), \的作用就是把这个字符转义
// 所以编译器就不会把这一行的代码结尾当作这一语句的结尾

//   位权(weight):  10^1 10^0    1/10 1/100 (这里的权重用十进制表示)
// 十进制(decimal):   1    1  .    1     1  
//                              10^-1 10^-2                               
//
//   位权(weight):   2^1  2^0    1/2   1/4  (这里的权重用十进制表示)
// 二进制(binary):     1   1   .   1    1
//                              2^-1  2^-2                               
// 形象化的解释:
//  1. 十进制 0.1 1根棍子掰成10等份,一份就是0.1 
//  2. 二进制 0.1 1根棍子掰成2等份,一份就是0.1
//  十进制的0.1五份 = 二进制0.1一份
//  十进制0.1权重1/10; 二进制0.1权重1/2 （这里的权重统一用十进制表示)
//  理解十进制和二进制转换的关键: 十进制和二进制的位权统一用十进制表示
// 1/2 + 1/4 + 1/8
// 1 - 1/2 + 1/2 - 1/4 + 1/4 - 1/8 = 1 - 1/8
//
// 不管任何进制,本质就是位置计数法:
// 数位,位值,位权
// 通俗理解,用符号记录有多少根牙签
//--------------------------------------------------------------------
// 第四层: 
//牙签总数 = 四个牙签数(十进制)之和,所以牙签总数之和为十进制数 = (3.75)10 decimal
//--------------------------------------------------------------------
// 第三层: 二进制的每个数位表示多少根牙签(十进制decimal),即4个十进制数表示牙签数
//         (2)10   (1)10    (1/2)10   (1/4)10     十进制          decimal
//--------------------------------------------------------------------
// 第二层: 二进制每一位的位权,即第一层的二进制的每一位的1份表示几根牙签,这里用
//        十进制表示(其他进制也可以,十进制是我们日常常用的,而且这里就是为了理解
//        二进制转换为十进制的本质)
//        (2^1)10  (2^0)10  (2^-1)10  (2^-2)10  位权/权重 十进制    decimal
//--------------------------------------------------------------------
// 夹层:
//  十六进制位值转换为十进制的问题(a-f位值转换成十进制位值不同);
//  二进制,八进制本质上也要转,但转成十进制位值也没区别
//--------------------------------------------------------------------
// 第一层: 用二进制表示总共有多少根牙签 
//            1        1.       1       1                二进制     binary
//--------------------------------------------------------------------

//计算机组成原理
// endianness 端序
// big endian 大端序: 数据高位存低地址
// little endian 小端序: 数据低位存低地址

// (x-y)=u
// 2(x-y)=2u
// x-y + x-y = 2u
// 2x - 2y = 2u

//1. (x-y)^2=u^2
//2. (x-y) * (x-y) = u * u
// (x-y) * (x-y)等于(x-y)个(x-y)相加
//3. (x-y)*x + (x-y)*y = u^2
// x个(x-y)相加 + y个(x-y)相加
//4. x*x - x*y + y*x - y*y = u^2
//5. x^2 - x*y + y*x - y^2 = u^2
//6. x^2 - y^2 = u^2

// 二进制乘法:
//  十进制乘法参考: 248 * 8 = 248 * 5 + 248 * 3
//  1010 * 1010 = 1010 * (1000 + 10)

// 二进制除法
// chrome收藏夹
// 左移,减法,余数
// 101100 / 101
// 辣条升级版理解(除法运算的本质理解的再一次升华):
// CPU整数除法原理形象化理解:就是拆包装分辣条的过程
//1. 桌子6上有1包辣条分成101份,没法分
//         101100
//       101
// 商 = 0
//2. 1包辣条拆开包装,放在桌子5上,现在桌子5上有10小包(桌子5上原来有0小包)
//   (这里是二进制,用十进制表示就是拆开有2小包,后面以此类推)
//        101100
//       101
// 商 = 0
//3. 大于等于101,执行减法(当然,计算机中为加二补数)
//        101100
//        101
// 商 = 1, 余数 = 0
//4.     余数0放回最高位
//          0100
//        101
// 商 = 0
//5.
//          100
//        101
// 商 = 0
//6.
//         100
//        101
// 商 = 0
//7.
//        100
//        101
// 商 = 0

// assembly 汇编
// disassembly 反汇编
// breakpoint 断点
// gcc -g 可执行程序包含调试信息
// (gdb) disas 函数名
// (gdb) b *0x...   设置断点breakpointer ???
// (gdb) list 查看源代码
// (gdb) list 源代码行数. 查看行数附近源代码
// (gdb) b 源代码行数 设置断点
// (gdb) r          run运行程序(从断点开始)
// (gdb) info registers
// (gdb) next 下一条源代码
// (gdb) ni 下一条汇编指令
// (gdb) p %rsp     打印寄存器存储的指针?
// (gdb) x (exmine检查) 检查内存位置
// (gdb) p/x 打印十六进制
// (gdb) x/-2x $rbp
// step可以帮助初步揭开代码位置的谜团,例如：函数调用和函数本身可能在不同的文件中.
// next是在单步执行时,在函数内遇到子函数时不会进入子函数内单步执行,而是将子函数整个执行完再停止,也就是把子函数整个作为一步. 

// C语言的四种存储类别:
//  1. auto     自动
//  2. static   静态
//  3. register 寄存器
//  4. extern   外部
//
//  auto可省略,默认自动存储类别,
//  给变量分配了内存存储空间,没有初始化的情况下
//  读取变量的值时,内存区域的数据是什么就是什么
//
//  静态存储类别
//  与自动存储类别不同,即使变量没有初始化,
//  读取变量的值时默认为0
//
//  理解: auto未初始化,变量的值时随机变化的
//        static未初始化,变量的值默认为0

// rename命令,批量修改文件名

// readelf 
// elf文件
//
// 常量存储区,这是一块比较特殊的存储区,它们存储的是常量,不允许修改
//
// 栈区(stack) -- 由编译器自动分配释放
//  堆区(heap) -- 由程序员分配和释放,程序员不释放,程序运行结束系统也会释放

// 汇编有个概念叫立即数,立即数是固化在机器指令码中的一个值而不是一个指向
// 一个存储位置的地址(指针).立即数在c语言中对应的概念叫右值

// 加深理解:数组名并不是一个变量名,而是一个指针常量
//          数组名是无法做左值的

// 个人理解: *p 间接访问内存位置
//            a 直接访问内存位置
//            硬件都是通过地址访问内存位置
//            直接和间接访问由编译器实现

// 汇编的基础知识
//  栈(stack)
//  push/pop 入栈/出栈 压栈/弹栈 压入/弹出
//  程序中每一个未完成运行的函数对应一个栈帧(stack frame)
//  栈底对应高地址,栈顶对应低地址,栈由高地址向低地址生长
//
//  bp(base pointer):
//      基址指针寄存器:用于存放执行中的函数对应的栈帧的栈底地址
//      存放的指针永远指向系统最上面一个栈帧的栈底
//  sp(stack pointer):
//      用于存放执行中的函数对应的栈帧的栈顶地址
//      存放的指针永远指向系统最上面一个栈帧的栈顶
//
//  bp只存储某时刻的栈顶指针
//  (上一个栈帧,旧的栈顶指针,新的栈帧,栈顶变栈底)
//
//  ip(instruction pointer):指向当前执行指令的下一条指令
//  ax(accumulator):可用于存放函数返回值
//  x86架构,e前缀,寄存器大小32位
//  x86_64架构,r前缀,寄存器大小64位
//
//              |          |   high address
//              |          |
//              |          |   heap 堆(低向高)
//              |          |   例如malloc()函数
//              |__________|
//              |          |   栈:高向低
//              |          |
//              |          |    ...
//              |          |    
//              |          |    privious frame
//              |          |
//              |__________|   
//              | old rbp  |    | [caller]old 0(%rsp) = [callee]new 0(%rbp)
//     0(%rbp)  |__________|    | <-- stack bottom(bp)旧栈底压栈,旧栈顶变栈底
//              |          |    |
//              |          |    |
//              |          |    |
//              |          |  current frame
//              |          |    |
//              |          |    |
//              |          |    |
//              |          |    |
//              |          |    |
//     0(%rsp)  |__________|    | <-- stack top(sp)指针永远指向栈顶
//              |          |
//              |          |
//              |          |   stack 栈(高向低)
//              |          |   随代码块运行分配空间,代码快结束回收空间
//              |          |   (比如说函数?)
//              |          |
//              |          |
//              |__________|   
//              |          |
//              |   rodata |   rodatasegment 暂时忽略
//              |          |   只读数据
//              |__________|   
//              |          |
//              |    bss   |   bsssegment  暂时忽略         未链接前.comment
//              |          |   未初始化的全局变量和静态变量
//              |__________|
//              |          |
//              |   global |   datasegment 数据段
//              |   static |   global/static 初始化的全局变量和静态变量
//              |          |   随程序/进程持续性
//              |__________|
//              |          |
//              |    code  |   (code/text)segment 代码段/文本段
//              |          |   存放指令,空间在代码运行前已确定
//              |__________|   可能包含常数,字符串常量等
//              |          |    
//              |          |   low address
//
//  程序在内存简化不精准的模型(为了便于记忆)：
//  栈 stack                动态内存分配
//  堆 heap                    -
//  bss数据段 未初始化的变量   静态内存分配
//  数据段 初始化的变量           -
//  代码段 指令，常量            -
//
//  call stack 调用栈 简称栈(the stack)
//
//  形式地址A  
//  有效地址EA
//  有效地址由形式地址根据寻址方式来确定
//  |操作码|寻址特征|形式地址|
//  立即寻址:操作码中直接给出立即数
//  直接寻址:操作码中的形式地址=有效地址
//  间接寻址:操作码中的形式地址=有效地址的地址
//
// 《计算机组成第5版》 第2章 2.8堆栈和队列
//  
//
//
//
//
//
//
//  递归的个人理解心得(从数据结构的角度):
//  函数每被调用一次,入栈,每一个栈帧保存函数的私有局部变量
//

//  20210817笔记
//  标准C不支持闭包，C不允许在函数体内定义函数。以后会不会支持不知道，未来的时谁知道...

// 20211114笔记
// void * p;
// 无(void)类型指针变量p,任何类型的指针都可以赋值给p,
// 但p的值(如果有的情况下)不能赋值给其它类型指针变量。
//  
// 函数没有返回值,应声明void类型
// 函数无形参,应声明其参数为void

// 网络资料:
//  c语言sizeof的实现问题:
//     编译器里的符号表记录着各种数据类型的信息,
//     编译时在文本阶段直接替换成相应数据长度;
//     vla和struct等编译器通过alloc库申请内存???所以编译时编译器是知道长度的???
//      仅为备忘录,目前的总结还不够完善和权威,待以后再继续补充...
//
//  在计算机科学里,被称为相关数组、map、符号表或者字典,是由一组<key,value>对组成的抽象数据结构。
//  并且同一个key只会出现一次。