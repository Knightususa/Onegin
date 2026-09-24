#include "../Headers/comparators.h"



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