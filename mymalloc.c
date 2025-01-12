#include <stdlib.h>
#include <stddef.h>

#define MEMORY_SIZE 25000
char memory[MEMORY_SIZE];

typedef struct block {
    size_t size;
    int is_free;
    struct block * next;
} block;

block * free_list = (block*)memory;

int * mymalloc(size_t size)
{
    block * current = free_list;

    while (current != NULL)
    {
        if (current != NULL && current->is_free && current->size >= size)
        {
            current-> is_free = 0;
            return (void *)(current + 1);
        }
        current = current-> next;
    }
    return NULL;
}