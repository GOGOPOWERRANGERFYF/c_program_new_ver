#include <stdio.h>
int create_array(int index_max);
int array_example1(void);

void main(void){
    create_array(5);
    //array_example1();
    return;
}

// (原型声明里的形参名是可写可不写,且不需与函数定义里的形参名一致)
// 关于函数定义里的返回值在语法上的一点个人推理：
//  应该是跟函数原型声明里的参数一样,只需要知道返回值的类型即可
//  因此int 表示返回值类型为int
//      int *   表示返回值类型为指向int变量的指针类型
//  从语法上按照函数原型声明里的省略形参名的变量声明我就比较能理解为什么这么写了
//  不过说到底还不是别人编译器要怎样你就要怎样,不服去学编译原理,自己写个编译器。。。
int create_array(int index_max){
    int i, index = 0, value = 1, array[index_max];
    int (* array_pointer)[index_max];
    for (i = 0; i < index_max; i++){
        array[index] = value++;
        index++;
    }
    //数组指针知识：
    //  声明数组指针
    //      int (* array_pointer)[index];
    //  array和&array的值虽然是相等的，但它们是不同类型的指针
    //  array为数组第一个元素的指针
    //  &array为数组对象的指针
    //  因此array+1和&array+1两个表达式的求值结果完全不同
    //  第一个表达式的值指向数组的下一个元素
    //  第二个表达式的值是在原地址的基础上加上sizeof(&数组)的存储长度
    //
    //  还有一个指针数组不要搞混:
    //      (int *) array[index];
    //  数组的元素类型为int
    //  声明数组
    //      int array[index];
    //  声明中,int表示元素类型为int
    //  声名中,(int *)表示指向int类型的指针
    //
    //  以上这些其实只要记住了*为间接运算符就很容易理解了
    //  更深层理解的话回忆一下立即寻址，直接寻址，间接寻址的知识点就OK了
    array_pointer = &array;
    for (i = 0; i < index_max; i++){
        printf("array[%d] = %d\n",
         i, array[i]);
    }
    printf("---------------------------------------------------\n");
    for (i = 0; i < index_max; i++){
        printf("array_pointer:%p, array_element_pointer:%p\n",
         &array+i, array+i);
    }
    printf("---------------------------------------------------\n");
    for (i = 0; i < index_max; i++){
        printf("array_pointer:%p, array_element_pointer:%p\n",
         array_pointer+i, array+i);
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
