#include <stdio.h>
/*
 *A.十进制(十进制计数法): 由是十个基数0,1,2,3,4,5,6,7,8,9表示,满十进一
 *个人理解: 数位1[十个基数(符号)最大只能表示九,然后9+1,数位1已经没有符号表示十了,假设数位1上有十根辣条,数位1已经没有符号表示十根
 *辣条了,然后把十根辣条捆成一捆,丢到数位2(1进位到数位2,进位2的1(一捆辣条)表示十根辣条,1*10(读成1个10更好理解),10为数位2的位权),
 *所以数位2变成1,数位1变成0(因为十根辣条已经全部放到数位2了,所以数位1就一根辣条也没有了),所以10(读作一零更好理解)表示十]
 *
 * 二进制跟上面的十进制概念是一样的,只是基数变成0,1。满二进一
 * 二进制转换成其他进制:
 * (1111)2=1*2^3+1*2^2+1*2^1+1*2^0=8+4+2+1= (15)10十进制 (e)16十六进制 (17)8八进制 
 * (平时都是用十进制,不理解十进制的定义,思维固化,虽知道转换方法,但不懂其中的原理,时间一久就忘了,脑子转不过弯,知其然不知其所以然... --`)
 * 1111 1111 = (255)10 [0000 0000,1111 1111]=[0,255]区间有256个符号表示0~255
 * 1 0000 0000 = (256)10 [0000 0000,1 0000 0000]=[0,256]区间有257个符号表示0~256
 * 位权:因为平时都习惯用十进制,所以位权就用十进制表示吧,换成其实进制脑子不够用(要不人类发明计算机干嘛呢～),习惯真可怕。。。
 * 位权通俗来说就是每一数位的1表示多少根辣条(平时用开十进制,梗系用十进制表示位权啦,啊!!!十进制已经灌进了我脑中无法磨灭了)
 *
 * B.机器数的真值(机器数的形式值:看了定义感觉跟无符号数一样)
 * 机器数:一个数在计算机中的二进制表示,机器数是带符号的
 * 例如: 1000 0001的真值=-000 0001=(-1)10  1000 0001的形式值=(129)10
 *
 *
 * C.二进制代码-->数据类型的本质就是分配存储空间长度-->转换说明才决定输出的数据字面量(常量)
 *整数常量integer constants(C语言中字符常量character constants也被当作整数常量)
 *在声明(declaration)变量时,整数常量(由上可知当然也包含字符常量,字符常量本质上在计算机存储二进制代码中算是整数常量的子集,)
 *赋值给变量,如果该整数字面量(整数常量)大于或小于该数据类型所代表的整数字面量的区间,编译器编译时会报错,
 *但非声明变量时不会报错,会出现整数溢出,得不到正确结果.
 *
 *以8bits有符号数为例,除去一个符号位,数值位共7位,模1000 0000,模mod为2^7。
 *以十进制数为例,个位的模为10^1,十位的模位10^2,以此类推. 10^n/10^m=10^(n-m) 10^1/10^1=10^(1-1)=10^0=1
 *以十进制为例,数学公式(同余式-通俗说就是余数相同):-3=7(mod10) mod10表示模是10, 7是(-3)对10的补数
 */
