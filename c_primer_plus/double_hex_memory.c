//浮点数在内存中的存储格式用十六进制打印
#include <stdio.h>
#include <stdlib.h>
int int_promotion(void);

void main(void){
    // 对文件c_primer_plus9.c的第199行笔记做验证,已手动转换7.0的十六进制存储编码
    double d1 = 7.0, d2 = 1.5;
    // 将double类型变量d的指针&d强制转换成下面代码所示的指针类型
    unsigned long int * uli;

    uli = (unsigned long int *)&d1;
    // 最后得到的结果与手动转换的完全一致
    printf("%lx\n", *uli);

    uli = (unsigned long int *)&d2;
    printf("%lx\n", *uli);

    // unsigned无符号数,避免有符号数中的负数整形提升时不足位数填充1的问题
    unsigned char * uc;
    uc = (unsigned char *)&d2;
    // 数组名为第一个元素指针的逆向应用
    printf("%02x %02x %02x %02x %02x %02x %02x %02x\n",
     uc[0], uc[1], uc[2], uc[3], uc[4], uc[5], uc[6], uc[7]);
    printf("%02x %02x %02x %02x %02x %02x %02x %02x\n",
     *uc, *(uc+1), *(uc+2), *(uc+3), *(uc+4), *(uc+5), *(uc+6), *(uc+7));
    // 小端序,低位存储在低字节;
    printf("%02x %02x %02x %02x %02x %02x %02x %02x\n",
     uc[7], uc[6], uc[5], uc[4], uc[3], uc[2], uc[1], uc[0]);
    // 最后得到的结果与手动转换的完全一致

    char char_array[3] = {0, 1, 2};
    // 数组名为数组第一个元素的指针,char类型指针
    printf("%d\n", *char_array);
    printf("%zd\n", sizeof(*char_array));
    // &数组名为整个数组的指针
    printf("%zd\n", sizeof(*&char_array));

    /*
    unsigned long int binary = 0b0011111111111100000000000000000000000000000000000000000000000000;
    */

    int_promotion();

    return;
}
// 为什么不用unsgined打印会出错？
// 原因：整形提升，正数填充0，负数填充1。高位填充，填充符号位
//      main函数中的例子，打印时char提升为int，因为第二个字节最高位为1，(提升时不足的位数填充1)
//      因此char数组第二个元素输出为 fffffff8
//
// 我个人的实现负整数整形提升填充符号位的思路:
//      最高位符号位为0
//      0000 0001读取入32位寄存器
//      0000 0000 0000 0000 0000 0000 0000 0001 正整数整形提升
//
//      最高位符号位为1
//      1000 0001读取入32位寄存器
//      0000 0000 0000 0000 0000 0000 1000 0001
//      使用“掩码”：1111 1111 1111 1111 1111 1111 0000 0000 (通过算术逻辑单元)按位与| 要整形提升的char类型变量
//
//      以下仅为个人推测...
//      但在参与运算的情况下会转换成二补码进行运算?我觉得是肯定的啊,因为结果是正确的int类型结果
//      传入printf函数可变参数没有进行运算,所以只有整形提升？
//            
//      进行算术运算时,如果是负整数,则先转换成二补数编码
//      1111 1111 1111 1111 1111 1111 1000 0001
//      用"掩码"：1000 0000 0000 0000 0000 0000 1111 1111 (通过算术逻辑单元)按位| 转换成负整数的二补码编码
//
//      结论是确认的,但实现过程仅为个人猜想,纯属娱乐,貌似这玩意的实现也没啥固定标准吧...C标准也只是规定了结果,并没规定过程
//      但不同的编译器实际是怎么处理的，我目前还没查到相关深入的资料,只能自己脑补了...  (～￣▽￣)～ 


/*
    integer promotion in c 整形提升(算是一种隐式转换)
        char、short传入printf的可变参数(传参,赋值给形参)或
            进行算术运算时(对它们执行操作时),提升为int类型    sizeof并不是算术运算符
        unsigned char、short则提升为unsigned int类型
*/
int int_promotion(void){
    char c1 = 2;
    short int si1 = 2;
    printf("%zd %zd %zd\n", sizeof(c1), sizeof(si1), sizeof(c1 + si1));

    char cb1 = 0b10000001, cb2 = 0b01111111;
    printf("%zd %d %x\n", sizeof(cb1), cb1, cb1);
    printf("%zd %zd %d %x\n", sizeof(cb2), sizeof(+cb2), cb2, cb2);
    return 0;
}

/*
    float传入printf的可变参数或进行表达式运算时(对它们执行操作时),提升为double类型
*/
