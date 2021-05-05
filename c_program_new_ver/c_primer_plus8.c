#include<stdio.h>
//  《c primer plus第六版》P217 第三段重点
//  *键盘只能生成文本字符: 字母,数字,标点符号
//  要输入整数1024
//  键盘键入字符 1 0 2 4
//  scanf函数 把 字符串 转化成 整数1024
//  character 字符; character string 字符串.
//
//printf()和scanf()函数参数：
//  [1] printf()函数使用变量,常量,可求值的表达式,有返回值的函数
//  [2] scanf()函数使用指向变量的指针
//
//scanf()读取基本类型变量的值,在变量名前加&
//scanf()读取字符串,储存到字符数组中,不使用&
void scanf_format_character_string(void);
void scanf_conversion_specification_character(void);
//void scanf_return_value(void);
void printf_star_modifier(void);
void scanf_star_modifier(void);
void usage_tips_for_printf(void);

void main(void)
{
    int age_a, age_b, age_c, age_d;
    float f_asset_a, f_asset_b, f_asset_c, f_asset_d;
    double d_asset_a;
    char name_a[10], name_b[10], name_c[10], name_d[10];
    printf("sizeof(f_asset_a): %zd,sizeof(d_asset_a): %zd\n",
     sizeof(f_asset_a), sizeof(d_asset_a));
    printf("input age  asset  name: ");
    // 每个输入项之间至少一个空白(换行符、空格、制表符)
    // scanf()函数使用空白把输入分成多个字段
    // 依次把转换说明和字段匹配时跳过空白
    // 内存区域:
    //  [...|数字字符|空白字符|数字字符|空白字符|字母字符|...]
    // 举例: scanf()函数 使用%d转换说明
    // 我想输入整数32
    // 使用键盘键入文本字符1和8
    //    3        2 
    // 数字字符  数字字符
    // 空白字符会被scanf()函数跳过
    // 遇到第一个数字字符或+/-符号字符开始读取,保存后再读取下一个字符
    // 读取到非数字字符,scanf()函数把非数字字符放回输入
    // 程序下一次读取时,从这个放回的非数字字符读取
    // 因此输入 32 40000fyf (正常的输入方式 -->:32 40000 fyf)
    // scanf()函数读取的结果也是正确的
    scanf("%d %lf %s", &age_a, &d_asset_a, name_a);
    // scanf() double类型转换说明要加修饰符l %lf,与pirntf()不同
    // conversion specification 转换说明
    // modifier 修饰符
    // *《c primer plus第六版》P220 scanf()转换说明,修饰符
    printf("Age: %d, Asset: %.2f, Name: %s\n", age_a, d_asset_a, name_a);
    // 打印变量的指针(地址)  
    // %p 指针
    printf("integer variable age virtual address: %p\n", &age_a);
    // %s %d 转换说明顺序
    // scanf()函数先读取非空白字符,读取一个,保存,再读取下一个字符
    // 读取到空白字符,读取结束(与转换说明%s匹配的字符串字段读取结束)
    // 再读取下一个与转换说明%d匹配的整数字段
    printf("input name age: ");
    scanf("%s %d", name_b, &age_b);
    printf("Name: %s, Age: %d\n", name_b, age_b);
    // %d %s 转换说明顺序
    // 如果输入A,scanf()函数读取到A后,将停止读取,并将A放回输入
    // 不会把值赋给指定变量
    // ***如果scanf()函数带多个转换说明,C规定在第一个出错处停止读取输入(后面的读取全部停止)
    printf("input age name: ");
    scanf("%d %s", &age_c, name_c);
    printf("Age: %d, Name: %s\n", age_c, name_c);
    
    printf("age(%%d): %d\n", age_d);
    printf("age(%%x): %x\n", age_d);
    printf("&age(%%x): %x\n", &age_d);
    // %d 一个转换说明(注:这里假设每个scanf函数只有一个转换说明,因此一次读取就是一个scanf函数调用)
    // 输入A,scanf()函数停止读取,把A字符放回输入
    // 程序下一次读取时,从这个A字符开始读取
    // 如果程序只有%d输入转换符,scanf()函数就一直无法越过A字符
    printf("input age: ");
    scanf("%d", &age_d);
    printf("age(%%d): %d\n", age_d);
    printf("age(%%x): %x\n", age_d);
    printf("&age(%%x): %x\n", &age_d);
    
    // %s
    // scanf()函数跳过空白字符,直到遇到第一个非空白字符
    // 读取,保存,再读取下一个字符,保存
    // 直到再次遇到空白字符,这个空白字符不保存
    // (这个空白字符放不放回输入不知道,书上没写。。。不过放不放也没啥意义)
    printf("input name: ");
    scanf("%s", &name_d);
    printf("name_d(%%s): %s\n", name_d);
    scanf_format_character_string();
    scanf_conversion_specification_character();
    //scanf_return_value();
    printf_star_modifier();
    scanf_star_modifier();
    usage_tips_for_printf();
    return;
}
// 注: 在C语言中,scanf()并不是最常用的输入函数,但它能读取不同类型的数据
//     C语言还有其它的输入函数,例如: getchar()和fgets(),会在后面的章节中介绍

