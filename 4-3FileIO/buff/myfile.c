#include "myfile.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


MY_FILE* myfopen(const char* path, const char* mode)
{
    int flag = 0;
    if (strcmp(mode, "r") == 0) flag |= O_RDONLY;
    else if (strcmp(mode, "w") == 0) flag |= O_CREAT | O_WRONLY | O_TRUNC;
    else if (strcmp(mode, "a") == 0) flag |= O_CREAT | O_WRONLY | O_APPEND;
    else {}

    int fd = 0;
    if (flag & O_CREAT) fd = open(path, flag, 0666);
    else                fd = open(path, flag);

    if (fd < 0)
        return NULL;

    MY_FILE* myfile = (MY_FILE*)malloc(sizeof(MY_FILE));
    if (!myfile)
    {
        close(fd);
        return NULL;
    }
    
    myfile->fd = fd;
    myfile->flush_way = FLUSH_LINE; 
    memset(myfile->output_buffer, 0, sizeof(myfile->output_buffer));

    return myfile;
}

size_t myfwrite(const void* ptr, size_t size, size_t nmenb, MY_FILE* stream)
{
    assert(ptr && stream);

    if (stream->current == SIZE)
        myfflush(stream);

    while (nmenb--)
    {
        memcpy(stream->output_buffer + stream->current, ptr, size);
        stream->current += size;

        if (stream->current + size >= SIZE)
            myfflush(stream);
    }

    stream->output_buffer[stream->current] = 0;

    if (stream->flush_way & FLUSH_LINE)
    {
        myfflush(stream);
    }
    else if (stream->flush_way & FLUSH_ALL)
    {
        if (stream->current == SIZE)
            myfflush(stream);
    }

    return 0;
}

int myfflush(MY_FILE* fp)
{
    write(fp->fd, fp->output_buffer, fp->current);
    fp->current = 0;

    return 0;
}

int myfclose(MY_FILE* fp)
{
    assert(fp);

    if (fp->current > 0)
        myfflush(fp);

    int ret = close(fp->fd);
    free(fp);

    return ret;
}
