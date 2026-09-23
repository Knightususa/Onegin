#include "other.h"



int PrintText(ArrInfo arrInfo)
{
    ArrInfo a = arrInfo;
    yaissert(a.pointerArr != NULL, "Pointer is NULL");
    if(!IsNeedPrintThis(a.whatPrint, a.printType))
        return 1;

    printf(RED "\n\n#################################--");
    switch (a.printType)
    {
        case raw_text:
            printf("Raw text");
            break;

        case sorted_form_end_text:
            printf("Sorted from end text");
            break;

        case sorted_form_start_text:
            printf("Sorted from start text");
            break;

        default:
            printf("Incorrect type");
            break;
    }
    printf("--#################################\n\n\n" RESET);
    
    int i = 0;
    while (a.pointerArr[i] != 0 && i < a.nLines)
    {
        printf("pointer %i: %p || <%s>\n", i + 1, &(a.pointerArr[i]), a.pointerArr[i]);
        i++;
    }
    return 0;
}
    
bool IsNeedPrintThis(char *whatPrint, enum PRINT_TYPE printType)
{
    if(whatPrint == NULL)
        return 0;
    char cWhatPrint = 0;
    switch(printType)
    {
        case(raw_text):
            cWhatPrint = 'r';
            break;

        case(sorted_form_end_text):
            cWhatPrint = 'e';
            break;

        case(sorted_form_start_text):
            cWhatPrint = 's';
            break;
        
        default:
            break;
    }
    int whatPrintlen = (int)strlen(whatPrint);
    for(int i = 0; i < whatPrintlen; i++)
    {
        if(whatPrint[i] == cWhatPrint)
            return true;
    }
    return false;
}

int WriteToFile(char *fileWName, ArrInfo arrInfo)
{
    ArrInfo a = arrInfo;

    if(!IsNeedPrintThis(a.whatWrite, a.printType))
        return 1;

    yaissert(a.pointerArr != NULL, "Pointer is NULL");
    warning(fileWName != NULL, "Pointer to file name is NULL");

    FILE *pFile = fopen(fileWName, "w");
    warning(pFile != NULL, "Cant open file with this name");

    size_t i = 0;
    while (a.pointerArr[i] != NULL && i < a.lenPointerArr)
    {
        fprintf(pFile, "pointer %zu: %p || <%s>\n", i + 1, &(a.pointerArr[i]), a.pointerArr[i]);
        i++;
    }

    fclose(pFile);
    return 0;
}

char **Selfstrdup(char **str1, size_t count)
{
    yaissert(str1 != NULL, "Pointer to array that try to copy is NULL");
    char **strcopy = (char **)calloc(count, sizeof(str1[0]));
    size_t i = 0;

    while (i < count)
    {
        strcopy[i] = str1[i];
        i++;
    }
    return strcopy;
}

char *CreateNameFile(char *fileNameBuf, const char *strToAdd)
{
    char *fileName = (char *)safe_calloc(strlen(fileNameBuf) + strlen(strToAdd), sizeof(char));
    strcpy(fileName, fileNameBuf);
    strcat(fileName, strToAdd);
    return fileName;
}

void PrintHelp()
{
    printf(RED "DESCRIPTION\n" RESET\
                    "\tReads text from a file and sorts it by \n"\
                    "\tline start or end.\n"\
                    "\tIt can print the first n lines to the \n"\
                    "\tterminal and also write the sorted text.\n\n\n"\
             YELLOW "\t-f [STRING]" RESET " Enter the name of the file (without extension)\n"\
                    "\tfrom which the text will be read.\n\n"\
             YELLOW "\t-n [INT]" RESET " Enter the number of first lines of a file \n"\
                    "\tto output to the terminal.\n\n"\
             YELLOW "\t-p [STRING]" RESET " Enter some texts to output to the terminal\n"\
                    "\tr - raw text\n"\
                    "\ts - text sorted by line start\n"\
                    "\te - text sorted by line end\n\n"\
             YELLOW "\t-w [STRING]" RESET " Enter what texts to output to the file\n"\
                    "\tr - raw text\n"\
                    "\ts - text sorted by line start\n"\
                    "\te - text sorted by line end\n\n");
}