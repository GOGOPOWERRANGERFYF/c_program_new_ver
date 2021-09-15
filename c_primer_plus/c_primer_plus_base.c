//git config --global credential.helper store (github免密码,要先账号密码登陆一次)
#include <limits.h> /* 提供整数类型大小相关的信息,里面定义了明示常量 具体《c primer plus》P190  */
#include <float.h>  /* 提供浮点数类型大小相关的信息,里面定义了明示常量 */
//ascii(american standard code for information interchange):美国信息交换标准代码
//包含0~9,大小写字母和常用符号,用一个字节的数据表示
//unicode(unique universal uniform character encode):唯一 通用 统一 字符编码
//utf-8(8-bit unicode transformation format):8比特位unicode转换格式
//ALU(arithmetic logic unit):算术逻辑单元
//PS(program counter):程序计数器
//USB(universal serial bus):通用串行总线
//shell是一个命令行解释器,如果输入命令行的第一个单词不是shell内置命令,那么shell会假设这个是
//可执行文件的名字,它将加载并运行这个文件
//sizeof是运算符(operator):唯一一个单词形式的运算符
//invert 颠倒 grep -v

/*
    |<-- compilation system编译系统
    |
    |--> cpp(pre-processor)预处理器
    |--> ccl(compiler)编译器
    |--> assembler(as)汇编器:将指令转变为机器码
    |--> linker(ld is short for link editor)链接器
*/

/*
    cpu(central processing unit):中央处理器
    main memory:主存(我们平常所说的内存条)
*/

//program:程序,编码指令
//程序是一个指令序列
//这一段代码以字节序列的方式存储在文件中,每个字符都对应一个ascii码,中文字符是unicode码
//只由ascii码构成的文件称为文本文件(也有unicode文本文件),所有其他文件都称为二进制文件
//所有数据都是一串比特表示,区分不同数据对象的唯一方法是读取数据对象上下文,
//在不同的上下文中,一个相同的字节序列可能表示一个整数,浮点数,字符串或机器指令.

//进程(process)是操作系统对一个正在运行的程序的抽象
//并发运行是指一个程序的指令和另一个程序的指令是交错执行的
//单核处理器一个时刻只能处理一个程序,多核处理器一个时刻同时能够执行多个程序
//处理器在进程间切换让单核处理器看上去能并发处理多个程序
//操作系统实现这种进程间交错执行的机制称为上下文切换

#include <stdio.h> /* standard input & output . head头文件 */
// * 重要知识点(编译系统的编译过程):
// * stdio.h是C编译器软件包的标准库的一个文件,它提供键盘输入和屏幕输出的支持
// * cpp(c pre-processor:预处理器)会读取stdio.h文件(C标准库的头文件)的内容并插入到程序文本中
// * 还有删除注释,字符常量的替换
// * 结果得到另外一个C程序,通常以.i作为文件扩展名
// * 源程序source program(文本text)hello.c --[cpp]-->修改了的源程序modified source program(文本)hello.i,
// * 旁注:(这里的文本编码格式是utf-8, 8bit unicode transformation format);
// *      utf-8可节省编码储存长度,用utf-8编码unicdoe长度可变;
// *      unicode码(4字节)是兼容ascii码(1字节)的.
// * hello.i --[ccl: c compiler]--> hello.s汇编程序assembly program(文本)
// * hello.s --[as: assembler]--> hello.o(relocatable object program可重定位目标程序(binary二进制文件))
// * hello.o --[ld: linker]--> hello可执行目标程序executable object program(二进制)
// * 把hello程序要调用到的标准C库的函数合并到hello.o程序中,
// * 比如调用到printf函数,printf函数存在于一个名为printf.o的单独编译的可重定位目标程序中,
// * printf.o以某种方式合并到hello.o文件,ld负责处理这种合并,
// * 合并后得到文件hello,可执行目标文件(简称可执行文件),可以加载到内存中,有系统执行.
int main(void)
{
    float f_var_a;
    // \b : 光标左移一位
    // \r : 光标回到当前行起始处
    // \n : 光标移到下一行起始处
    printf("Enter floating point number: $__________\b\b\b\b\b\b\b\b\b\b");
    scanf("%f", &f_var_a);
    printf("hello world!\n");
    return 0;                    
    //函数体内程序结束,不加的话运行到函数内的最后一句代码之后也是会结束返回的
    //return后面可以加返回值
    //加在这里,下面的代码就不会运行了
    printf("hello world!\n");
}
//屏幕上显示的这段代码只是ascii码对应的字体文件的屏幕输出(这只是我个人的简化理解)

