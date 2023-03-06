#include <stdio.h>

typedef struct st2 st2;
// 结构体自引用和不完整类型引用方法:通过指针
struct st1 {
    unsigned long st1_id;
    st2 * st1_st2_pointer;
};


int main(void) {
    return 0;
}