#include "other.h"



void PrintText(char *const *pointerArr, enum PRINT_TYPE printType, int nLines)
{
    yaissert(pointerArr != NULL, "Pointer is NULL");

    printf(RED "\n\n#################################--");
    switch (printType)
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
            printf("Default");
            break;
    }
    printf("--#################################\n\n\n" RESET);

    int i = 0;
    while (pointerArr[i] != 0 && i < nLines)
    {
        printf("pointer %i: %p || <%s>\n", i + 1, &pointerArr[i], pointerArr[i]);
        i++;
    }
}



void WriteToFile(char *fileWName, char **pointerArr, size_t lenPointerArr)
{
    yaissert(pointerArr != NULL, "Pointer is NULL");
    FILE *pFile = fopen(fileWName, "w");
    size_t i = 0;
    while (pointerArr[i] != NULL && i < lenPointerArr)
    {
        fprintf(pFile, "pointer %zu: %p || <%s>\n", i + 1, &pointerArr[i], pointerArr[i]);
        i++;
    }
    fclose(pFile);
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