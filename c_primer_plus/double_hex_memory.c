//浮点数在内存中的存储格式用十六进制打印
#include <stdio.h>
void main(void){
    //对文件c_primer_plus9.c的第199行笔记做验证,已手动转换7.0的十六进制存储编码
    double d = 7.0;
    //将double类型变量d的指针&d强制转换成下面代码所示的指针类型
    unsigned long int * uli = (unsigned long int *)&d;
    printf("%lx\n", *uli);
    return;
}
//最后得到的结果与手动转换的完全一致
