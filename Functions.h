#include ".\\Library\\my_std.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

const size_t MAXLEN = 1000, MAXLINES = 10000;
enum PRINT_TYPE
{
    raw_text,
    sorted_form_end_text,
    sorted_form_start_text
};

char **ReadFile(const char *fileName, size_t *lenPointerArr);
size_t replaceRNto0(char *stringText, size_t fileSize);
void SetPointerArr(char *stringText, size_t fileSize, char **pointerArr);

void PrintText  (char *const *PointerArr, enum PRINT_TYPE printType, int nLines = 100);
void WriteToFile(char *fileWName, char **pointerArr, size_t lenPointerArr);

int CompareStrEnd (const void *first_string, const void *second_string);
int CompareStrStart(const void *first_string, const void *second_string);

char** Selfstrdup (char** str1, size_t count);