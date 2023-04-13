#include <stdio.h>
#include <assert.h>
#include "myfile.h"

int main()
{
    MY_FILE* fp = myfopen("log.txt", "w");
    assert(fp);

    myfwrite("hello myfwrite\n", 15, 1, fp);
    myfclose(fp);

    // myfwrite("hello myfwrite", 14, 1, fp);
    // close(fp->fd);


    return 0;
}
