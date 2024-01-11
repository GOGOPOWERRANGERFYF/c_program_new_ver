#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    printf("location of code: %p.\n", (void *) main);
    printf("location of heap: %p.\n", (void *) malloc(sizeof(int)));
    int x = 0;
    printf("location of stack: %p.\n", &x);

    printf("%f\n", 1.0 / 0.0);
    printf("%d\n", 1 / 0);
    //printf("%d\n", 5 / 2);
    //printf("%f\n", 5 / 2);
    return x;
}
