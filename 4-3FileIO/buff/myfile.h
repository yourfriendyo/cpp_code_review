#include <stdio.h>

#define SIZE 1024

enum FLUSH_WAY
{
    FLUSH_NONE = 0,
    FLUSH_LINE,
    FLUSH_ALL,
};

typedef struct _MY_FILE
{
    char  input_buffer[SIZE];
    char output_buffer[SIZE];
    size_t current;
    int flush_way;
    int fd;
} MY_FILE;

MY_FILE* myfopen(const char* path, const char* mode);

size_t myfwrite(const void* ptr, size_t size, size_t nmenb, MY_FILE* stream);

int myfflush(MY_FILE* fp);

int myfclose(MY_FILE* fp);

