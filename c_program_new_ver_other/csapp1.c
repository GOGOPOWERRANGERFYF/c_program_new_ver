//  《深入理解计算机系统》
//  《计算机系统:一个程序员的视角》
//  CSAPP   Computer Systems A Programmer's Perspective Third Edition
//  
//  第3章 程序的机器级表示
//  3.7 过程
//  ...
//  3.7.1 运行时的栈
//  当X86-64过程需要的存储空间超出寄存器能够存放的大小时,就会在栈上分配空间
//  这个部分称为过程的栈帧(stack frame)
//  


// 第4章 处理器体系结构
//
//  ISA(instruction set architecture):指令集架构
//
// 4.1.3 指令编码:
//  每条指令第一个字节表明指令的类型
//  这个字节分为两个部分:高4位是代码code部分,低4位是功能function部分
//  0000 0000  
// 