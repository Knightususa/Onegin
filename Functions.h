#include ".\\Library\\my_std.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const size_t MAXLEN = 1000, MAXLINES = 10000;
enum PRINT_TYPE
{
    raw_text,
    sorted_text
};

char ***ReadFile(const char *fileName, char ***pPointerArr);
void PrintText(char *const *PointerArr, enum PRINT_TYPE printType, int nLines = 100);
int CompareStrRifm(const void *, const void *);
void WriteToFile(char *fileWName, char **pointerArr);