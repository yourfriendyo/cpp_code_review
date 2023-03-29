#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("log.txt", O_CREAT | O_WRONLY, 0664);

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