/*
    个人的一点简化的理解(省略很多细节,而且未必正确,但目前对我的知识水平来说解释得通...):
        假设w=3,无符号数,源程序数据:7+7(文本)--编译系统-->可执行文件(二进制数据:111+111)
        shell命令行解释器,输入可执行文件名称,按回车(这过程在计算机中的细节去看《深入理解计算机系统》P7)
        111和111加载在cpu寄存器堆,alu(arithmetic logic unit)读取数据进行加法运算
        得到数据1(110)--保留110, 
        %u(format specific格式说明符),编译系统编译后应该是个机器指令
        这个机器指令是把110处理成字符 6的ascii编码
        ascii编码从寄存器--->总线-->图形适配器-->显示器 显示6在屏幕上

    w=3,B2U(bit vector) --映射map--> [0,7]的ascii编码
    按照我们人类的思维,x+y应该最大值是7+7=14
    经过上面一段描述的过程
    发生了所谓的溢出,得到的结果6= 14-8 = 14 mod 8

    short unsigned x=1;(文本文件)--编译系统(compilation system)--
    --> 二进制文件(机器语言代码)中 数据x=[0000 0000 0000 0001] 
    C编译器根据C语言的标准来实现
*/


// 20210415标记,以下内容已停止更新,更新版请移步到computer_science.c(以该文件内容为准)
// 计算机基础知识:
//   半导体,常温条件下导电性能介于导体和绝缘体之间的材料
//   晶体管,它是一个开关,可以用控制线路来控制开或关
//                                电极(可当成输入)
//                                  |
//                                 /
//      控制线control wire --------|   <---- "|"为半导体,是一个门电极gate electode
//                                 \           通过控制线改变门的电荷electrical charge of the gate
//                                  |          来控制半导体材料的导电性
//                                 电极(可当成输出)
//   布尔代数(boolean)
// 1.NOT Gate 非门:
//                                电极
//                                  |_____  output输出
//                                 /
//               input输入 --------|   
//                                 \           
//                                  |         
//                                __|__
//                                 ___    "接地"
//   input off, output on  电流往output方向流动
//   input on , output off 电流往接地方向流动
//   logic table for Not:
//       ____________________
//      | input   |   output |
//      | true  1 |  false 0 |
//      | false 0 |  true  1 |
//       --------------------
// 2.AND Gate 与门:
//     _____  ____  _____  output
//          \/    \/
//         ----  ----
//          |     |
//      inputA  inputB 
//  logic table for And:
//       ________________________________
//      | input A | output B |  output   |
//      | true  1 |  true  1 |  true  1  |
//      | true  1 |  false 0 |  false 0  |
//      | false 0 |  true  1 |  false 0  |
//      | false 0 |  false 0 |  false 0  |
//       --------------------------------
// 3.OR Gate 或门:
//   current电流
//             __________     ___
//            |          \___/   |
// current ---|            |     |-- output
//            |__     ____/-\____|
//               \___/     |
//                 |       |
//              inputA   inputB  (transistor晶体管)
//       ________________________________
//      | input A | output B |  output   |
//      | true  1 |  true  1 |  true  1  |
//      | true  1 |  false 0 |  true  1  |
//      | false 0 |  true  1 |  true  1  |
//      | false 0 |  false 0 |  false 0  |
//       --------------------------------
// 4.XOR Gate 异或门:
// 
//  =|=AND-Not-|
//   |=OR------|=AND--
//
//            _______      NOT
//  ---+------|      \     |\
//     |      | AND   )----| >----+
//  ---|--+---|______/     |/     |
//     |  |                       |   _______
//     |  |   _______             |___|      \
//     |__|___\      \            ____| AND   )----
//        |    | OR   \___________|   |______/
//        |___ |      /               
//            /______/
//
//       ________________________________
//      | input A | output B |  output   |
//      | true  1 |  true  1 |  false 0  |
//      | true  1 |  false 0 |  true  1  |
//      | false 0 |  true  1 |  true  1  |
//      | false 0 |  false 0 |  false 0  |
//       --------------------------------
//-----------------------------------------------------
// P5:
// ALU: arithmetic logic unit
//        an arithmetic unit and a logic unit
//-----------------------------------------------------
// 5.half adder 半加法器:
//       _______________________
//      |   input   |  output   |
//      ------------------------
//      |  A  |  B  |carry| sum |
//      ------------------------
//      |  0  |  0  |  0  |  0  |
//      |  0  |  1  |  0  |  1  |
//      |  1  |  0  |  0  |  1  |
//      |  1  |  1  |  1  |  0  |
//      ------------------------
//                 _______             
//               \ \      \           
//   A---+-------|  | XOR  \______SUM
//   B---|--+----|  |      /              
//       |  |    / /______/
//       |  |       ______
//       |  |______|      \
//       |_________| AND   )------CARRY
//                 |______/
//
//   抽象(封装成一个单独组件):
//         _____________
//     A--|  half adder |-- SUM
//     B--|_____________|-- CARRY
//
// 6.full adder 全加器:
//     注: 这里的C是指低位的进位
//       _____________________________
//      |     input       |   output  |
//      -------------------------------
//      |  A  |  B  |  C  |carry| sum |
//      -------------------------------
//      |  0  |  0  |  0  |  0  |  0  |
//      |  0  |  1  |  0  |  0  |  1  |
//      |  1  |  0  |  0  |  0  |  1  |
//      |  1  |  1  |  0  |  1  |  0  |
//      -------------------------------
//      |  0  |  0  |  1  |  0  |  1  |
//      |  0  |  1  |  1  |  1  |  0  |
//      |  1  |  0  |  1  |  1  |  0  |
//      |  1  |  1  |  1  |  1  |  1  |
//      -------------------------------
//         _____________
//     A--| half adder 2|-- CARRY -------------------------------- OR ------ C[i+1]
//     B--|_____________|-- SUM---|                                 |
//                                |        _____________            |
//                                |----A--|half adder 1 |-- CARRY---|
//     C[i]--------------------------- B--|_____________|-- SUM ------------ SUM[i] (i>=0)
//  C[i+1]会发生进位CARRY的必要条件:
//     1. 全加器2只有A和B都为1时才会进位,它的SUM为0,所以全加器2最大只能为1,不会进位CARRY
//     2. 全加器1只有A(half adder2 SUM)和B都为1时才会进位
//            2.1 全加器1 A(全加器2 SUM)为1的情况,只有全加器2 A和B中其中一个为1,一个为0,全0或全1 SUM都为0
//            2.2 全加器1 B(低一位的进位C为1)
//   总结：半加器1和半加器2不会发生同时进位CARRY的情况
//
//   全加器抽象:
//                 ___________
//           A----| full      |----C[i+1]
//           B----| adder     |
//        C[i]----|___________|----SUM[i]
//
// 7.8bit ripple carry adder(8位行波进位加法器):
//       _____________
//   A--|  half adder |-- SUM ----------------------------------------------- SUM[0]
//   B--|_____________|-- CARRY--|
//                               |         ___________
//                               |--C[i]--| full      |--SUM[i]---------------SUM[1]
//                                     A--| adder     |
//                                     B--|___________|--C[i+1]---后面继续堆全加法器就行了
//
//  最高位的全加器如果发生进位carry,就会发生溢出overflow,超过8bit所能表示的数据
// * 现代的计算机用的加法电路有点不同,叫"超前进位加法器"
//   简单的CPU做乘法运算只是多做几次加法
//   现在的计算机和手机有专门的加法器,比较复杂,但本质也只是堆逻辑门
// 
// 8. arithmetic & logic unit 算术逻辑单元
//    里面很多逻辑门,我们不必关心这些细节,抽象化:
//                         8bit       8bit
//                        inputA     inputB
//          4bit            __|__    __|__        flags(常用的,还有很多其他标志,输出0/1-->假/真):
//      operation code -->  \    \  /    /   --> overflow  (用一条线连接加法器最高位carry输出即可)               
//                           \    \/    /    --> zero      (可用于两个数是否相等)
//                            \________/     --> negative  (可用于比较连个数的大小)
//                                |
//                              output
//                               8bit
//   logic unit:
//   zero flag(只要有1个1输入,输出结果就会为0假)
//     =OR--|
//          |==OR--|
//     =OR--|      |
//          |      |==OR--NOT--output
//     =OR--|      |
//          |==OR--|
//     =OR--|
//
//  注意: 各种门电路是一种抽象,我们只考虑输入和输出就好,不要太纠结于真实电路
//

// RAM random access memory







