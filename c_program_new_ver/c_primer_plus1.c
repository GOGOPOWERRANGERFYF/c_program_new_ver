#include <stdio.h>

void jolly(void);
void deny(void);
void nation1(void);
void nation2(void);

int main(void)
{
    int dogs;

    printf("How many dogs do you have?\n");
    scanf("%d", &dogs);
    printf("So you have %d dog(s)!\n", dogs);
    printf("Dogs\n/nDogs\n");

    jolly();
    deny();

    nation1();
    printf(", ");
    nation2();
    printf("\n");
    nation1();
    printf(",\n");
    nation2();
    printf("\n");
    
    return 0;
}

void jolly(void)
{
    printf("Welcome! Jolly.\n");
}

void deny(void)
{
    printf("Welcome! deny.\n");
}

void nation1(void)
{
    printf("A, B");
}

void nation2(void)
{
    printf("C, D");
}


