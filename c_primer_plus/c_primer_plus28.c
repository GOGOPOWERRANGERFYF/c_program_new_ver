// 第15章 位操作
#include <stdio.h>
void bitwise_operator(void);
void left_right_shift(void);

void main(void){
    char temp_char;
    // 0b前缀,二进制常量(gcc支持)
    temp_char = 0b01100001 + 0b00000001;
    printf("%c\n", temp_char);
    temp_char = ~0b00000000;
    printf("%hd\n", temp_char);
    temp_char = 0b01100001 & 0b01100000;
    printf("%c\n", temp_char);
    temp_char = 0b01100001 | 0b00000001;
    printf("%c\n", temp_char);
    temp_char = 0b01100001 ^ 0b00000001;
    printf("%c\n", temp_char);

    //bitwise_operator();
    left_right_shift();
    return;
}
// 15.1 二进制数,位和字节 
//  ...
// 15.1.1 二进制整数
// 高阶位(编号7) -->  低阶位(编号0)
// high-order bit-->low-order bit
// 编号: 7  6  5  4  3  2  1  0
// byte: 0  0  0  0  0  0  0  1
//  
//
//
// 15.3 c按位运算符
// 15.3.1 按位逻辑运算符
//  4个按位逻辑运算符用于整型数据,包括char
//  按位(bitwise)运算
//  1.按位取反 ~ (一元运算符)
//  数学层面:一补码,一补数
void bitwise_operator(void){
    int a, b;
    a = 0;
    b = ~a;
    a = ~a;
    printf("a = %d; b = %d\n", a, b);
    return;
}
//  2.按位与 &
//
//  3.按位或 |
//
//  4.按位异或 ^
//

// ...

// 15.3.7 移位运算符
//  shift 转移
//  移位运算符向左或向右移动位
//  << 左边抛弃,右边补充0
void left_right_shift(void){
    char temp_char;
    temp_char = 0b00011000 << 2;
    printf("%c\n", temp_char);
    temp_char = 0b11000000 >> 1;
    printf("%c\n", temp_char);
    return;
}
//  1.左移: <<
//  
//  2.右移: >>

