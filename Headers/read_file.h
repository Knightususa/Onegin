#ifndef READ_FILE
#define READ_FILE

#include "common.h"
#include "other.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void ReadFile(char *fileName, ArrInfo *pArrInfo);
size_t ReplaceRNto0(char *stringText, size_t fileSize);
void SetPointerArr(char *stringText, size_t fileSize, char **pointerArr);

void GetOptions(int argc, char **argv, Options *pOptions);

#endif