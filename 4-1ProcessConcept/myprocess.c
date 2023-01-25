#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    // while (1)
    // {
    //     pid_t pid  = getpid();
    //     pid_t ppid = getppid();
    //     
    //     printf("hello proc id: %d, ppid: %d\n", pid, ppid);
    //     sleep(1);
    // }
    //
    
    int val = 100;

    pid_t ret = fork();

    if (ret == 0) // child proc
    {
        while (1)
        {
            printf("child proc,  pid: %d, val: %d, &val: %p\n", getpid(), val, &val);
            sleep(1);
        }
    }
    else if (ret > 0) // parent proc
    {
        while (1)
        {
            printf("parent proc, pid: %d, val: %d, &val: %p\n", getpid(), val, &val);
            sleep(1);
        }

        val = 4321;
    }
    else
    {
        assert(1);
    }


    return 0;
}

