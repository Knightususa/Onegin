#include "read_file.h"



char **ReadFile(const char *fileName, size_t *lenPointerArr)
{
    FILE *pFile = fopen(fileName, "rb");
    warning(pFile != NULL, "Incorrect filename");
    PrintHelp();

    struct stat fileStat = {};
    fstat(fileno(pFile), &fileStat);
    size_t fileSize = fileStat.st_size;

    printf("Size of file = " RED "%lli bytes\n\n\n" RESET, fileSize);
    char *stringText = (char *)safe_calloc((size_t)fileSize + 1, sizeof(char));

    yaissert(stringText != NULL, "Pointer to strText is NULL");
    fread((void *) stringText, sizeof(char), fileSize, pFile);

    size_t nlines = ReplaceRNto0(stringText, fileSize);
    
    char **pointerArr = (char **)safe_calloc((size_t)nlines, sizeof(char *));
    SetPointerArr(stringText, fileSize, pointerArr);

    *lenPointerArr = nlines;
    fclose(pFile);
    return pointerArr;
}

size_t ReplaceRNto0(char *stringText, size_t fileSize)
{
    size_t i = 0;
    size_t nlines = 0;

    while (true)
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
    return nlines;
}

void SetPointerArr(char *stringText, size_t fileSize, char **pointerArr)
{
    yaissert(stringText != NULL, "Pointer to text is NULL");
    size_t i = 0;
    int indexLine = 0;
    pointerArr[indexLine++] = &(stringText[0]);
    
    while (true)
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

void GetOptions(int argc, char **argv, Options *pOptions)
{
    yaissert(argv != NULL, "argv = NULL");

    int opt = 0;
    while ((opt = getopt(argc, argv, "f:n:p:w:h")) != -1)
    {
        switch (opt)
        {       
            case 'f':
                pOptions -> filename = optarg;
                break;

            case 'n':
                pOptions -> nLines = atoi(optarg);
                break;

            case 'p':
                pOptions -> whatPrint = optarg;
                break;

            case 'w':
                pOptions -> whatWrite = optarg;
                break;

            case 'h':
                pOptions -> isHelp = true;
                break;
            
            default:
                warning(0, "Wrong flag");
                pOptions -> isHelp = true;
                break;
        }
    }
}