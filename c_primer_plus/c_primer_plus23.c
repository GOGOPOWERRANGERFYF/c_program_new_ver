// 第十章 数组和指针
// 这里为《c primer plus 第6版 中文版》学习笔记,
//  另外有array_pointer.c文件内容作为个人补充 (20211008)
#include <stdio.h>
#include <unistd.h>
//#include <windows.h>
#define SIZE 10
void array_a(void);
void designated_initializer(void);
void array_element_assignment(void);
void array_size(void);
void multidimensional_array_1(void);
void multidimensional_array_2(void);
void pointer_and_array(void);

void pointer_parameter();

// 等价函数原型:
// 函数原型可省略形参名
//void pointer_parameter_a(int *, int);
//void pointer_parameter_b(int [], int);
void pointer_parameter_a(int * array, int n);
void pointer_parameter_b(int array[], int n);

void use_pointer_parameter(int * start, int * end);

void main(void){
    int array[2] = {1, 12}, array1[5] = {1, 2, 3, 4, 5};
    //array_a();
    //designated_initializer();
    //array_element_assignment();
    //multidimensional_array_1();
    //multidimensional_array_2();
    //pointer_and_array();
    //pointer_parameter_a(array, 2);
    //pointer_parameter_b(array, 2);
    use_pointer_parameter(array1, array1 + 5);
    return;
}

void array_a(void){
    // 只存储单个值的变量有时也称标量变量(scalar variable)
    int i1 = 1;

    const int birthday[3] = {1987,11,9};
    // 从ANSI C开始支持这种初始化,
    // 不支持ANSI的编译器需要在数组声明前加static
    // 逗号分隔的值列表
    int array1[5] = {2,4,6,8,10};
    int array2[5];
    // 初始化列表的元素个数少于数组元素个数时,编译器会把剩余的元素初始化为0
    // 初始化列表的元素个数多于数组元素个数时,编译器会把提示错误
    int array3[5] = {2,4};
    // 让编译器自动匹配数组元素个数并初始化
    int array_auto1[] = {1,2,3,4,5,6,7,8};

    // storage class存储类别
    // 数组与其他变量类似,可以把数组创建成不同存储类别
    // 第十二章将介绍存储类别的相关内容
    // 自动存储类别: 数组在函数内部声明,且声明没有使用static关键字
    // 变量和数组不同的存储类别有不同的属性

    // 自动存储类别数组使用前需要赋初值,如果没有赋值,
    // 编译器使用的值是内存相应位置的现有值.

    // 对于其他一些存储类别的变量和数组,如果声明时未初始化
    // 编译器会把它们的值设置为0
    // 如果是自动存储类别,数组的值是随机变动的(所以static为静止的固定值为0)
    printf("array2[0]: %d\n", array2[0]);
    printf("array3[0]: %d\n", array3[3]);
    printf("array_auto1[0]: %d\n", array_auto1[7]);
    // size 大小,尺码 printf("array size of array2: %d bytes\n", sizeof(array2));
    return;
}

// designated 指定;指明
// initializer 初始值;初始化程序
// designated initializer 指定初始化器 (C99标准)
// 指定初始化的元素
void designated_initializer(void){
    int array1[5] = {[4]=15};
    // 声明数组后,可以借助数组下标subscript(索引index)给数组元素赋值
    int array2[2];
    array2[1] = 5;

    printf("%d\n", array1[4]);
    printf("%d\n", array2[1]);
    return;
}

// 10.1.3 给数组元素赋值
void array_element_assignment(void){
    // c不允许把数组作为一个单元赋给另一个数组 
    int array1[5];
    int i;
    // 花括号初始化列表 只能在数组初始化时使用,声明之后是没有办法使用的
    // error错误: array1[5] = {1,2,3,4,5};
    // error错误: array1 = {1,2,3,4,5};
    // array1[5] = 1; 数组下标越界
    // array1数组的最后一个元素array1[5-1]
    for (i = 0; i < 5; i++){
        array1[i] = 2 * i;
        printf("array1[%d]: %d\n", i, array1[i]);
    }
    return;
}
// 在C标准中,使用越界下标的结果是未定义的
// 编译器是不会检查使用的数组下标是否越界的
// 程序可以编译运行,但运行结果会很奇怪,或异常中止

void array_size(void){
    int i, j;

    // symbolic integer constant 符号整数常量
    int array1[SIZE];
    // literal integer constant 字面整数常量 
    float array2[10];

    // C99标准之前,声明数组时只能在中括号中使用整型常量表达式
    // 所谓整型常量表达式,就是由整型常量构成的表达式
    //  int n; 
    //  float f;
    //  int array1[n]; 
    //  int array2[n+1];
    //  int array3[2*n+1];
    //  int array4[(int)f];
    // sizeof表达式被视为整型表达式
    // 但const(关键字,限制变量为只读)值不是,与c++不同
    // 另外,整型表达式的值必须大于0
    // 错误代码示范:
    //      int array[-1];
    //      int array[0];
    //      int array[2.5];

    // 变长数组(variable-length array) C99标准
    // 我觉得翻译成 变量长度数组 对我来说能更好理解
    // C11标准又把把变长数组设定为可选,不是语言必备特性 额。。。真能折腾。。。
    // 声明VLA时不能进行初始化
    int array3[i], array4[j];
    return;
}

