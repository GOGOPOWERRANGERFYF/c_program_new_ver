#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    char s_char;
    int s_int;
    struct node * s_p;
} node;

node * single_linked_list_init(void);
node * head_single_linked_list_create(void);
//node * single_linked_list_create_head(void);
//node * single_linked_list_create_tail(void);
node * single_linked_list_node_insert(node * singl_linked_list_pointer);
node * single_linked_list_node_delete(node * single_linked_node_pointer);
void single_linked_list_print(node * singl_linked_list_pointer);
node * single_linked_list_node_modify(node * single_linked_list_pointer);

// 无效内存的内存引用(段故障) SIGSEGV   signal segmentation
// 《深入理解计算机系统第三版》8.5信号
// 不...最新发现...就是连续scanf()读取输入缓冲区的问题
int main(void){
    node * temp_node_pointer;
    temp_node_pointer = head_single_linked_list_create();
    single_linked_list_print(temp_node_pointer);
    single_linked_list_node_insert(temp_node_pointer);
    single_linked_list_node_delete(temp_node_pointer);
    single_linked_list_node_modify(temp_node_pointer);
    return 0;
}

node * single_linked_list_init(void){
    node * header_node_pointer;
    header_node_pointer = (node *)malloc(sizeof(node));
    if (header_node_pointer == NULL){
        printf("memory allocaiton failed\n");
    }
    return header_node_pointer;
}

//头插法创建单链表
//  理论/原理:
//             node[1]
//          |数据域|指针域|
//                | 插入
//     header     V     node[2]         node[3]         node[4]
// |数据域|指针域|-->|数据域|指针域|-->|数据域|指针域|-->|数据域|指针域|-->NULL
//     
//硬件层面:
//heap(堆区):由低地址到高地址分配
//注意:node[3]先在堆区中分配
//  内存:
//  low address      --------------------->         high address
//                                      ____________________
//                        _____________|____                |
//                       |             |    |               |
//                       V             V    |               |
//                     node[3]      node[2] |               |
// |数据域|指针域|  |数据域|指针域|  |数据域|指针域|  |数据域|指针域|
//          |              |                            node[1]
//          |              |                              ^
//          |______________|______________________________|
//                         |
//                         V
//                        NULL
//  低地址--->高地址
//  内存:堆区heap
//  header|
//  header|node[1]|
//  header|node[2]|node[1]|
//  header|node[3]|node[2]|node[1]|
//*理解和记忆的技巧:头节点始终指向最新进入堆区的节点
//
// 写代码时话当然还是从理论角度思考啦...
//
//头插法,头节点的指针成员指向最后插入的节点
//个人心得:
//  malloc()申请内存部分区域的访问许可
//  (node *)强制类型转换,本质目的:知道如何正确存储和读取在内存区域的数据
//再加点个人推测:
//  源代码编译成机器代码,采取直接或间接寻址,推测个鬼啊...
//  当然直接上gdb具体问题具体分析啊...靠空想能想出来的吗~
//  测nm个头,傻不傻啊...
node * head_single_linked_list_create(void){
    //创建表头
    printf("single linked list create, method: head insert\n");
    node * root_node_pointer;
    root_node_pointer = (node *)malloc(sizeof(node));
    if (root_node_pointer == NULL){
        printf("memory allocation failed! header node pointer: %p\n", root_node_pointer);
        return root_node_pointer;
    }
    root_node_pointer->s_p = NULL;
    printf("memory allocation success, header node pointer: %p\n", root_node_pointer);

    //创建节点
    char temp_char;
    int temp_int;
    //printf("input value of char & int variables:\t\b\b\b");
    printf("input value of char & int variables (type 'q' to finish create):\n");
    //while (scanf(" %c %d", &temp_char, &temp_int) != EOF){
    while (scanf(" %c %d", &temp_char, &temp_int) == 2){
        char c_temp;
        if ((c_temp = getchar()) != '\n'){
            node * new_node_pointer;
            new_node_pointer = (node *)malloc(sizeof(node));
            if (new_node_pointer == NULL){
                printf("memory allocation failed! new node pointer: %p\n", new_node_pointer);
                return root_node_pointer;
            }
            printf("memory allocation success, new node pointer: %p\n", new_node_pointer);
            new_node_pointer->s_p = root_node_pointer->s_p;
            root_node_pointer->s_p = new_node_pointer;
            new_node_pointer->s_char = temp_char;
            new_node_pointer->s_int = temp_int;
            //关键:函数结束
            return root_node_pointer;
        }
        node * new_node_pointer;
        new_node_pointer = (node *)malloc(sizeof(node));
        if (new_node_pointer == NULL){
            printf("memory allocation failed! new node pointer: %p\n", new_node_pointer);
            return root_node_pointer;
        }
        printf("memory allocation success, new node pointer: %p\n", new_node_pointer);
        new_node_pointer->s_p = root_node_pointer->s_p;
        root_node_pointer->s_p = new_node_pointer;
        new_node_pointer->s_char = temp_char;
        new_node_pointer->s_int = temp_int;
    }
    return root_node_pointer;
}

