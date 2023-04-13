#include <stdio.h>

#define ONE   0x1
#define TWO   0x2
#define THREE 0x4
#define FOUR  0x8

void Print(int flag) 
{
    if (flag & ONE)   printf("hell 1 ");
    if (flag & TWO)   printf("hell 2 ");
    if (flag & THREE) printf("hell 3 ");
    if (flag & FOUR)  printf("hell 4 ");

    printf("\n");
}

int main()
{
    Print(ONE);
    Print(ONE | TWO);
    Print(ONE | TWO | THREE);
    Print(ONE | TWO | THREE | FOUR);
    return 0;
}
