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

    // unsigned无符号数,避免有符号数中的负数整形提升问题,下面第一段注释我详细说明了原因
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
// 原因：int promotion，整形提升，char和short整型提升为int
//      上面main函数中的例子，打印时char提升为int
//      因此char数组第二个元素输出为 fffffff8 (这是-f8的二补码,这是理解的关键,知识点很简单,其实就是二补码编码)
//
// 我个人厘清一下有符号数整形提升的过程,首先明确一点这里说的是有符号数:
//      最高位符号位为0
//      0000 0001读取入32位寄存器
//      0000 0000 0000 0000 0000 0000 0000 0001 正整数整形提升
//
//      最高位符号位为1
//      1000 0001(有符号数负整数的二补码)读取入32位寄存器
//      1000 0001(二补码)---map(映射)--->二进制数-0111 1111
//      0000 0000 0000 0000 0000 0000 0111 1111 提升为32位二进制数
//      1111 1111 1111 1111 1111 1111 1000 0000 32位一补数       
//      1111 1111 1111 1111 1111 1111 1000 0001 32位二补数       
//      这就是产生所谓整形提升时有符号数负整数“最高位符号位填充1”现象的本质,不要被表象所迷惑~
//      
//      理论是这样,但CPU和编译器实际是怎么处理的，我目前还没查到相关深入的资料,只能自己脑补了...  (～￣▽￣)～ 
//      C标准也只是规定了结果,并没规定具体过程

//  所以直接使用unsigned整数,没有符号位,无符号整数的二补码就不存在这样的问题,无符号整数直接转换成二进制数就是它的二补码了
/*
    integer promotion in c 整形提升(算是一种隐式转换)
        char、short传入printf的可变参数(传参,赋值给形参)或进行表达式算术运算时,提升为int类型
        比较好的记忆方法：有符号整数的二补码，-5的8位二补码或16位二补码 整形提升位  32位的二补码
                       而有符号负整数的8位、16位、32位、64位二补数就是该有符号负整数的二补码
        ***(sizeof并不是算术运算符)
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
