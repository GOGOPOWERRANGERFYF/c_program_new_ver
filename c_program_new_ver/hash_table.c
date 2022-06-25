#include <stdio.h>
#include <stdlib.h>
#define NULL_CHAR '\0'
// 不完整的结构声明(结构声明前置)
struct valuenode;
struct valuenode * keyArrayInitial(unsigned long int index);
int hashFunction(char *cp, char (*cap)[]);
int printAttribute(char *cp, char (*cap)[]);

// 结构声明
typedef struct valuenode {
    // 这里还不能使用别名,编译器还没读取到别名的代码
    // struct valuenode 声明结构类型变量
    struct valuenode *vp;
    char *char_pointer;
} valuenode;
//之后可以使用valuenode结构类型别名进行声明

int main(void) {
    char hash_array[] = "color";
    char *cp = hash_array, (*cap)[] = &hash_array;
    //hashFunction(cp, cap);
    keyArrayInitial(5LU);
    return 0;
}

// 根据C的声明语法,标识符先与圆括号结合,表示是一个函数,
// 函数的值为返回值,返回值与*结合指向一个对象,表示返回值为一个指针,
// 与类型说明符结合,说明了指针指向的值(对象)的类型,也表明了指向该对象的指针的类型
valuenode * keyArrayInitial(unsigned long int index) {
    valuenode *valuenode_pointer = NULL, valuenode_array[index], value;
    value.char_pointer = "hello world";
    printf("%c\n", *value.char_pointer);
    printf("%c\n", *"hello world");
    printf("%c\n", *("hello world" + 1));
    return valuenode_pointer;
}

int hashFunction(char *cp, char (*cap)[]) {
    int i;
    unsigned long int uli_temp = 0UL, result;
    // cp[i]必须等于'\0'才符合测试条件,'\0'为第5个元素,数组下标i为4.
    for (i = 0; cp[i] != NULL_CHAR; i++) {
        //uli_temp = uli_temp + cp[i];
        uli_temp += cp[i];
    }
    printf("length of string(exclude null character): %d\n", i);
    result = uli_temp % i;
    printAttribute(cp, cap);
    printf("sum of chars:%lu; key=>hash: %lu;\n", uli_temp, result);
    return 0;
}

int printAttribute(char *cp, char (*cap)[]) {
    int i;
    printf("attribute:");
    for (i = 0; cp[i] != NULL_CHAR; i++) {
        printf("%c", cp[i]);
    }
    printf("; ");
    return 0;
}

/*
hash table(哈希表/散列表):
 "属性名"(string) ==> key%x(例如:array_length)=key ==> array[key]值为指针 ==> 属性值(C语言实现:malloc分配内存创建链表节点)
        index:key     array[key]    value    p          value    p    (p:pointer)
                        +---+     +--------+---+      +--------+---+
            [key]       | p | --> |        |   | -->  |        |   |         冲突()
                        +---+     +--------+---+      +--------+---+
                        |   |
                        +---+
                        |   |
                        +---+
                        |   |      值为指针(引用)
                        +---+     +--------+---+
                        |   | --> |value=p |   |   键值对的值为指针
                        +---+     +--------+---+
                        |   |                 
                        +---+     +--------+---+
                        |   | --> |value   |   |
                        +---+     +--------+---+
                        |   |
                        +---+
 "属性名" ascii/unicode编码相加,在经过算法(例如 % mod 模除)的到key数组的[索引]。
*/
/*
    《大话数据结构》
    哈希表/散列表 (连续数组)
        每个关键字key对应一个存储位置f(key),这种对应关系f称为散列函数,又称为哈希(hash)函数.
        散列函数将记录存储在一块连续的存储空间中,这块连续存储空间称为散列表或哈希表(hash table),
        关键字对应的记录存储位置称为散列地址。
        f(key1) = f(key2) 称为冲突(collision)
        key1和key2称为这个散列函数的同义词(synonym)

    散列函数的构造方法:
    除留余数法(只是其中一种)
        f(key) = key mod p (p<=m) m为散列表长度

    链地址法   
        讲所有关键字为同义词的记录存储在一个单链表中,称为同义词子表。
        散列表中只存储所有同义词子表的头指针。
*/

