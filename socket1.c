// 别忘记,源代码文件和其包含的头文件同属一个翻译单元,
// 同一翻译单元定义的标识符在同一个文件作用域
// 注意别和多文件编译混淆
#include "fyf.h"
#include <stdio.h>
// address resolution protocol address???
#include <arpa/inet.h>
//#include <sys/socket.h>

int main(void) {
    // c99加入的uint16_t为了程序的可移植性
    uint16_t uint16_variable = 10;
    uint32_t uint32_variable;
    printf("%zd %zd\n",
    sizeof(uint16_variable), sizeof(uint32_variable));

    short short_temp_variable = uint16_variable;
    printf("%zd\n", sizeof(short_temp_variable));

    s_t s_t_variable = 1;
    printf("%d\n", e_a);
    return 0;
}

/*
    硬件端口、软件端口和协议端口.
    硬件端口:物理端口
    软件端口:缓冲区
    协议端口:不同port的数据分配给不同的进程(所以端口在报文中?)
*/
