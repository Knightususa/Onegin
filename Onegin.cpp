#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "comparators.h"
#include "read_file.h"
#include "other.h"

int main()
{
    char fileName[]          = "Onegin_text.txt";
    char fileSortEndName[]   = "Onegin_text_end_sorted.txt";
    char fileSortStartNAme[] = "Onegin_text_start_sorted.txt";
    char fileReadTest[]      = "Onegin_text_read_test.txt";
    size_t lenPointerArr = 0;
    
    char **pointerArr = ReadFile(fileName, &lenPointerArr);
    $(pointerArr[0], p);
    $(pointerArr[1], s);

    //Text without sorting
    PrintText((char *const *)pointerArr, raw_text);
    WriteToFile(fileReadTest, pointerArr, lenPointerArr);
    
    //Text sorted from start
    char **pointerArrStartSort = Selfstrdup(pointerArr, lenPointerArr);
    qsort (pointerArrStartSort, lenPointerArr, sizeof(char*), &CompareStrStart);
    PrintText((char *const *)pointerArr, sorted_form_start_text);
    WriteToFile(fileSortStartNAme, pointerArrStartSort, lenPointerArr);

    //Text sorted from end
    char **pointerArrEndSort = Selfstrdup(pointerArr, lenPointerArr);
    qsort (pointerArrEndSort, lenPointerArr, sizeof(char*), &CompareStrEnd);
    PrintText((char *const *)pointerArr, sorted_form_end_text);
    WriteToFile(fileSortEndName, pointerArrEndSort, lenPointerArr);
}