void scanf_format_character_string(void)
{
    int i_sfcs_a, i_sfcs_b, i_sfcs_c, i_sfcs_d;
    // scanf函数允许在格式字符串中加入普通字符
    // * 空白字符包括(空格字符,制表字符,换行字符和没有空白字符的特殊情况)
    printf("input i_sfcs_a(int), i_sfcs_b(int);");
    printf("(%%d,%%d): ");
    //scanf(",%d%d", &i_sfcs_a, &i_sfcs_b);
    //从上一个回车键输入后已经开始读取
    //回车键产生的换行符与,逗号不匹配,多个转换说明,
    //根据C标准规定,这个scanf函数直接停止读取 
    //*因此普通字符并不像转换说明一样(前面加空白字符的特殊情况:即不加空白字符)可以跳过空白字符然后读取
    //要解决这个问题,在普通字符前加空白字符(非特殊情况),解决方法如下
    //scanf(" ,%d%d", &i_sfcs_a, &i_sfcs_b);
    scanf("%d,%d", &i_sfcs_a, &i_sfcs_b);
    printf("i_a,i_b: %d,%d\n", i_sfcs_a, i_sfcs_b);
    //scanf格式字符串中,[转换说明前]加空白字符(包括无空白字符的特殊情况,就是无字符)
    //[转换说明前]加空白字符包括特殊情况作用是匹配输入项时跳过空白字符.
    //scanf格式字符串中,转换说明加普通字符
    //输入时格式要与scanf格式字符串的格式相匹配,
    //才能让scanf函数能够从缓冲区中正确读取数据
    //* 简单说,转换说明前有空白字符(包括无空白字符的特殊情况),
    //  scanf函数读取输入时就会跳过输入到缓冲区的空白字符
    //* 转化说明之间有普通字符,输入时就要输入普通字符与格式字符串匹配
    //例如: scanf("%d,%d");  第一个输入项: 32,
    //输入:(读取时跳过空白字符)整数类型|,逗号|(读取时跳过空白字符)整数类型
    // 注: 第二个%d匹配输入项,后面可以输入空字符,scanf读取第二个整数输入项时,
    // 遇到空白字符,会停止第二个输入项的数据读取,把空字符放回输入缓冲区,下一次读取时从这个空白字符读取 
    printf("input i_sfcs_a(int), i_sfcs_b(int);");
    printf("(%%d : %%d): ");
    scanf("%d : %d", &i_sfcs_c, &i_sfcs_d);
    printf("%d %d\n", i_sfcs_c, i_sfcs_d);
    return;
}

void scanf_conversion_specification_character(void)
{
    int i_a, i_b, i_c, i_d;
    char c_a, c_b;

    printf("input int i_a i_b(%%d%%d):");
    scanf("%d%d", &i_a, &i_b);
    printf("%d,%d\n", i_a, i_b);
    printf("input int i_a i_b(%%d %%d):");
    scanf("%d %d", &i_c, &i_d);
    printf("%d,%d\n", i_c, i_d);
    
    // %c与普通字符情况一样,前面加空白字符的特殊情况(即不加空白字符)
    // 都是不会跳过输入时的空白字符的
    // scanf("%c") 和scanf(" %c")是有区别的 
    // (注: scanf函数的%c是特殊情况,其它转换说明无这种区别)
    // %c读取一个字符,包括回车键生成的换行符
    // 假设执行到上一个scanf函数,我们输入数据,按回车,
    // 生成的换行字符会存入输入缓冲区
    // scanf("%c")会读取这个换行字符
    // scanf(" %c")则可正确读取,不会读取输入缓冲区中的换行字符(ascii码)
    // scanf转换说明前没有空格
    printf("input char c_a(%%c):");
    scanf("%c", &c_a);
    printf("c_a(%%c):%c\n", c_a);
    //换行符ascii码是10,C语言换行符是'\n'
    //空格符(space)ascii码是32
    printf("c_a(%%hhu):%hhu\n", c_a);
    // scanf转换说明前有空格
    printf("input char c_b( %%c):");
    scanf(" %c", &c_b);
    printf("c_b(%%c):%c\n", c_b);
    // 'A' ascii码是65
    // %hhu printf和scanf都有这个转换说明
    // 作用:输出或输入一个一个字节的无符号整数
    printf("c_b(%%hhu):%hhu\n", c_b);
    return;
}

