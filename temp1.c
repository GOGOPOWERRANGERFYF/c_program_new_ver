#include <stdio.h>

typedef struct st2 st2; //结构体自引用和不完整类型引用方法:通过指针

typedef struct st1 {
    unsigned long st1_id;
    st2 * st1_st2_pointer;
} st1;

typedef struct  st2 {

};

int main(void) {
    printf("源神启动！！！\n");
    st1 st1_instance;
    return 0;
}
