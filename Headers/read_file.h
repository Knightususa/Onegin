#ifndef READ_FILE
#define READ_FILE

#include "other.h"
#include "common.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct 
{
    char *filename;
    char *whatPrint;
    char *whatWrite;
    int nLines;
    bool isHelp;
} Options;


char **ReadFile(const char *fileName, size_t *lenPointerArr);
size_t ReplaceRNto0(char *stringText, size_t fileSize);
void SetPointerArr(char *stringText, size_t fileSize, char **pointerArr);

void GetOptions(int argc, char **argv, Options *pOptions);

#endif