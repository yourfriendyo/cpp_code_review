#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
/*
int g_val = 0;

int main()
{
    pid_t id = fork();
    assert(id >= 0);

    if (id == 0)
    {
        while (1) {
            printf("I am child proc, pid: %d, g_val: %d, &g_val: %p\n", getpid(), g_val, &g_val);
            g_val++;
            sleep(1);
        }
    }
    else 
    {
        while (1) {
            printf("I am fathr proc, pid: %d, g_val: %d, &g_val: %p\n", getpid(), g_val, &g_val);
            sleep(1);
        }
    }

    return 0;

} */

/* int uninit_val;
int inited_val = 0;

int main()
{
    static int s_val = 0;
    int a, b, c, d;

    printf("     a: %p\n", &a);
    printf("     b: %p\n", &b);
    printf("     c: %p\n", &c);
    printf("     d: %p\n", &d);

    printf(" heap1: %p\n", malloc(4));
    printf(" heap2: %p\n", malloc(4));
    printf(" heap3: %p\n", malloc(4));
    printf(" heap4: %p\n", malloc(4));

    printf("uninit: %p\n", &uninit_val);
    printf("inited: %p\n", &inited_val);
    printf("static: %p\n", &s_val);

    printf(" const: %p\n", "1234");
    printf(" const: %p\n", main);   

    return 0;
} */

/* int main()
{
    pid_t id = fork();
    if (id == 0) 
    {
        sleep(30);
    }
    else 
    {
        sleep(5);
    }
    return 0;
} */


int g_val = 0;

int main() 
{
    if (fork() == 0) 
    {
        printf("child proc change, g_val=%3d, &g_val=%p\n", g_val, &g_val);
        g_val = 200;
        printf("child proc done  , g_val=%3d, &g_val=%p\n", g_val, &g_val);
    }
    else 
    {
        sleep(1);
        printf("I am parent proc , g_val=%3d, &g_val=%p\n",g_val, &g_val);
    }

    return 0;
}

/* void Usage(const char* arg)
{
    printf("Usage:\n\t%s -[a|b|c]\n", arg);
}

int main(int argc, char* argv[])
{
    if (argc != 2) 
    {
        Usage(argv[0]);
        exit(1);
    }
    
    if (strcmp(argv[1], "-a") == 0)      printf("aaaaaaaaaaaaaaaaaaaaaaa\n");
    else if (strcmp(argv[1], "-b") == 0) printf("bbbbbbbbbbbbbbbbbbbbbbb\n");
    else if (strcmp(argv[1], "-c") == 0) printf("ccccccccccccccccccccccc\n");
    else                                 printf("other\n");


    return 0;
} */

// int main(int argc, char* argv[])
// {
//     // for (int i = 0; argv[i]; i++)
//     for (int i = 0; i < argc; i++) 
//     {
//         printf("argv[%d]->%s\n", i, argv[i]);
//     }
//     return 0;
// }

// int main()
// {
//     char* own = getenv("USER");
//     if (strcmp(own, "yyx") == 0)
//     {
//         printf("这个程序已经执行了\n");
//     }
//     else 
//     {
//         printf("当前用户%s非法\n", own);
// 
//     }
// }

/* int main()
{
    char* pwd = getenv("PWD");
    if (pwd == NULL)
        perror("getenv::");
    else
        printf("%s\n", pwd);

    return 0;
} */

/* int main(int argc, char* argv[], char* envp[])
{
    extern char** environ;

    for (int i = 0; environ[i]; i++) 
    {
        printf("environ[%d]->%s\n", i, environ[i]);
    }

    return 0;
}
 */

/* int main()
{
    pid_t id = fork();

    if (id == 0) 
    {
        while(1);
    }
    else 
    {
        sleep(10);
    }

    return 0;
} */

/* int main()
{
    pid_t id = fork();
    if (id == 0)
    {
        sleep(5);
    }
    else 
    {
        sleep(100);
    }
    return 0;
} */
