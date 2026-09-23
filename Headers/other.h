#ifndef OTHERLIB
#define OTHERLIB

#include "common.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

enum PRINT_TYPE
{
    raw_text               = 1,
    sorted_form_end_text   = 2,
    sorted_form_start_text = 3
};

typedef struct 
{
    char *const *pointerArr;
    size_t lenPointerArr;
    enum PRINT_TYPE printType;
    char *whatPrint;
    char *whatWrite;
    int nLines;
} ArrInfo;

void PrintHelp();

int PrintText(ArrInfo arrInfo);
bool IsNeedPrintThis(char *whatPrint, enum PRINT_TYPE printType);

char *CreateNameFile(char *fileNameBuf, const char *strToAdd);
int WriteToFile(char *fileWName, ArrInfo arrInfo);
char** Selfstrdup (char** str1, size_t count);


#endif