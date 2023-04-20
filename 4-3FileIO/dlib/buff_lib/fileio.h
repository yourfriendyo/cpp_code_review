#include <stdio.h>

#define NUM 1024

enum FLUSH
{
    FLUSH_NONE = 0,
    FLUSH_LINE,
    FLUSH_ALL,
};

typedef struct _MY_FILE
{
    int fd;
    
    char in_buff[NUM];
    char out_buff[NUM];

    size_t icur;
    size_t ocur;

    int flush;

}MY_FILE;

MY_FILE* myfopen(const char* pathname, const char* mode);

size_t myfwrite(const void *ptr, size_t size, size_t nmemb, MY_FILE *stream);

size_t myfread(void *ptr, size_t size, size_t nmemb, MY_FILE *stream);

int myfflush(MY_FILE* stream);

int myfclose(MY_FILE* stream);