// 10.2 多维数组
void multidimensional_array_1(void){
    unsigned int i, j;
    // 主数组(master array)有5个元素
    // 每个元素是一个包含12个元素的数组
    int data1[2][12] =
    {
        {1,2,3,4,5,6,7,8,9,10,11,12},
        {13,14,15,16,17,18,19,20,21,22,23,24}
    };
    float data2[3][12];
    //printf("%d\n", data1[1][11]);
    //printf("%d\n", data1[2][10]);
    for (i = 0; i < 2; i++){
        for (j = 0; j < 12; j++){
            sleep(2);
            printf("data1[%2u][%2u]:%3d;\n", i, j, data1[i][j]);
        }
        printf("\n");
    }
    return;
}

void multidimensional_array_2(void){
    static float total_horizon, total_vertical,
     total_of_array_element, average_of_array_element,
     total_of_array_element_of_element, average_of_array_element_of_element;
    unsigned int i, j;
    // float data1[2] 一维数组
    // {1,2,3,4,5,6,7,8,9,10,11,12} 数值列表
    // 初始化二维数组(two-dimensional array)
    float data1[2][12] =
    {
        // 数组元素个数不匹配问题与一维数组一致
        // 数组元素是数组的,单个数值列表的数值个数不匹配问题与一维数组一致
        {1,2,3,4,5,6,7,8,9,10,11,12},
        {13,14,15,16,17,18,19,20,21,22,23,24}
        // 内部花括号可以省略,只要保证初始化的数值个数正确即可
        // 省略内部花括号的数值列表发生数值个数与数组大小(长度)不匹配的情况
        // 与一维数组一致
    };

    printf("static variable total_of_array_element = %.2f; average_of_array_element = %.2f\n\n",
     total_of_array_element, average_of_array_element);

    for (i = 0; i < 2; i++){
        for (j = 0, total_of_array_element = 0; j < 12; j++){
            total_of_array_element += data1[i][j];
        }
        total_horizon += total_of_array_element;
        printf("total_of_array_element[%d]: %.2f; ", i, total_of_array_element);
        printf("average_of_array_element[%d]: %.2f\n", i, total_of_array_element / j);
    }
    
    for (j = 0; j < 12; j++){
        for (i = 0, total_of_array_element_of_element = 0; i < 2; i++){
            total_of_array_element_of_element += data1[i][j];
        }
        total_vertical += total_of_array_element_of_element;
        printf("total_of_array_element_of_element[i][%d]: %.2f; ",
         j, total_of_array_element_of_element);
        printf("average_of_array_element_of_element[i][%d]: %.2f\n",
         j, total_of_array_element_of_element / i);
    }

    printf("\ntotal_horizon: %.2f; total_vertical: %.2f\n",
     total_horizon, total_vertical);
    return;
}
// 其他多为数组,例如三维数组 float array[x][y][z],
// 按照二维数组类推即可,包括四维数组,五维数组等...

// 指针和数组
// 数组表示法其实是在变相使用指针
// 数组名是数组首元素的地址
void pointer_and_array(void){
    char c;
    short int si;
    int a;
    // 指针变量未初始化之前为野指针(wild pointer)
    // 指针变量未初始化,其值是随机的
    int * p1, * p2;
    char char_array1[3];
    int array1[3];
    //printf("wild pointer p1/p2: %p, %p.\n", p1, p2);

    // 没有布尔类型的转换说明
    // array1和&array1[0]两者都是常量,程序运行过程中不会改变
    // array1 = &a; 无法赋值,编译器会报错,因此在程序运行过程中它是constant常量
    // 但程序下一次运行时地址会改变

    // 可以把它们(就跟地址常量一样)赋给指针变量
    p1 = array1;
    p2 = &array1[0];

    printf("array1 == &array1[0]?: %s\n", array1 == &array1[0] ? "true" : "false");
    printf("array1(virtual address): %p\n", array1);
    printf("&array1(virtual address): %p\n", &array1[0]);
    // 数组的地址就是数组首元素的地址
    printf("&c: %p; &c + 1: %p\n", &c, &c + 1);
    printf("&si: %p; &si + 1: %p\n", &si, &si + 1);

    // 在系统中,地址是按字节编址的(虚拟地址)
    // 在C中,指针+1指的是增加一个存储单元(指针指向下一个存储单元)
    // 在数组中,+1后就是下一个元素的地址
    // 这就是指针变量必须声明所指向对象类型的原因之一
    // 因为只知道存储对象地址是不够的,计算机需要知道对象的存储需要多少个字节
    // 指针指向标量变量和数组都要知道变量的类型,不然无法正确取回地址上的值
    printf("&char_array1[0]: %p\n&char_array1[1]: %p\n&char_array1[2]: %p\n",
     &char_array1[0], &char_array1[1], &char_array1[2]);
    printf("&array1[0]: %p\n&array1[1]: %p\n&array1[2]: %p\n",
     &array1[0], &array1[1], &array1[2]);
    // 指针的值是它所指向数据对象的地址
    // 在指针前面使用*运算符(间接运算符)可以得到该指针所指向数据对象的值
    // 指针加1,指针的值递增它所指向数据对象类型的大小(以字节byte为单位)
    // 数组与指针的关系十分密切
    // 可以使用指针标识数组元素和获得数组元素的值
    printf("array1 == &array1[0]: %s\n", array1 == &array1[0] ? "true" : "false");
    printf("array1 + 1 == &array1[0 + 1]: %s\n", array1 + 1 == &array1[0 + 1] ? "true" : "false");
    printf("*array1 == array1[0]: %s\n", *array1 == array1[0] ? "true" : "false");
    printf("*(array1 + 1) == array1[0 + 1]: %s\n", *(array1 + 1) == array1[0 + 1] ? "true" : "false");

    // 间接运算符*(一元运算符)优先级高于算术运算符+ - * /
    // *array + 1 不等于 *(array + 1)
    // *array + 1 等于数组首元素的值加1 *(&array[0]) + 1
    // *(array + 1) 到array的内存地址,然后移动一个array元素数据类型的大小(存储空间大小)
    //  再获取移动后的地址所存储的值

    // 数组表示法 array notation    array[index]
    // 指针表示法 pointer notation  *(array + index)
    // 指针表示法和数组表示法是两种等效的方法
    return;
}

