#include <stdio.h> //预处理器指令 头文件:具体看书，懒得写了。。。= ='

int main(void)
{
    /* 变量声明:declaration 
     *    第一种方式：
     *        int a;
     *        a = 10;
     *    第二种方式：
     *        int a = 10;
     *    第三种方式：
     *        int a,b;
     *        a = 10;
     *        b = 20;
     *    第四种方式：
     *        int a = 10,b = 20;
     */
    int a = 10;
    float f,n,value;
    float m = 3.14e-3;

    /* short long unsigned 附属关键字 《c primer plus》P125 */
    /* short = short int, long = long int, unsigned = unsighed int */
    /* unsigned 无符号类型. int,float,double默认其实都是有符号类型signed */
    short s;
    short int si;
    int i;
    unsigned ui;
    long l;
    long int li = 123456789;
    long long ll;
    long long int lli;

    /*
     * 整数溢出：
     *     short int 最大值：11111111 + 1 --> 00000000,多出来的bit无法保存,所以又变回了最小值
     */ 
    //整数溢出,但编译器没报错。
    //short int overflow1 = 65536; 开始报错
    //65536二进制:1 0000 0000 0000 0000 
    //[32768,65535]之间编译器都不会报错,看上面的65536的二进制就知道了,17位bit
    //short int数据类型 [-32768,32767]<--->[0000 0000 0000 0000,1111 1111 1111 1111]内存中
    //unsigned short int数据类型 [0,65535]<--->[0000 0000 0000 0000,1111 1111 1111 1111]内存中
    //所以编译器不会报错，数据在内存中没有超出变量声明分配的存储空间
    // *重点：计算机只有加法运算器，具体运算过程要先补习原码，反码，补码
    // *符号位用最高位(比特位)来表示,0000 0001表示+1,1000 0001表示-1。
    // *补充：只有[整数类型]和[字符类型]分[有符号类型]和[无符号类型]。其余都为有符号类型
    // 补码的定义网上有,可正确理解补码的由来,二进制的补码可通过反码+1得来，但反码+1并不是补码的定义。
    // 补码涉及到模的概念,忘记了再上网查询理解就行。
    // *帮助理解补码tips:无论什么进制,原码(原数)+补码(补数)=模 重点:原数+补数进一位
    //     例如:十进制,模为10,制作一个0~9的圆形计量表,逢10转完一圈,但计量表无法显示10,而是回到0,
    //          只能显示10的余数位0
    //          9-3=6,9+7=16=6只保留个位数,溢出的一位就像8bit运算结果得9bit,而数据类型分配存储空间就是8bit,
    //          所以最后保留了余数位,得到了9-3=6和9+7=16=6的结果
    //          7+3=10(模,进一位)  9-3与9+7效果一样
    //正数(+1)：
    //  原码=反码=补码  000 0001 = 0000 0001 = 0000 0001
    //负数(-1)：
    //  原码：1000 0001 最高位为符号位，后面为绝对值
    //  反码：1111 1110 符号位不变,反码=原码除符号位外取反
    //  补码：1111 1111 符号位不变,反码+1。补码=反码+1
    //原码+原码 原码+反码都得不到正确结果
    //正确运算方法： 1+(-1)=0, 负数在计算机中以补码存储
    //  0000 0001
    // +1111 1111
    // =0000 0000
    // 
    short int of1,of2;
    short int overflow1 = 32767;
    short int overflow2 = -32768;
    unsigned short int overflow3 = 65535;
    unsigned short int b = 60000;
    long big1 = 65536,big2 = -65536;

    /*
     * printf() c库的输出函数 print format:格式打印................................................
     */
    printf("enter number: ");
    
    /* 'a'表示- a的字符字面量*/
    /* "a"表示- a的字符串字面量(指针) */
    scanf("%f", &n);  // & 地址运算符 取变量n内存地址
    value = n * n;
    printf("n = %.2f, value = n * n = %.2f.\n", n, value);
    
    /* %d成为转换说明 */
    printf("%d\n", a);
    printf("%f\n", m);
    
    /* binary二进制 octonary八进制 decimal十进制 hexadecimal十六进制 */
    printf("整数类型变量a 转换说明 不显示前缀的八进制:%o\n", a);
    printf("整数类型变量a 转换说明 不显示前缀的八进制:%#o\n", a);
    printf("整数类型变量a 转换说明 不显示前缀的十六进制:%x\n", a);
    printf("整数类型变量a 转换说明 显示前缀的十六进制:%#x\n", a);
    printf("整数类型变量a 转换说明 不显示前缀的十进制:%#d\n", a);
    printf("整数类型变量a 转换说明 显示前缀的十进制:%#d\n", a);
    printf("long int variable 转换说明 显示有前缀的十六进制:%#lx\n", li);
    printf("short int variable 转换说明 显示前缀的八进制:%#ho\n", overflow1);
    printf("short int variable 转换说明 显示前缀的八进制:%#ho\n", overflow2);
    printf("short int variable 转换说明 显示前缀的八进制:%#hu\n", overflow3);
    printf("short int variable 转换说明 显示前缀的十六进制:%#hx\n", overflow1);
    printf("short int variable 转换说明 显示前缀的十六进制:%#hx\n", overflow2);
    printf("short int variable 转换说明 显示前缀的十六进制:%#hu\n", overflow3);
    
    //变量b在计算机储存的二进制表示与-1294967296的计算机储存(负数以补码储存)的二进制表示相同
    //转换说明:%u unsigned int,%d int 
    //理解:%u [0000,1111] [0,15]; [0000,0111][0,7]正数区间u1,[1000,1111][8,15]正数区间u2
    //     %d [0000,1111] [-8,7]; [0000,0111][0,7]正数区间d1,补码:[1000,1111][-8,-1]负数区间d2
    //     u1和d1区间所表示的正数是相同的,所以这区间%u和%d转换说明输出的结果都一样
    //     u2和d2区间所表示的整数不相同(),d2区间的原码和补码虽不同但都在d2[1000,1111]这一区间,与u2重叠,
    //     所以必然出现u2和d2在计算机存储中二进制表示相同的情况.
    //     提示:d2的1000比较特殊,为了避免+0和-0,用1000表示最小值(-8),其它的直接二进制换算成十进制就能得到正确结果
    //     d2为负数,储存的是补码,%d转换说明先转换成原码(补码是相互的,所以补码的补码就是原码),再转换负数十进制整数
    printf("unsigned short int b = %hu,not = %hd\n", b, b);
    printf("long int big = %ld,not = %hd\n", big1, big1);
    printf("long int big = %ld,not = %hd\n", big2, big2);
    printf("short int -32768十六进制%hx\n", overflow2);

    printf("float size:%d\n", sizeof(f));
    printf("short size:%d\n", sizeof(s));
    printf("short int size:%d\n", sizeof(si));
    printf("int size:%d\n", sizeof(i));
    printf("unsigned int size:%d\n", sizeof(ui));
    printf("long size:%d\n", sizeof(l));
    printf("long int size:%d\n", sizeof(li));
    printf("long long size:%d\n", sizeof(ll));
    printf("long long int size:%d\n", sizeof(lli));
    
    //整数溢出,有符号类型的数值位溢出(超出存储空间),编译器不会报错(C标准未定义有符号类型溢出规则)
    //32767 short int binary: 0111 1111 1111 1111
    //运算: + 1       binary: 0000 0000 0000 0001
    //结果:           binary: 1000 0000 0000 0000
    //不赋值直接转换成十进制:  32768
    //赋值给短整型变量再转换: -32768  原因:最高位符号位1表示负数,短整型值区间:[-32768,32767]
    printf("overflow1:%d,\n(结果存入短整型变量,整数溢出)of1=overflow1+1=%d,\n(直接运算结果)overflow1+1=%d\n",\
		    overflow1, of1=overflow1+1, overflow1+1);
    //-32768 short int binary: 1000 0000 0000 0000 原码
    //                         1111 1111 1111 1111 反码 符号位不变,其它取反
    //           计算机中储存: 1000 0000 0000 0000 补码 符号位不变,反码+1 
    //
    //-1               binary: 1000 0000 0000 0001 同上
    //                         1111 1111 1111 1110
    //           计算机中储存: 1111 1111 1111 1111
    //     
    //运算: +                  1000 0000 0000 0000 -32768补码 
    //原因看上面整数溢出注释 + 1111 1111 1111 1111 -1补码     
    //                       1 0111 1111 1111 1111 运算结果:1.赋值给变量后整数溢出,最高位变0变正数
    //                                                      2.直接运算结果,有符号类型,最高位1,负数
    //赋值给短整型变量再转换: 32767  原因:最高位符号位0表示正数,短整型值区间:[-32768,32767]
    //
    //                       1 0111 1111 1111 1111 不赋值,最高位符号位1,为负数
    //                       1 1000 0000 0000 0000 反码
    //                       1 1000 0000 0000 0001 补码 -32769
    printf("overflow2:%d, of2=overflow2-1=%d, overflow2-1=%d\n",\
		    overflow2, of2=overflow2-1, overflow2-1);
    printf("overflow3:%u, overflow3+1=%u, overflow3+2=%u\n",\
		    overflow3, overflow3+1, overflow3+1000000);

    return 0;
}





