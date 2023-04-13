#include <stdio.h>
#include <assert.h>
#include "myfile.h"

int main()
{
    MY_FILE* fp = myfopen("log.txt", "w");
    assert(fp);

    myfwrite("hello myfwrite\n", 15, 1, fp);

    myfclose(fp);

    return 0;
}
