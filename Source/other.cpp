#include "../Headers/other.h"



int PrintText(ArrInfo *pArrInfo, Options *pOptions)
{
    ArrInfo *a = pArrInfo;
    Options *po = pOptions;
    yaissert(a->pointerArrEdit != NULL, "Pointer to ArrEdit is NULL");
    if(!IsNeedPrintThis(po->whatPrint, a->printType))
        return 1;

    printf(RED "\n\n#################################--");
    switch (a->printType)
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
    while (a->pointerArrEdit[i] != 0 && i < po->nLines)
    {
        printf("pointer %i: %p || <%s>\n", i + 1, &(a->pointerArrEdit[i]), a->pointerArrEdit[i]);
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

int WriteToFile(char *fileWName, ArrInfo *pArrInfo, Options *pOptions)
{
    ArrInfo *a = pArrInfo;
    Options *po = pOptions;

    if(!IsNeedPrintThis(po->whatWrite, a->printType))
        return 1;

    yaissert(a->pointerArrEdit != NULL, "Pointer is NULL");
    warning(fileWName != NULL, "Pointer to file name is NULL");

    FILE *pFile = fopen(fileWName, "w");
    warning(pFile != NULL, "Cant open file with this name");

    size_t i = 0;
    while (a->pointerArrEdit[i] != NULL && i < a->lenPointerArr)
    {
        fprintf(pFile, "pointer %zu: %p || <%s>\n", i + 1, &(a->pointerArrEdit[i]), a->pointerArrEdit[i]);
        i++;
    }

    fclose(pFile);
    return 0;
}

char **Selfstrdup(char **str1, size_t count)
{
    yaissert(str1 != NULL, "Pointer to array that try to copy is NULL");
    char **strcopy = (char **)safe_calloc(count, sizeof(str1[0]));
    size_t i = 0;

    while (i < count)
    {
        strcopy[i] = str1[i];
        i++;
    }
    return strcopy;
}

char *CreateNameFile(Options *pOptions, const char *strToAdd)
{
    char *fileName = (char *)safe_calloc(strlen(pOptions->filename) + 
                                         strlen(pOptions->fileext)  +
                                         strlen(strToAdd), sizeof(char));
    strcpy(fileName, pOptions->filename);
    strcat(fileName, strToAdd);
    strcat(fileName, pOptions->fileext);
    return fileName;
}

void PrintHelp()
{
    printf(RED "DESCRIPTION\n" RESET\
                    "\tReads text from a file and sorts it by \n"\
                    "\tline start or end.\n"\
                    "\tIt can print the first n lines to the \n"\
                    "\tterminal and also write the sorted text.\n\n\n"\
             YELLOW "\t-i [STRING] Necessarily\n" RESET \
                    "\tEnter the name of the file \n"\
                    "\t(with extension(or if without extension it will be readed as txt file))\n"\
                    "\tfrom which the text will be read.\n\n"\
             YELLOW "\t-n [INT] Not necessarily\n" RESET\
                    "\tEnter the number of first lines of a file \n"\
                    "\tto output to the terminal.\n\n"\
             YELLOW "\t-p [STRING] Not necessarily\n" RESET\
                    "\tEnter some texts to output to the terminal\n"\
                    "\tr - raw text\n"\
                    "\ts - text sorted by line start\n"\
                    "\te - text sorted by line end\n\n"\
             YELLOW "\t-o [STRING] Not necessarily\n" RESET\
                    "\tEnter what texts to output to the file\n"\
                    "\tr - raw text\n"\
                    "\ts - text sorted by line start\n"\
                    "\te - text sorted by line end\n\n");
    abort();
}

void HowPrintHelp()
{
    printf(YELLOW "To display a hint on how to run the program enter -h\n" RESET);
    abort();
}


int SplitNameExt(Options *pOptions)
{   
    char *f = pOptions->filename;
    int lenf = (int)strlen(f);
    int i = lenf - 1;

    while(i >= 0 && f[i] != '.')
        i--;

    if(i < 0)
    {
        pOptions->fileext = (char *)safe_calloc(strlen(".txt"), sizeof(char));
        strcat(pOptions->fileext, ".txt");
        return 0;
    }

    pOptions->fileext = (char *)safe_calloc(lenf - i, sizeof(char));

    for(int j = 0; i + j < lenf; j++)
    {
        (pOptions->fileext)[j] = (pOptions->filename)[i + j];
        (pOptions->filename)[i + j] = '\0';
    }
    return 1;
}


void SortAndDisplay(ArrInfo *pArrInfo, Options *pOptions, int(*CompareStrStart)(const void *a, const void *b), char *fileWName)
{
    ArrInfo *pa = pArrInfo;
    Options *po = pOptions;
    if(!IsNeedPrintThis(po->whatPrint, pa->printType) && !IsNeedPrintThis(po->whatWrite, pa->printType))
        return;
    pa->pointerArrEdit = Selfstrdup(pa->pointerArrOrig, pa->lenPointerArr);
    qsort (pa->pointerArrEdit, pa->lenPointerArr, sizeof(char*), CompareStrStart);
    PrintText(pa, po);
    WriteToFile(fileWName, pa, po);
}