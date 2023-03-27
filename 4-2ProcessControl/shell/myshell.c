#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NUM 1024
#define ARGC 64
#define SEP " "

int split(char* cmd, char* argv[], const char* sep) 
{
    argv[0] = strtok(cmd, sep);
    if (!argv[0])
        return 0;

    int i = 1;
    while (1) 
    {
        argv[i] = strtok(NULL, " ");
        if (!argv[i])
            break;
        i++;
    }
    return i;
}

void showEnv() 
{
    extern char** environ;
    for (int i = 0; environ[i] != NULL; i++)
        printf("%d:%s\n", i, environ[i]);
}

int main()
{
    int last_exit_code = 0;

    while (1) 
    {
        // 打印提示
        printf("[zhangsan@myhost currentpath]$ ");
        fflush(stdout);

        // 切割命令行参数
        char cmd[NUM] = {0};
        fgets(cmd, sizeof(cmd) - 1, stdin);
        cmd[strlen(cmd) - 1] = 0;

        char* argv[ARGC] = {NULL};
        int cmd_num = split(cmd, argv, SEP);

        // 处理内建命令
        if (strcmp(argv[0], "cd") == 0 && cmd_num > 0)
        {
            chdir(argv[1]);
            continue;
        }
        if (strcmp(argv[0], "export") == 0 && cmd_num > 0) 
        {
            char* env_kv[ARGC];
            int num = split(argv[1], env_kv, "=");

            if (num == 2)
                setenv(env_kv[0], env_kv[1], 0);
            continue;
        }
        if (strcmp(argv[0], "env") == 0) 
        {
            showEnv();
            continue;
        }
        if (strcmp(argv[0], "echo") == 0 && cmd_num > 0) 
        {
            if (argv[1][0] == '$') 
            {
                if (argv[1][1] == '?') {
                    printf("%d\n", last_exit_code);
                }
                else {
                    printf("%s\n", getenv(argv[1] + 1));
                }
            }
            else {
                printf("%s\n", argv[1]);
            }
            continue;
        }

        // 创建子进程执行命令
        pid_t id = fork();
        if (id == 0) 
        {
            int ret = execvp(argv[0], argv);
            exit(ret);
        }

        // 获取执行情况
        int status = 0;
        waitpid(id, &status, 0);
        if (WEXITSTATUS(status) != 0) 
        {
            last_exit_code = WEXITSTATUS(status);
            printf("exit unnoramlly, code: %d\n", last_exit_code);
        }
    }

    return 0;
}
