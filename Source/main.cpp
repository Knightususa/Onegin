#include <stdio.h>
#include <stdlib.h>

#include "..\\Headers\\common.h"
#include "..\\Headers\\comparators.h"
#include "..\\Headers\\read_file.h"
#include "..\\Headers\\other.h"

int main(int argc, char **argv)
{
    Options options = {.filename  = NULL,
                       .whatPrint = NULL,
                       .whatWrite = NULL,
                       .nLines    = 100,
                       .isHelp    = false};
    
    GetOptions(argc, argv, &options);
    if(options.isHelp || options.filename == NULL)
        PrintHelp();
    char *fileNameBuf = options.filename;
    char *fileName          = CreateNameFile(fileNameBuf, ".txt"); //TODO принимать файлы с расширением
    char *fileReadTest      = CreateNameFile(fileNameBuf, "_read_test.txt");
    char *fileSortEndName   = CreateNameFile(fileNameBuf, "_end_sorted.txt");
    char *fileSortStartName = CreateNameFile(fileNameBuf, "_start_sorted.txt");
    size_t lenPointerArr = 0;
    
    char **pointerArr = ReadFile(fileName, &lenPointerArr);
    
    ArrInfo arrInfo = {.lenPointerArr = lenPointerArr,
                       .whatPrint     = options.whatPrint,
                       .whatWrite     = options.whatWrite,
                       .nLines        = options.nLines};
    
    //Text without sorting
    arrInfo.printType  = raw_text;
    arrInfo.pointerArr = pointerArr;
    PrintText(arrInfo);
    WriteToFile(fileReadTest, arrInfo);
    
    //Text sorted from start
    char **pointerArrStartSort = Selfstrdup(pointerArr, lenPointerArr);//TODO однотипный вывод(функция)
    qsort (pointerArrStartSort, lenPointerArr, sizeof(char*), &CompareStrStart);
    arrInfo.printType  = sorted_form_start_text;
    arrInfo.pointerArr = pointerArrStartSort;
    PrintText(arrInfo);
    WriteToFile(fileSortStartName, arrInfo);
    
    //Text sorted from end
    char **pointerArrEndSort = Selfstrdup(pointerArr, lenPointerArr);
    qsort (pointerArrEndSort, lenPointerArr, sizeof(char*), &CompareStrEnd);
    arrInfo.printType  = sorted_form_end_text;
    arrInfo.pointerArr = pointerArrEndSort;
    PrintText(arrInfo);
    WriteToFile(fileSortEndName, arrInfo);
}