// 总结: %d 转换说明匹配输入项
//       |空白字符前|整数类型数据|空白字符后|
//                 |           |
//跳过空白字符   读取开始     读取结束    读到空白字符后,放回输入缓存区
//程序有下一个scanf函数的话,从放回的空白字符开始读取
//
// scanf 转换说明  例如: scanf("%d"); 和 scanf(" %d"); 是等价的
// scanf格式字符串的空白字符(包括无空白字符的特殊情况)作用是跳过输入缓冲区的空白字符
// %c 是个例外  scanf("%c"); 和 scanf(" %c"); 是不等价的
// scanf格式字符串中的普通字符,输入时要输入相匹配的普通字符,不匹配的话会停止读取
// 普通字符并不会被保存,只有与转换说明相匹配的输入被保存到指定变量
// scanf只有单个转换说明,输入不匹配,scanf会停止读取,程序有下一个scanf的话,下一个scanf继续读取
// scanf如果有多个转换说明,输入不匹配的话,C标准规定程序停止读取,即使后面代码中还有scanf

//void scanf_return_value(void)
//{
//    //scanf返回值为int类型
//    // 转义序列(escape sequence)    
//    // \" 反斜杠后面的字符,不是它ascii字符本来的意思了
//    // " C中原意是字符串符号, \" 转义序列,意思是双引号符号字符本身 
//    // %d 转换说明,转换成整数类型
//    // %% 转换说明,转换成百分号字符本身
//}

// * modifier   *修饰符
// printf("%*d", width, integer);   *表示字段宽度,不想预先指定字段宽度时用*代替
void printf_star_modifier(void)
{
    unsigned int before, after;
    double d_a = 1111111.1111;
    printf("input width before/after decimal point: ");
    scanf("%d %d", &before, &after);
    // %*.*f  第一个*表示浮点数字段宽度,位数不足的填充空格,位数足够或超过的原样输出即可
    //        第二个*表示浮点数小数点后保留位数
    printf("%*.*f\n", before, after, d_a);
    return;
}

void scanf_star_modifier(void)
{
    int ssm_i_a;
    //scanf的*修饰符与printf的*修饰符作用不同
    //scanf("%*d%*d%d", &int);
    //读取输入缓冲区时,跳过前两个输入项,读取和保存第三个输入项到指定变量
    printf("&ssm_i_a(%%*d%%*d%%d): ");
    scanf("%*d%*d%d", &ssm_i_a);
    printf("ssm_i_a(%%d): %d\n", ssm_i_a);
    return;
}

// usage 用法
void usage_tips_for_printf(void)
{
    int utfp_i_a, utfp_i_b, utfp_i_c, utfp_i_d, utfp_i_e, utfp_i_f,\
     utfp_i_g, utfp_i_h, utfp_i_i, utfp_i_j, utfp_i_k, utfp_i_l;
    
    printf("input(%%d %%d %%d %%d %%d %%d): ");
    scanf("%d %d %d %d %d %d",
     &utfp_i_a, &utfp_i_b, &utfp_i_c, &utfp_i_d, &utfp_i_e, &utfp_i_f);
    printf("input(%%d %%d %%d %%d %%d %%d): ");
    scanf("%d %d %d %d %d %d",
     &utfp_i_g, &utfp_i_h, &utfp_i_i, &utfp_i_j, &utfp_i_k, &utfp_i_l);
    
    printf("%d %d %d %d %d %d\n",
     utfp_i_a, utfp_i_b, utfp_i_c, utfp_i_d, utfp_i_e, utfp_i_f);
    printf("%8d %8d %8d %8d %8d %8d\n",
     utfp_i_a, utfp_i_b, utfp_i_c, utfp_i_d, utfp_i_e, utfp_i_f);
    return;
}



