#ifndef COMMON
#define COMMON

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define $(variable, typeInprintf) printf("\n" #variable " = <%" #typeInprintf ">\n", variable)


#define RED "\x1B[31m"
#define YELLOW  "\x1B[33m"
#define RESET "\x1B[0m"

#ifndef NDEBUG
#define yaissert(usl, text)                                                                                            \
    {                                                                                                                  \
        if (!(usl))                                                                                                    \
        {                                                                                                              \
            printf("\n" RED text RESET "\n%s:%i\n", __FILE__, __LINE__);                                                 \
            abort();                                                                                                   \
        }                                                                                                              \
    }
#else
#define yaissert
#endif

#define warning(usl, text)                                                                                            \
{                                                                                                                  \
    if (!(usl))                                                                                                    \
    {                                                                                                              \
        printf("\n" RED text RESET "\n%s:%i\n", __FILE__, __LINE__);                                                                                                \
    }                                                                                                              \
}


typedef struct 
{
    char *filename;
    char *fileext;
    char *whatPrint;
    char *whatWrite;
    int nLines;
    bool isHelp;
} Options;

enum PRINT_TYPE
{
    raw_text               = 1,
    sorted_form_end_text   = 2,
    sorted_form_start_text = 3
};

typedef struct 
{
    char **pointerArrOrig;
    char **pointerArrEdit;
    size_t lenPointerArr;
    enum PRINT_TYPE printType;
} ArrInfo;


void *safe_calloc(size_t count, size_t size);
void *safe_malloc(size_t size);
void  safe_free(void *pointer, size_t size);

#endif