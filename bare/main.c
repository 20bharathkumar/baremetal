/*
NAME: BHARATHKUMAR K
DATE: 19/12/2024
DESCRIPTION:
SAMPLE INPUT:
SAMPLE OUTPUT:
*/

#include "mal.h"
#define uint8_t char
hp hep[HEAP_SIZE];

void print_stat()
{
    printf("Heap Status:\n");
    for (int i = 0; i < HEAP_SIZE; )
    {
        printf("Block %d: Size = %lu KB, Free = %d\n", i, hep[i].size, hep[i].free);
        i += hep[i].size; // Move to the next block based on size
    }

}

int main()
{
    initialize_heap();

    // Malloc calls
    void* p1 = my_malloc(sizeof(int)*128); // 512 bytes -> 1KB
    printf("allocated\n");
    print_stat();
    void* p2 = my_malloc(sizeof(uint8_t) * 1000); // 1000 bytes -> 1KB
    printf("allocated\n");
    print_stat();

    my_free(p1);
    printf("p1 deallocated\n");
    //my_free(p1);	//prints error
    
    my_free(p2);
    printf("p2 deallocated\n");



    return 0;
}

