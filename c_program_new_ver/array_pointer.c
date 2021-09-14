#include <stdio.h>
int create_array(int index_max);
int array_example1(void);

void main(void){
    //create_array(5);
    array_example1();
    return;
}

int create_array(int index_max){
    int i, index = 0, value = 1, array[index_max];
    int (* array_pointer)[index_max];
    for (i = 0; i <= index_max; i++){
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
    for (i = 0; i <= index_max; i++){
        printf("array[%d] = %d\n",
         i, array[i]);
    }
    printf("---------------------------------------------------\n");
    for (i = 0; i <= index_max; i++){
        printf("array_pointer:%p, array_element_pointer:%p\n",
         &array+i, array+i);
    }
    printf("---------------------------------------------------\n");
    for (i = 0; i <= index_max; i++){
        printf("array_pointer:%p, array_element_pointer:%p\n",
         array_pointer+i, array+i);
    }
    printf("---------------------------------------------------\n");
    printf("&array:%zd\n", sizeof(*&array));
    // 由以上输出发现：&array+1表达式的值为数组最后一个元素的指针/地址
    // 个人推理，之所以指向数组的最后一个元素，而不是指向最后一个元素的后继元素
    // 后继元素的指针已经数组越界了
    // 数组可以通过malloc(sizeof(int)*index)实现的
    return 0;
}

int array_example1(void){
    int array[3] = {3, 5, 8};
    // 数组声明里的下标为元素个数，太久不写C了犯这种低级错误。。。
    // 下面的声明为声明一个3个int类型元素的指针,所以赋值的时候是赋值一个该类型的数组指针
    int (* array_pointer)[3] = &array;
    printf("%zd\n", sizeof(*array));
    printf("%zd\n", sizeof(*&array));
    printf("%zd\n", sizeof(*array_pointer));
    return 0;
}