// 函数原型的形参可以省略参数名(假名),也可以与函数定义头的形参名不同
void pointer_parameter(){
    // 下面的array编译器会报错,数组和指针类型冲突
    // int * array;
    // int array[] = {1, 2};
    // 数组和指针并不相同
    return;
}

// 下面两种函数定义等价
void pointer_parameter_a(int * array, int n){
    // int * array和int array[]在函数原型和函数定义的函数头里
    // 才可以用int array[]替换int * array
    // 在函数原型和函数头里作为形参这两个是等价的,可以互相替换
    // 相当于知道数组首元素地址但不知道数组长度
    printf("pointer variable array: %p\n", array);
    printf(" *array: %d;  *(array + 1): %d\n", *array, *(array + 1));
    return;
}
// 利用C中数组和指针的特殊关系,用数组表示法来表示
// 指针array,main函数中array数组的数组名,为首元素指针,为常量,程序运行时不能修改
void pointer_parameter_b(int array[], int n){
    printf("(array first element adress: array name -> array: %p\n", array);
    printf(" *array[0]: %d;  array[1] %d\n", array[0], array[1]);
    // gcc -w 忽略警告 下面的输出语句编译器会警告
    // array数组名为数组首元素的地址,是指针
    //下面的sizeof不完整类型数组编译器会警告,
    //不完整类型数组未初始化前数组元素个数并不确定
    //printf("sizeof(array): %zd\n", sizeof(array));
    // %zd sizeof()的转换说明,如果编译器不支持,可以用%u或%lu代替
    return;
}

// segmentation fault
// 一种特殊的错误:访问了未分配给C程序的内存位置(不允许访问的,不合法的)
// 算法知识点: 
//  指向数组的指针意义重大,特别时非常大的数组时
//  把一个指向数组的指针作为实参传递给函数,从而使函数不用复制整个
//  数组就能访问数组中的对象

// 10.4.1 使用指针形参
// 函数原型可以省略形参名,函数定义的函数头不可以省略
// 函数处理数组的两种方式:
//  1. 知道数组在哪里开始,数组元素个数: void func(int * start, int array_size)
//      用int变量array_size来结束循环
//  2. 知道数组在哪里开始,在哪里结束: void func(int * start, int * end)
//      用指针end来结束循环
void use_pointer_parameter(int * start, int * end){
    //用第二个指针end来结束循环
    //测试条件用的是关系运算符<
    //所以循环所处理的最后一个数组元素是end指针指向地址的前一个元素
    //C保证给数组分配空间时,指向数组最后一个元素的后面的第一个指针仍是有效指针
    //虽然C保证了该指针的有效,但对该地址上的值未作保证,因此程序不能访问该位置
    while (start < end){
        printf("*formal parameter --> *start: %d\n", *start);
        //int类型指针变量start递增,递增一个int类型的大小(长度)
        //使指针指向int类型数组的下一个元素
        start++;
        // 一元运算符*和++优先级相同,结合律从右往左
        // int sum;
        //         <------
        //        操作数先与++结合
        // sum += *start++;         等价于*(start++)
        //        操作数先与++结合
        //        *++start
        //        操作数先与*结合
        //        ++*start
        //        操作数先与*结合
        //        (*start)++
        // P679
    }
    return;
}

// 不完整类型(incomplete type): 
// 描述标识符但缺少标识符大小信息的类型
//  例如: 尚未指定其维度的数组类型 array[]
//  此外还有: 未指定成员的结构(structrue)类型和联合(union)类型

// 10.7 指针和多维数组
//      int a[5][2];    声明一个数组,数组有5个元素,元素为内含两个元素的int类型数组