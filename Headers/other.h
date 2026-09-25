#ifndef OTHERLIB
#define OTHERLIB

#include "common.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


void HowPrintHelp();
void PrintHelp();

int SplitNameExt(Options *pOptions);
char *CreateNameFile(Options *pOptions, const char *strToAdd);

int PrintText(ArrInfo *pArrInfo, Options *pOptions);
bool IsNeedPrintThis(char *whatPrint, enum PRINT_TYPE printType);

int WriteToFile(char *fileWName, ArrInfo *pArrInfo, Options *pOptions);
char** Selfstrdup (char** str1, size_t count);

void SortAndDisplay(ArrInfo *pArrInfo, Options *pOptions, int(*CompareStrStart)(const void *a, const void *b), char *fileWName);



#endif