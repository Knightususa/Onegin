#include "Functions.h"

char **ReadFile(const char *fileName, size_t *lenPointerArr)
{
    FILE *pFile = fopen(fileName, "rb");
    yaissert(pFile != NULL, "Pointer to file is NULL");

    struct stat fileStat = {};
    fstat(fileno(pFile), &fileStat);
    size_t fileSize = fileStat.st_size;

    printf("Size of file = " RED "%lli bytes\n\n\n" RESET, fileSize);
    char *stringText = (char *)safe_calloc((size_t)fileSize + 1, sizeof(char));

    yaissert(stringText != NULL, "Pointer is NULL");
    fread((void *) stringText, sizeof(char), fileSize, pFile);

    size_t nlines = replaceRNto0(stringText, fileSize);
    
    char **pointerArr = (char **)safe_calloc((size_t)nlines, sizeof(char *));
    SetPointerArr(stringText, fileSize, pointerArr);

    *lenPointerArr = nlines;
    return pointerArr;
}

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

int CompareStrEnd(const void *a, const void *b)
{
    const char *p1 = *(const char *const *)a;
    const char *p2 = *(const char *const *)b;
    if (p1 == NULL)
        return 1;
    if (p2 == NULL)
        return -1;

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

        char char1 = (char)tolower(p1[i1]);
        char char2 = (char)tolower(p2[i2]);

        if (char1 != char2)
            return char1 - char2;

        i1--;
        i2--;
    }
    return 0;
}

int CompareStrStart(const void *a, const void *b)
{
    const char *p1 = *(const char *const *)a;
    const char *p2 = *(const char *const *)b;

    if (p1 == NULL)
        return 1;
    if (p2 == NULL)
        return -1;

    size_t i1 = 0, lenp1 = strlen(p1);
    size_t i2 = 0, lenp2 = strlen(p2);

    while (i1 <= lenp1 && i2 <= lenp2)
    {
        while (i1 <= lenp1 && !isalpha((unsigned char)p1[i1]))
            i1++;
        while (i2 <= lenp2 && !isalpha((unsigned char)p2[i2]))
            i2++;
        if (i1 > lenp1 || i2 > lenp2)
            break;

        char char1 = (char)tolower(p1[i1]);
        char char2 = (char)tolower(p2[i2]);

        if (char1 != char2)
            return char1 - char2;
        i1++;
        i2++;
    }
    return 0;
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


size_t replaceRNto0(char *stringText, size_t fileSize)
{
    size_t i = 0;
    size_t nlines = 0;

    while (1)
    {
        char charInArr = stringText[i];

        while(charInArr == ' ')
        {
            stringText[i++] = '\0';
            charInArr = stringText[i];
        }

        while(charInArr != '\n' && charInArr != '\r' && charInArr != '\0' && i < fileSize + 1)
        {
            i++;
            charInArr = stringText[i];
        }

        if(charInArr == '\r' || charInArr == '\n')
        {
            while(stringText[i] == '\r' || stringText[i] == '\n')
                stringText[i++] = '\0';
            nlines++;
        }

        else if(charInArr == '\0' || i == fileSize)
        {
            nlines++;
            stringText[i] = '\0';
            break;
        }
    }
    $(stringText[i], c);
    return nlines;
}

void SetPointerArr(char *stringText, size_t fileSize, char **pointerArr)
{
    size_t i = 0;
    int indexLine = 0;
    pointerArr[indexLine++] = &(stringText[0]);
    
    while (1)
    {
        char charInArr = stringText[i];
        while(charInArr != '\0' && i < fileSize)
        {
            i++;
            charInArr = stringText[i];
        }

        if(i < fileSize)
        {
            while(stringText[i] == '\0' && i < fileSize)
                i++;
            if(i < fileSize)
                pointerArr[indexLine++] = &(stringText[i]);
        }
        if(i >= fileSize)
            break;
    }
}