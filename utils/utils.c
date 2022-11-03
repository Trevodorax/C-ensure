#ifndef _UTILS_H_
#include "./utils.h"
#endif

// my reusable functions

int isInStringArray(
    char ** array, 
    size_t arraySize, 
    const char * word
)
{
    for(int i = 0; i < arraySize; i++)
    {
        if(strcmp(*(array + i), word) == 0)
        {
            return i;
        }
    }

    return -1;
}

void removeFromStringArray(
    char *** array,
    size_t * arraySize,
    const char * word
)
{
    int removedIndex = isInStringArray(*array, *arraySize, word);

    if(removedIndex == -1)
    {
        return;
    }
    printf("\nremoved index : %d", removedIndex);
    printf("\nremoving : %s", *(*(array) + removedIndex));

    for(int i = removedIndex; i < (*arraySize) - 1; i++)
    {
        *(*(array) + i) = realloc(*(*(array) + i), sizeof(char) * strlen(*(*(array) + i + 1)) + 1);
        strcpy(*(*(array) + i), *(*(array) + i + 1));
    }

    free(*(*(array) + (*arraySize) - 1));

    (*arraySize)--;

    return;
}
