#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    umask(00);

    // int fd = open("log.txt", O_CREAT | O_WRONLY, 0666);
    int fd = open("log.txt", O_CREAT | O_WRONLY | O_TRUNC | O_RDONLY, 0666);
    // int fd = open("log.txt", O_CREAT | O_WRONLY | O_APPEND, 0666);

    if (fd < 0) 
    {
        printf("fd: %d, errno: %d, errdisc: %s\n", fd, errno, strerror(errno));
        exit(1);
    }

    printf("fd: %d\n", fd);

    // const char* msg = "hello 404 small ugly guy\n";
    const char* msg = "aa";

    for (int i = 0; i < 5; i++) 
    {
        /* char line[256];
        snprintf(line, 256, "%d:%s", i, msg); */

        ssize_t s = write(fd, msg, strlen(msg));
    }

    char buff[256];
    ssize_t s = read(fd, buff, sizeof(buff) - 1);
    printf("%s\n", buff);


    close(fd);
    return 0;
}

// int main()
// {
//     FILE* fp = fopen("log.txt", "w");
//     if (fp == NULL) 
//     {
//         perror("fopen");
//         return 1;
//     }
// 
//     const char* msg = "小丑陈鑫出列！！";
//     int cnt = 5;
// 
//     while (cnt)
//     {
//         // char buffer[256];
//         // snprintf(buffer, 256, "%s:%d\n", msg, cnt);
//         // printf("%s",buffer);
// 
//         // fprintf(fp, "%s:%d\n", msg, cnt);
//         // fprintf(stdout, "%s:%d\n", msg, cnt);
//         
//         // fputs(msg, fp);
//         
//         cnt--;
//     }
// 
//     fclose(fp);
// 
//     return 0;
// }
