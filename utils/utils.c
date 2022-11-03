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
        // if word at this index matches search string, return the index
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
    // get the index of the removed string
    int removedIndex = isInStringArray(*array, *arraySize, word);

    // if the removed string isn't in array, do nothing
    if(removedIndex == -1)
    {
        return;
    }

    // moving every element after deleted one index lower to delete it
    for(int i = removedIndex; i < (*arraySize) - 1; i++)
    {
        *(*(array) + i) = realloc(*(*(array) + i), sizeof(char) * strlen(*(*(array) + i + 1)) + 1);
        strcpy(*(*(array) + i), *(*(array) + i + 1));
    }

    // last index is not required anymore
    free(*(*(array) + (*arraySize) - 1));
    (*arraySize)--;

    return;
}
