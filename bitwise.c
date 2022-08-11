#include <stdio.h>
// 类函数宏 《c primer plus》 16.3
// 核心思路:用0去&按位与,清除相应的bit
/*
    <桶式移位器>实现左移和右移
    原理:
    例如,操作数1010,右移指令(SHR)
          |   |   |   |
    I0  1 | 0 | 1 | 0 |     --> 电流移动方向,可根据时钟周期向右移动
        --+---|---|---|
    I1  1 | 0 | 1 | 0 |     --> 注意每列的+位置为输出点
        --|---+---|---|
    I2  1 | 0 | 1 | 0 |     --> 有标志寄存器存储溢出的位
        --|---|---+---|
    I3  1 | 0 | 1 | 0 |     -->
        --|---|---|---+
          |   |   |   |
          O0  O1  O2  O3
*/
// 位运算的一些基础技巧
// 使用时要注意,宏只做文本替换,不做运算.
// 替换体 替换 类函数宏圆括号里的文本
// 类函数宏的参数为替换体里的参数
// 不强制转换数据类型的话,x默认为int类型
#define GET_BYTE0(x) ((long)x >> 0) & 0x00000000000000ff
#define GET_BYTE1(x) ((long)x >> 8) & 0x00000000000000ff
#define GET_BYTE2(x) ((long)x >> 16) & 0x00000000000000ff
#define GET_BYTE3(x) ((long)x >> 24) & 0x00000000000000ff
#define GET_BYTE4(x) ((long)x >> 32) & 0x00000000000000ff
#define GET_BYTE5(x) ((long)x >> 40) & 0x00000000000000ff
#define GET_BYTE6(x) ((long)x >> 48) & 0x00000000000000ff
#define GET_BYTE7(x) ((long)x >> 56) & 0x00000000000000ff
#define GET_BIT(x, bit) (x & (1 << bit)) >> bit
int get_byte(long int, unsigned int);
int get_bit(int, unsigned int);

int main(void) {
    //int hex = 0x00000080;
    //printf("%x %x %x\n", hex, hex >> 4, hex >> 8);

    long int hex = 0x12345678912345L;
    printf("0x%x\n", GET_BYTE0(hex));
    printf("0x%x\n", GET_BYTE1(hex));
    printf("0x%x\n", GET_BYTE2(hex));
    printf("0x%x\n", GET_BYTE3(hex));
    printf("0x%x\n", GET_BYTE4(hex));
    printf("0x%x\n", GET_BYTE5(hex));
    printf("0x%x\n", GET_BYTE6(hex));
    printf("0x%x\n", GET_BYTE7(hex));

    unsigned char u_char = 0b10101100;
    // 运算时隐式类型转换为unsigned int
    printf("bit%u = %x %zdbytes\n", 0, GET_BIT(u_char, 0), sizeof GET_BIT(u_char, 0));
    printf("bit%u = %x\n", 1, GET_BIT(u_char, 1));
    printf("bit%u = %x\n", 2, GET_BIT(u_char, 2));
    printf("bit%u = %x\n", 3, GET_BIT(u_char, 3));
    printf("bit%u = %x\n", 4, GET_BIT(u_char, 4));
    printf("bit%u = %x\n", 5, GET_BIT(u_char, 5));
    printf("bit%u = %x\n", 6, GET_BIT(u_char, 6));
    printf("bit%u = %x\n", 7, GET_BIT(u_char, 7));

    get_bit(1, 0);
    get_bit(3, 0);
    get_bit(3, 1);
    get_byte(hex, 0);
    get_byte(hex, 1);
    get_byte(hex, 2);
    get_byte(hex, 3);
    get_byte(hex, 4);
    get_byte(1024L, 0);
    get_byte(1024L, 1);
    return 0;
}

int get_byte(long int number, unsigned int byte) {
    switch (byte) {
        case 0: {
            printf("0X%x\n", GET_BYTE0(number));
            break;
        }
        case 1: {
            printf("0X%x\n", GET_BYTE1(number));
            break;
        }
        case 2: {
            printf("0X%x\n", GET_BYTE2(number));
            break;
        }
        case 3: {
            printf("0X%x\n", GET_BYTE3(number));
            break;
        }
        case 4: {
            printf("0X%x\n", GET_BYTE4(number));
            break;
        }
        case 5: {
            printf("0X%x\n", GET_BYTE5(number));
            break;
        }
        case 6: {
            printf("0X%x\n", GET_BYTE6(number));
            break;
        }
        case 7: {
            printf("0X%x\n", GET_BYTE7(number));
            break;
        }
        default: {
            printf("out of range!\n");
            break;
        }
    }
    return 0;
}

int get_bit(int x, unsigned int bit) {
    printf("number(decimal):%d bit%u = %x\n", x, bit, GET_BIT(x, bit));
    return 0;
}





// 只是单纯为了用一下switch语句...
//int get_bit(int x, unsigned int bit) {
//    switch (bit) {
//        case 0: {
//            printf("number(decimal):%d bit%u = %x\n", x, 0, GET_BIT(x, 0));
//            break;
//        } 
//        case 1: {
//            printf("number(decimal):%d bit%u = %x\n", x, 1, GET_BIT(x, 1));
//            break;
//        } 
//        case 2: {
//            printf("number(decimal):%d bit%u = %x\n", x, 2, GET_BIT(x, 2));
//            break;
//        } 
//        case 3: {
//            printf("number(decimal):%d bit%u = %x\n", x, 3, GET_BIT(x, 3));
//            break;
//        }
//        case 4: {
//            printf("number(decimal):%d bit%u = %x\n", x, 4, GET_BIT(x, 4));
//            break;
//        }
//        case 5: {
//            printf("number(decimal):%d bit%u = %x\n", x, 5, GET_BIT(x, 5));
//            break;
//        }
//        case 6: {
//            printf("number(decimal):%d bit%u = %x\n", x, 6, GET_BIT(x, 6));
//            break;
//        }
//        case 7: {
//            printf("number(decimal):%d bit%u = %x\n", x, 7, GET_BIT(x, 7));
//            break;
//        }
//        case 8: {
//            printf("number(decimal):%d bit%u = %x\n", x, 8, GET_BIT(x, 8));
//            break;
//        }
//        case 9: {
//            printf("number(decimal):%d bit%u = %x\n", x, 9, GET_BIT(x, 9));
//            break;
//        }
//        default: {
//            printf("%ubit => out of range\n");
//            break;
//        }
//    }
//    return 0;
//}
