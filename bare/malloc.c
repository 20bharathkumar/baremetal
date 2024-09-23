/*
NAME: BHARATHKUMAR K
DATE: 19/12/2024
DESCRIPTION:
SAMPLE INPUT:
SAMPLE OUTPUT:
*/

#include "mal.h"


extern hp hep[HEAP_SIZE];
void initialize_heap()
{
    hep[0].size = HEAP_SIZE;
    hep[0].free = FREE;

    for(int i=1; i<HEAP_SIZE; i++)
    {
	hep[i].size = 0;
	hep[i].free = ALOTED;
    }
}

void* my_malloc(size_t req_size)
{
    size_t blocks_need = (req_size + BLOCK_SIZE) / BLOCK_SIZE;

    int index = -1;
    size_t best_size = HEAP_SIZE + 1; // Initialize to large

    for (int i = 0; i < HEAP_SIZE; i++)
    {
        if (hep[i].free && (hep[i].size >= blocks_need))
	{
            index = i;
            best_size = hep[i].size;
        }
    }

    // If blocks are not found, return NULL
    if (index == -1)
    {
        return NULL;
    }

    // If the block is larger than needed, split it
    if (hep[index].size > blocks_need)
    {
        hep[index + blocks_need].size = hep[index].size - blocks_need;
        hep[index + blocks_need].free = FREE;
        hep[index].size = blocks_need;
    }

    // Mark the chosen block as allocated
    hep[index].free = ALOTED;

    // Return a pointer to the allocated block
    return (void*) &hep[index];
}

void my_free(void* ptr) {
    int index = ((hp*) ptr) - hep; // Calculate the index
    // Mark the block as free
    
    if(hep[index].free == FREE)
    {
	printf("Error : Cannot deallocate again\n");
	return;
    }
    hep[index].free = FREE;
    // Try to coalesce with next block if it's free
    if (((index + hep[index].size) < HEAP_SIZE) && hep[index + hep[index].size].free) {
        hep[index].size += hep[index + hep[index].size].size; // Merge the next block
        hep[index + hep[index].size].size = 0; // Invalidate the next block
    }

    // Try to coalesce with previous block if it's free
    for (int i = index - 1; i >= 0; i--) {
        if (hep[i].free) {
            hep[i].size += hep[index].size; // Merge the current block with the previous one
            hep[index].size = 0; // Invalidate the current block
            break;
        }
    }
}

