#include <stdio.h>
int f1(int);

int main(void) {
    int arg1;
    f1(arg1);
    return 0;
}

int f1(int arg) {
    printf("%d\n", arg);
    return 0;
}