/*
  位置计数系统小数的本质:
      (0.1)10  = 1/10       一根辣条变10份,十分之一根辣条
               = 1/10^1
               = 1*10^0/10^1
               = 1*10^(0-1)
               = 1*10^-1
               = 10^-1
    10的0次方为什么等于1:
       10^0 = 10/10         十根辣条除于十,变一根辣条
            = 10^1/10^1
            = 10^(1-1)
            = 10^0
            = 1
    10的2次方除于10的1次方:
       10^2/10^1 = 100/10 = 100 * 1/10     100根辣条,分成十份,只剩一份了
                 = 10
                 = 10^1
                 = 10^(2-1)
    小数点向左移一位和向右移一位的本质:
        (11.11)2  ---小数点左移一位---> (1.111)2  
        本质:(这里用十进制表述),从最高位起,两根辣条变一根,一根辣条变1/2根,1/2根变1/4根
        (11.11)2  ---小数点右移一位---> (111.1)2
        本质:跟上面道理一样,只不过刚好相反,2根辣条变4跟,以此类推......  
*/
// 十六进制与二进制的关系:
//         x[1]                    x[0]               一位x取值范围[0,15] --> [0,f]
//  d[7] d[6] d[5] d[4]    d[3] d[2] d[1] d[0]        四位d取值范围[0,15] --> [0000,1111]
//  (  5   f  )16 
//  (0101 1111)2
// 四位二进制数 对应 一位十六进制数
//*理解的关键,满十六进位(把二进制的四位理解为十六进制中的一位就行了),这句才是理解重点,
//本质就是满十六进一,也是位置计数系统的本质啊
// 十六进制的一位用 0~f十六个符号表示,相当于用四位二进制 0000~1111十六种编码方式分别表示十六进制中的 0~f
// 八进制与二进制的关系原理也是一样的
//
int main(void)
{
    //*tips:C语言将字符常量视为int数据类型而非char数据类型
    //char字符类型本质上是整数类型,
    //ascii码和unicode码都是用整数来表示字符和符号
    //ascii码一个byte字节就能储存完(字母大小写和标点符号)
    //ascii码中'A' 对应整数65
    char c1 = 'A';
    char c2 = 65;
    char c3 = 255;
    //int -128二进制:1000 0000 0000 0000 0000 0000 1000 0000 -128很特殊,它没有原码反码,只有补码,具体查看补码的定义
    //          补码:1000 0000 0000 0000 0000 0000 1000 0000
    //int   -1二进制:1000 0000 0000 0000 0000 0000 0000 0001
    //          补码:1111 1111 1111 1111 1111 1111 1111 1111
    //-128-1 运算: 1(1111 1111 1111 1111 1111 1111 0111 1111) 结果为负数,补码与原码不一样,所以要得到正确结果还要转成原码
    //       原码:   1000 0000 0000 0000 0000 0000 1000 0001  原码转换成十进制结果,得到-129
    //                                             1*2^7+1*2^0=129   2^(n-1)为二进制中第n位的位权 
    //char c4 = -129; 编译时报错,溢出
    //char c4 = 256;  编译时报错,溢出
    //char c4 = -256; 编译时报错,溢出

    short int hi1 = -32768;
    
    int i1 = 'A';
    int i2 = 65;

    //非打印字符 P134:
    //1.直接ascii码赋值(转换成int数据类型赋值)
    char beep = 7;
    //2.转义序列(escape sequence)
    char newline = '\n';
    short int int_newline = '\t';
    /* 个人理解:字符常量虽被C语言视为int类型(整数常量),但声明时(declaration)给变量(除布尔型)赋值没有溢出overflow错误
      (因为ascii码不超过8bit,视为int类型前面的bit全部填充为0,整数字面量在[-128,255]区间),
       int数据类型声明变量赋值时,如果超过int类型的数值范围编译器会提示overflow出错
       运算后溢出编译器不会提示错误,但得到的结果并不正确(整数溢出) */
    short int a = 100,sum; 
    
    //布尔类型:true,false 1,0 占1bit存储空间
    _Bool b;
    
    //运算结果超出了声明时分配给变量sum的存储长度,整数溢出
    sum = a + 1000000;

    printf("sum:%hd\n", sum);

    printf("char size:%dbyte\n", sizeof(c1));
    printf("int size:%dbyte\n", sizeof(i1));
    printf("character c1='A' 转换说明i-->%d,character c2=65 转换说明c-->%c\n", c1, c2);
    printf("integer i1='A' 转换说明i-->%d,integer i2=65 转换说明c-->%c\n", i1, i2);
    
    //P135 有需要就到转义序列表查看即可
    /*常用 转义序列: \t \b \n \r \' \" \\ 非打印字符*/
    printf("转义序列例如: '\\\\' '\\\"' '\\t',转义序列(非打印字符)\\n效果:%c", newline);     
    printf("字符变量character variable size:%d\n", sizeof(newline));//字符变量占一个字节
    printf("字符常量character constants size:%d\n", sizeof('\n')); //得出tips的结论,字符常量占4个字节
    printf("-128 C compiler当作int数据类型,size:%d\n", sizeof(-129));
    printf("%c\n", c3);
    printf("%hx,%hx,%x\n", -1,-128,-128-1);
    printf("%hx\n", hi1);
    printf("布尔数据类型_Bool variable b size:%d\n", sizeof(b));
    return 0;
}