//node * single_linked_list_create_head(void){
//    node * header_node_pointer;
//    header_node_pointer = (node *)malloc(sizeof(node));
//    header_node_pointer->s_p =NULL;
//
//    char char_var_temp;
//    int int_var_temp;
//    while (scanf(" %c %d", &char_var_temp, &int_var_temp) != EOF){
//        node * new_node_pointer;
//        new_node_pointer = (node *)malloc(sizeof(node));
//
//        //数据域(结构变量“数据"成员)
//        new_node_pointer->s_char = char_var_temp;
//        new_node_pointer->s_int = int_var_temp;
//
//        //指针域(结构变量“链/指针"成员)
//        //new_node_pointer->s_p = NULL;
//        new_node_pointer->s_p = header_node_pointer->s_p;
//        header_node_pointer->s_p = new_node_pointer;
//    };
//    return header_node_pointer;
//}

//node * single_linked_list_create_tail(void){
//    //*间接运算符,对操作数(指针)进行间接运算,访问node结构类型变量
//    node * header_node_pointer, * move_node_pointer;
//    header_node_pointer = (node *)malloc(sizeof(node));
//    header_node_pointer->s_p = NULL;
//    move_node_pointer = header_node_pointer;
//
//    char char_var_temp;
//    int int_var_temp;
//    while (scanf(" %c %d", &char_var_temp, &int_var_temp) != EOF){
//        node * new_node_pointer;
//        new_node_pointer = (node *)malloc(sizeof(node));
//        move_node_pointer = new_node_pointer;
//
//        new_node_pointer->s_char = char_var_temp;
//        new_node_pointer->s_int = int_var_temp;
//
//        new_node_pointer->s_p = header_node_pointer->s_p;
//        header_node_pointer->s_p = new_node_pointer;
//        move_node_pointer = new_node_pointer;
//    }
//    return header_node_pointer;
//    //return move_node_pointer;
//}

//重点:通过move_node_pointer移动指针变量遍历链表
//思路:
//插入一个新节点到单链表的第i个位置,通过移动指针遍历到第i-1个节点进行插入
//头插法,新插入节点变成第i个节点
//i从0开始,表头为0,
node * single_linked_list_node_insert(node * single_linked_node_pointer){
    printf("input insert node position, node menbers(int_position char int):\n");
    char insert_node_member_char, temp_char;
    int insert_node_member_int;
    unsigned long int node_index, insert_position;
    node * move_node_pointer;

    //读取(头插法)单链表创建函数的输入缓存残余
    temp_char = getchar();
    temp_char = getchar();
    while (scanf("%lu %c %d", &insert_position, &insert_node_member_char, &insert_node_member_int) == 3){
        if ((temp_char = getchar()) != '\n'){
            //每插入一个新节点,初始化一个新节点
            move_node_pointer = single_linked_node_pointer;
            //移动指针指向第i-1个节点,第i个节点的前一个
            for (node_index = 1; node_index < insert_position; node_index++){
                move_node_pointer = move_node_pointer->s_p;
            }
            node * insert_node_pointer;
            insert_node_pointer = (node *)malloc(sizeof(node));    
            if (insert_node_pointer == NULL){
                printf("memory allocation failed! insert node pointer: %p\n", &insert_node_pointer);
                return single_linked_node_pointer;
            }
            printf("memory allocation success! insert node pointer: %p\n", &insert_node_pointer);
            insert_node_pointer->s_char = insert_node_member_char;
            insert_node_pointer->s_int = insert_node_member_int;
            insert_node_pointer->s_p = move_node_pointer->s_p;
            move_node_pointer->s_p = insert_node_pointer;
            printf("--->the last insert node\n");
            single_linked_list_print(single_linked_node_pointer);
            //关键:结束函数
            return single_linked_node_pointer;
        }

        //每插入一个新节点,初始化一个新节点
        move_node_pointer = single_linked_node_pointer;
        //读取到q指令前
        //移动指针指向第i-1个节点,第i个节点的前一个
        for (node_index = 1; node_index < insert_position; node_index++){
            move_node_pointer = move_node_pointer->s_p;
        }
        node * insert_node_pointer;
        insert_node_pointer = (node *)malloc(sizeof(node));    
        if (insert_node_pointer == NULL){
            printf("memory allocation failed! insert node pointer: %p\n", &insert_node_pointer);
            return single_linked_node_pointer;
        }
        printf("memory allocation success! insert node pointer: %p\n", &insert_node_pointer);
        insert_node_pointer->s_char = insert_node_member_char;
        insert_node_pointer->s_int = insert_node_member_int;
        insert_node_pointer->s_p = move_node_pointer->s_p;
        move_node_pointer->s_p = insert_node_pointer;
        single_linked_list_print(single_linked_node_pointer);
    }
    //root_node_pointer
    return single_linked_node_pointer;
}

