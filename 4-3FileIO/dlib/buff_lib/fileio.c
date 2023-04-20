#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "fileio.h"



MY_FILE* myfopen(const char* pathname, const char* mode)
{
    assert(pathname && mode);
    umask(00);

    int ways = 0;
    if (strcmp(mode, "w") == 0)      ways |= O_CREAT | O_WRONLY | O_TRUNC;
    else if (strcmp(mode, "a") == 0) ways |= O_CREAT | O_WRONLY | O_APPEND;
    else if (strcmp(mode, "r") == 0) ways |= O_CREAT | O_RDONLY;

    int fd = open(pathname, ways, 0664);
    assert(fd >= 0);
    
    MY_FILE* fp = (MY_FILE*)malloc(sizeof(MY_FILE));
    assert(fp);

    fp->fd = fd;
    fp->icur = fp->ocur = 0;
    fp->flush = FLUSH_LINE;
    memset(fp->in_buff, 0, sizeof(fp->in_buff));
    memset(fp->out_buff, 0, sizeof(fp->out_buff));

    return fp;
}

size_t myfwrite(const void *ptr, size_t size, size_t nmemb, MY_FILE *stream)
{
    assert(ptr && stream);

    while (nmemb--) 
    {
        memcpy(stream->out_buff + stream->ocur, ptr, size);
        stream->ocur += size;

        if (stream->flush == FLUSH_LINE) 
            myfflush(stream);
        if (stream->ocur + size >= NUM)
            myfflush(stream);
    }

    return size * nmemb;
}

size_t myfread(void *ptr, size_t size, size_t nmemb, MY_FILE *stream)
{

    return 0;
}

int myfflush(MY_FILE* stream)
{
    assert(stream);
    ssize_t s = write(stream->fd, stream->out_buff, stream->ocur);
    stream->ocur = 0;

    return 0;
}

int myfclose(MY_FILE* stream)
{
    assert(stream);

    myfflush(stream);
    close(stream->fd);
    free(stream);

    return 0;
}
