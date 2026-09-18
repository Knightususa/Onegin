#include <stdio.h>
#include <stdlib.h>

#include ".\Library\my_std.h"
#include "Functions.h"

int main()
{
    char fileName[]          = "Onegin_text.txt";
    char fileSortEndName[]   = "Onegin_text_end_sorted.txt";
    char fileSortStartNAme[] = "Onegin_text_start_sorted.txt";
    char **pointerArr = (char **)safe_calloc((size_t)MAXLINES, (size_t)sizeof(char *));
    enum PRINT_TYPE printType = raw_text;

    ReadFile(fileName, &pointerArr);
    PrintText((char *const *)pointerArr, printType);

    char **pointerArrEndSort = Selfstrdup(pointerArr, MAXLINES);
    qsort (pointerArrEndSort, MAXLINES, sizeof(char*), &CompareStrRifm);
    printType = sorted_form_end_text;
    PrintText((char *const *)pointerArr, printType);
    WriteToFile(fileSortEndName, pointerArrEndSort);

    char **pointerArrStartSort = Selfstrdup(pointerArr, MAXLINES);
    qsort (pointerArrStartSort, MAXLINES, sizeof(char*), &CompareStrStart);
    printType = sorted_form_end_text;
    PrintText((char *const *)pointerArr, printType);
    WriteToFile(fileSortStartNAme, pointerArrStartSort);
}