#include <stdio.h>
typedef int(*fp_t)(void); //定义函数指针类型?
void * func_a(void);
int func_b(void);

int main(void) {
    void*(*fp)(void);
    fp = func_a();
    fp();
    return 0;
}

void * func_a(void) {
    printf("func_a=%p %p\n", func_a, &func_a);
    return func_a;
}

int func_b(void) {
    printf("func_b\n");
    return 0;
}

/*
int main(void) {
    //printf("%d\n", EOF);
    char char_array[5] = {1, 2, 3, 4, 5};
    for (int i = 1; i <= 5; i++) {
        printf("%d\n", char_array[i]);
    }
    return 0;
}
*/
