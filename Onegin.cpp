#include <stdio.h>
#include <stdlib.h>

#include ".\Library\my_std.h"
#include "Functions.h"

int main()
{
    char fileName[] = "Onegin_text.txt";
    char fileWName[] = "Onegin_text_sorted.txt";
    char **pointerArr = (char **)safe_calloc((size_t)MAXLINES, (size_t)sizeof(char *));
    ReadFile(fileName, &pointerArr);
    enum PRINT_TYPE printType = raw_text;
    PrintText((char *const *)pointerArr, printType);
    qsort(pointerArr, MAXLINES, sizeof(char*), &CompareStrRifm);
    printType = sorted_text;
    PrintText((char *const *)pointerArr, printType);
    WriteToFile(fileWName, pointerArr);
}