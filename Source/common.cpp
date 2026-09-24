#include "../Headers/common.h"



void *safe_calloc(size_t count, size_t size)
{
    void *pointer = calloc(count, size);
    yaissert(pointer != NULL, "Calloc return NULL\n");
    return pointer;
}

void *safe_malloc(size_t size)
{
    void *pointer = malloc(size);
    yaissert(pointer != NULL, "Malloc return NULL\n");
    memset(pointer, 0, size);
    for (size_t i = 0; i < size; i++)
    {
        yaissert(*(char *)((size_t)pointer + i) == 0, "Malloc returns a pointer whose value is not 0\n");
    }
    return pointer;
}

void safe_free(void *pointer, size_t size)
{
    if (pointer == NULL)
    {
        yaissert(0, "Pointer is NULL");
    }
    else
    {
        memset(pointer, 0, size);
    }
    free(pointer);
    pointer = NULL;
}

