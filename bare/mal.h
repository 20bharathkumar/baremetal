#ifndef MAL
#define MAL

#include <stdio.h>

#define HEAP_SIZE 128 // Total heap blocks
#define BLOCK_SIZE 1024 // Minimum block size in bytes (1KB)

enum
{
    ALOTED,
    FREE
};

typedef struct node
{
    size_t size;
    int free;
}hp;



void initialize_heap();
void* my_malloc(size_t req_size);
void my_free(void* ptr);

#endif