node * single_linked_list_node_delete(node * single_linked_node_pointer){
    printf("delete the node, input the node index:\n");
    char temp_char;
    unsigned long int node_index, delete_node_index;
    node * move_previous_node_pointer, * move_current_node_pointer;
    //读取接受输入缓冲区残余
    temp_char = getchar();
    temp_char = getchar();
    while (scanf("%lu", &delete_node_index)){
        //检测到输入缓冲区的结束指令(非'\n'字符...)
        if ((temp_char = getchar()) != '\n'){
            move_previous_node_pointer = single_linked_node_pointer;
            move_current_node_pointer = single_linked_node_pointer;
            for (node_index = 1; node_index < delete_node_index; node_index++){
                move_previous_node_pointer = move_previous_node_pointer->s_p;
            }
            for (node_index = 1; node_index <= delete_node_index; node_index++){
                move_current_node_pointer = move_current_node_pointer->s_p;
            }
            move_previous_node_pointer->s_p = move_current_node_pointer->s_p;
            printf("--->the last delete node: %p\n", move_current_node_pointer);
            free(move_current_node_pointer);
            single_linked_list_print(single_linked_node_pointer);
            return single_linked_node_pointer;
        }

        move_previous_node_pointer = single_linked_node_pointer;
        move_current_node_pointer = single_linked_node_pointer;
        for (node_index = 1; node_index < delete_node_index; node_index++){
            move_previous_node_pointer = move_previous_node_pointer->s_p;
        }
        for (node_index = 1; node_index <= delete_node_index; node_index++){
            move_current_node_pointer = move_current_node_pointer->s_p;
        }
        move_previous_node_pointer->s_p = move_current_node_pointer->s_p;
        printf("delete the node: %p\n", move_current_node_pointer);
        free(move_current_node_pointer);
        single_linked_list_print(single_linked_node_pointer);
    }
    return single_linked_node_pointer;
}

void single_linked_list_print(node * single_linked_list_pointer){
    printf("single linked list print:\n");
    node * move_node_pointer;
    unsigned long int list_node_index = 0;
    //指向第一个节点的指针
    move_node_pointer = single_linked_list_pointer->s_p;
    //遍历单链表,移动指针指向当前节点
    //循环测试条件,移动结构指针变量值为空,循环结束
    //移动结构指针变量的值从表头指针到空指针
    while (move_node_pointer){
    //move_node_pointer为真(0为真,非0为假,NULL源代码约定为0),执行循环体内的语句
    //while (move_node_pointer != 0){
    //while (move_node_pointer != NULL){
        printf("node pointer: %p node[%d] = {%c, %d}\n",
          move_node_pointer, ++list_node_index,
         move_node_pointer->s_char, move_node_pointer->s_int);
        move_node_pointer = move_node_pointer->s_p;
    }
    return;
}

//待完善函数
node * single_linked_list_node_modify(node * single_linked_list_pointer){
    char node_member_char, temp_char;
    int node_member_int;
    unsigned long int node_index, modify_node_index;
    node * move_node_pointer;
    temp_char = getchar();
    temp_char = getchar();
    // enter键,输入加载进输入缓冲区
    // enter键,linux '/n'
    // enter键,windows '/r/n'
    printf("modify the node, input(node_index m_char m_int):\n");
    while (scanf("%lu %c %d", &modify_node_index, &node_member_char, &node_member_int) == 3){
        //移动指针指向头节点
        move_node_pointer = single_linked_list_pointer;
        if ((temp_char = getchar()) != '\n'){
            for (node_index = 1; node_index <= modify_node_index; node_index++){
                //移动指针指向下一个节点
                move_node_pointer = move_node_pointer->s_p;
            }
            move_node_pointer->s_char = node_member_char;
            move_node_pointer->s_int = node_member_int;
            single_linked_list_print(single_linked_list_pointer);
            return single_linked_list_pointer;
        }
        //遍历节点,从节点[1]开始
        for (node_index = 1; node_index <= modify_node_index; node_index++){
            //移动指针指向下一个节点
            move_node_pointer = move_node_pointer->s_p;
        }
        move_node_pointer->s_char = node_member_char;
        move_node_pointer->s_int = node_member_int;
        single_linked_list_print(single_linked_list_pointer);
    }
    return single_linked_list_pointer;
}
