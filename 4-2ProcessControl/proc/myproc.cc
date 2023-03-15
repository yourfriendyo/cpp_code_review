#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t id = fork();
    if (id == 0) 
    {
        // execl("/usr/bin/ls", "ls", "-a", "-l" NULL);
        
        // const char* const argv[] = { "ls", "-a", "-l", NULL };
        // execv("/usr/bin/ls", (char** const)argv);

        // execl("/usr/bin/g++", "g++", "-o", "./exec/otherproc", "./exec/otherproc.cc", nullptr);
        
        const char* const env[] = {
            "HELLO1=WORLD1",
            "HELLO2=WORLD2",
            "HELLO3=WORLD3",
            NULL
        };

        execle("./exec/otherproc", "./exec/otherproc", nullptr, (char** const)env);

        // execle();
        
        // execlp("ls", "ls", "-a", "-l", NULL);


        exit(1);
    }
    int status = 0;
    waitpid(id, &status, 0);
    printf("wait succ, exit code: %d\n", WEXITSTATUS(status));

    return 0;
}


int test_wait()
{
    pid_t id = fork();
    if (id == 0) 
    {
        while (1) 
        {
            printf("I am child proc, pid:%d, ppid:%d\n", getpid(), getppid());
            sleep(1);
        }
        exit(102);
    }
    else 
    {
        int status = 0;
        while (1) {
            pid_t ret = waitpid(id, &status, WNOHANG);
            if (ret > 0) { // succ
                // printf("proc[%d], code:%d, signal:%d\n", ret, status >> 8, status & 0x7f);
                if (WIFEXITED(status)) {
                    printf("childproc exit normally, exit code:%d\n", WEXITSTATUS(status));
                }
                else {
                    printf("childproc exit by signal:%d\n", WTERMSIG(status));
                }
                break;
            }
            else if (ret == 0) { // nohang
                printf("childproc is not exit, do other things...\n");
            }
            else { // error
                printf("wait error\n");
                break;
            }
            sleep(1);
        }
    }

    return 0;
}
