#include <stdio.h>
#include "fileio.h"

int main()
{
    MY_FILE* fp = myfopen("log.txt", "w");

    myfwrite("hello myfileio\n", 15, 1, fp);

    myfclose(fp);

    return 0;
}
