#include "Functions.h"

char ***ReadFile(const char *fileName, char ***pPointerArr)
{
    yaissert(pPointerArr != NULL, "Pointer is NULL");
    FILE *pFile = fopen(fileName, "r");
    int nlines = 1;
    while (1)
    {
        char buffer[MAXLEN] = {};
        if (fgets(buffer, MAXLEN, pFile) == NULL)
            break;
        if(buffer[0] == '\n')
            continue;
        buffer[strlen(buffer) - 1] = 0;
        (*pPointerArr)[nlines - 1] = strdup((const char *)buffer);
        nlines++;
    }
    return pPointerArr;
}

void PrintText(char *const *PointerArr, enum PRINT_TYPE printType, int nLines)
{
    yaissert(PointerArr != NULL, "Pointer is NULL");
    switch(printType)
    {
        case raw_text:
        printf("Raw text\n");
        break;
        case sorted_text:
        printf("Sorted text\n");
        break;
        default:
        printf("Default\n");
        break;
    }
    int i = 0;
    while (PointerArr[i] != 0 && i < nLines)
    {
        printf(" %i <%s>\n", i + 1, PointerArr[i]);
        i++;
    }
}

int CompareStrRifm(const void *a, const void *b)
{
    const char *p1 = *(const char * const *)a;
    const char *p2 = *(const char * const *)b;
    // printf("%s\n", p2);
    // printf("%s\n\n\n", p1);
    if(p1 == NULL)
        return 1;
    if(p2 == NULL)
        return  -1;

    int i1 = (int)strlen(p1) - 1;
    int i2 = (int)strlen(p2) - 1;
    while (i1 >= 0 && i2 >= 0)
    {
        while (i1 >= 0 && !isalpha((unsigned char)p1[i1]))
            i1--;
        while (i2 >= 0 && !isalpha((unsigned char)p2[i2]))
            i2--;
        if (i1 < 0 || i2 < 0)
            break;
        if (p1[i1] != p2[i2])
            return p1[i1] - p2[i2];
        i1--;
        i2--;
    }
    return 0;
}

void WriteToFile(char *fileWName, char **pointerArr)
{
    yaissert(pointerArr != NULL, "Pointer is NULL");
    FILE *pFile = fopen(fileWName, "w");
    int i = 0;
    while(pointerArr[i] != NULL)
    {
        fputs(pointerArr[i], pFile);
        fputc('\n', pFile);
        i++;
    }
    fclose(pFile);
}