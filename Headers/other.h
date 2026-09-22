#ifndef OTHERLIB
#define OTHERLIB

#include "common.h"
#include <stdio.h>
#include <stdlib.h>

const size_t MAXLEN = 1000, MAXLINES = 10000;
enum PRINT_TYPE
{
    raw_text,
    sorted_form_end_text,
    sorted_form_start_text
};

void PrintText  (char *const *PointerArr, enum PRINT_TYPE printType, int nLines = 100);
void WriteToFile(char *fileWName, char **pointerArr, size_t lenPointerArr);

char** Selfstrdup (char** str1, size_t count);

#endif