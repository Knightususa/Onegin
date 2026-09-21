#include <stdio.h>
#include <stdlib.h>

#include ".\Library\my_std.h"
#include "Functions.h"

int main()
{
    char fileName[]          = "Onegin_text.txt";
    char fileSortEndName[]   = "Onegin_text_end_sorted.txt";
    char fileSortStartNAme[] = "Onegin_text_start_sorted.txt";
    char fileReadTest[]      = "Onegin_text_read_test.txt";
    size_t lenPointerArr;
    
    char **pointerArr = ReadFile(fileName, &lenPointerArr);
    $(pointerArr[0], p);
    $(pointerArr[1], s);
    WriteToFile(fileReadTest, pointerArr, lenPointerArr);
    PrintText((char *const *)pointerArr, raw_text);
    
    char **pointerArrEndSort = Selfstrdup(pointerArr, lenPointerArr);
    qsort (pointerArrEndSort, lenPointerArr, sizeof(char*), &CompareStrEnd);
    // PrintText((char *const *)pointerArr, sorted_form_end_text);
    WriteToFile(fileSortEndName, pointerArrEndSort, lenPointerArr);

    char **pointerArrStartSort = Selfstrdup(pointerArr, lenPointerArr);
    qsort (pointerArrStartSort, lenPointerArr, sizeof(char*), &CompareStrStart);
    // PrintText((char *const *)pointerArr, sorted_form_start_text);
    WriteToFile(fileSortStartNAme, pointerArrStartSort, lenPointerArr);
}