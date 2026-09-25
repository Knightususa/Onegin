#include "../Headers/common.h"
#include "../Headers/comparators.h"
#include "../Headers/read_file.h"
#include "../Headers/other.h"

int main(int argc, char **argv)
{
    Options options = {.filename  = NULL,
                       .fileext   = NULL,
                       .whatPrint = NULL,
                       .whatWrite = NULL,
                       .nLines    = 100,
                       .isHelp    = false};
    
    GetOptions(argc, argv, &options);
    if(options.isHelp)
        PrintHelp();
    if(options.filename == NULL)
        HowPrintHelp();
        
    SplitNameExt(&options);
    char *fileName          = CreateNameFile(&options, "");
    char *fileReadTest      = CreateNameFile(&options, "_read_test");
    char *fileSortEndName   = CreateNameFile(&options, "_end_sorted");
    char *fileSortStartName = CreateNameFile(&options, "_start_sorted");
    
    ArrInfo arrInfo = {.pointerArrOrig = NULL,
                       .pointerArrEdit = NULL,
                       .lenPointerArr  = 0,
                       .printType      = raw_text};

    ReadFile(fileName, &arrInfo);
    
    //Text without sorting
    arrInfo.printType = raw_text;
    arrInfo.pointerArrEdit = arrInfo.pointerArrOrig;
    PrintText(&arrInfo, &options);
    WriteToFile(fileReadTest, &arrInfo, &options);

    //Text sorted from start
    arrInfo.printType = sorted_form_start_text;
    SortAndDisplay(&arrInfo, &options, &CompareStrStart, fileSortStartName);
    
    //Text sorted from end
    arrInfo.printType = sorted_form_end_text;
    SortAndDisplay(&arrInfo, &options, &CompareStrEnd, fileSortEndName);
}