#ifndef READ_FILE
#define READ_FILE

#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

char **ReadFile(const char *fileName, size_t *lenPointerArr);
size_t replaceRNto0(char *stringText, size_t fileSize);
void SetPointerArr(char *stringText, size_t fileSize, char **pointerArr);

#endif