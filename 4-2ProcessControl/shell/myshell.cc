#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NUM 1024
#define ARGC 64

void split(char* cmd, char* argv[]) 
{
    argv[0] = strtok(cmd, " ");
    if (!argv[0])
        return;

    int i = 1;
    while (1) 
    {
        argv[i] = strtok(NULL, " ");
        if (!argv[i])
            break;
        i++;
    }
}

int main()
{
    while (1) 
    {
        printf("[zhangsan@myhost currentpath]$ ");
        fflush(stdout);

        char cmd[NUM] = {0};
        fgets(cmd, sizeof(cmd) - 1, stdin);
        cmd[strlen(cmd) - 1] = 0;

        printf("%s\n", cmd);

        char* argv[ARGC] = {NULL};
        split(cmd, argv);

        pid_t id = fork();
        if (id == 0) 
        {
            execvp(argv[0], argv);
            exit(0);
        }

        int status = 0;
        waitpid(id, &status, 0);
        if (WEXITSTATUS(status) != 0) printf("exit unnoramlly, code: %d", WEXITSTATUS(status));
    }

    return 0;
}
