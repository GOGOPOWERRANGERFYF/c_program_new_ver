#include <stdio.h>
int create_array(int index_max);
int array_example1(void);

void main(void){
    create_array(5);
    //array_example1();
    return;
}

// 《C和指针(第二版)》P158

// (原型声明里的形参名是可写可不写,且不需与函数定义里的形参名一致)
// 关于函数定义里的返回值在语法上的一点个人推理：
//  应该是跟函数原型声明里的参数一样,只需要知道返回值的类型即可
//  因此int 表示返回值类型为int
//      int *   表示返回值类型为指向int变量的指针类型
//  从语法上按照函数原型声明里的省略形参名的变量声明我就比较能理解为什么这么写了
//  不过说到底还不是别人编译器要怎样你就要怎么写,不服去学编译原理,自己写个编译器。。。
//  目前了解到的一点编译原理知识点，正则匹配，语义分析等等等。。。
int create_array(int index_max){
    int index = 0, value = 1, array[index_max];
    int (* array_pointer)[index_max];
    for (index = 0; index < index_max; index++){
        array[index] = value++;
        index++;
    }
    // 指针数组和数组指针的知识：
    //      重要的知识点，[]下标引用的优先级高于*间接访问运算符
    //                  []下标引用运算符结合律：从左往右  
    //                  *间接访问运算符结合律：从右往左       (*运算对象,先取运算对象,再通过运算对象的值进行寻址)
    //      声明指针数组： 
    //          int * p[5]
    //          这个声明作为一个表达式,我们来对它进行求值。
    //          []下标引用运算符优先级高于*间接访问运算符,所以运算对象p与[]下标引用运算符结合进行运算
    //          执行下标引用,因此p是某种类型的数组,
    //          注意,数组声明中的5代表的是元素个数,而不是访问/引用数组的第5个元素,p为一个能储存5个某种类型元素的数组
    //          然后*间接访问运算符与子表达式的值(值为访问数组元素)结合进行运算,运算结果为间接通过数组元素访问
    //          此时表达式已经没有其他操作符,根据关键字得知,间接通过数组元素访问操作得到的值为int类型,所以这是一个int类型指针数组
    //          (简而言之就是间接通过数组元素的值进行寻址,访问数组元素指向的数据,所以数组元素为指针,这是一个指针数组)
    //        
    //      声明数组指针:
    //          int (* array_pointer)[index];
    //      对表达式进行分析,间接访问运算符与运算对象先进行结合运算,表示表示运算对象是个指针,但这个指针指向什么呢?           
    //      接下来执行下标引用,有下标引用说明指针是指向某种类型的数组,没有其他操作符,根据关键字int得知下标引用访问的是一个int类型值
    //      说明这是一个int类型数组,array_pointer为int类型数组的指针(&数组名)
    //            
    //      
    //      array和&array的值虽然是相等的，但它们是不同类型的指针
    //      array为数组第一个元素的指针
    //      &array为数组对象的指针
    //      因此array+1和&array+1两个表达式的求值结果完全不同
    //      第一个表达式的值指向数组的下一个元素
    //      第二个表达式的值是在原地址的基础上加上sizeof(&数组)的存储长度
    //
    //      还有一个指针数组不要搞混,
    //      指针数组就是间接通过数组的元素访问数据,所以元素必为某数据类型的指针:
    //          int * array[index]; 
    //      数组的元素类型为int类型指针
    //
    //      声明数组
    //          int array[index];
    //      声明中,int表示元素类型为int
    //      array为数组第一个元素的指针；   array等于&array[0]
    //      &array为整个数组的指针
    //
    //      以上这些其实只要记住了*为间接运算符就很容易理解了
    //      更深层理解的话回忆一下立即寻址，直接寻址，间接寻址的知识点就OK了
    array_pointer = &array;
    for (index = 0; index < index_max; index++){
        printf("array[%d] = %d\n",
         index, array[index]);
    }
    printf("---------------------------------------------------\n");
    for (index = 0; index < index_max; index++){
        printf("array_pointer:%p, array_element_pointer:%p\n",
         &array+index, array+index);
    }
    printf("---------------------------------------------------\n");
    for (index = 0; index < index_max; index++){
        printf("array_pointer:%p, array_element_pointer:%p\n",
         array_pointer+index, array+index);
    }
    printf("---------------------------------------------------\n");
    printf("&array:%zd\n", sizeof(*&array));
    // 数组可以通过malloc(sizeof(int)*index)实现的
    return 0;
}

int array_example1(void){
    // 数组声明里的下标为元素个数，太久不写C了犯这种低级错误。。。
    int array[3] = {3, 5, 8};
    // 下面的声明为声明一个3个int类型元素的指针,所以赋值的时候是赋值一个该类型的数组指针
    // 重点：记住这是数组指针变量，不是数组啊。。。
    int (* array_pointer)[3] = &array;
    printf("sizeof(*array): %zd\n", sizeof(*array));
    printf("*array,the first element of array: %d\n", *array);
    printf("sizeof(*&array): %zd\n", sizeof(*&array));
    printf("sizeof(*array_pointer): %zd\n", sizeof(*array_pointer));
    printf("array_pointer(%%p):%p\narray_pointer+1(%%p):%p\n", array_pointer, array_pointer+1);
    printf("&array[2](%%p)%p\n", &array[2]);
    return 0;
}
