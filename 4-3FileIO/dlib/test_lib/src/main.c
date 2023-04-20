#include <stdio.h>
#include "add.h"
#include "sub.h"

int main()
{
    int x = 2;
    int y = 1;

    printf("%d + %d = %d\n", x, y, add(x, y));
    printf("%d - %d = %d\n", x, y, sub(x, y));
}
