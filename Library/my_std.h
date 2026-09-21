#ifndef MY_STD
#define MY_STD

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define $(variable, typeInprintf) printf("\n" #variable " = <%" #typeInprintf ">\n", variable);

#define RED "\x1B[31m"
#define RESET "\x1B[0m"

#ifndef NDEBUG
#define yaissert(usl, text)                                                                                            \
    {                                                                                                                  \
        if (!(usl))                                                                                                    \
        {                                                                                                              \
            printf("\n" RED text RESET "\n%s:%i", __FILE__, __LINE__);                                            \
            abort();                                                                                                   \
        }                                                                                                              \
    }
#else
#define yaissert
#endif

void *safe_calloc(size_t count, size_t size);
void *safe_malloc(size_t size);
void  safe_free(void *pointer, size_t size);

#endif