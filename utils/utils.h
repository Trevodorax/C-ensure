#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isInStringArray(
    char ** array, 
    size_t arraySize, 
    const char * word
);

void removeFromStringArray(
    char *** array,
    size_t * arraySize,
    const char * word
);
