#ifndef _DICTIONARY_H_
#include "./dictionary.h"
#endif

void addToDictionary(
    char *** dictionary,
    size_t * dictionarySize,
    const char * addedWord
)
{
    // adding a memory slot for new word
    *dictionary = realloc(*dictionary, sizeof(char*) * (*dictionarySize + 1));

    // creating new word at this slot
    *((*dictionary) + (*dictionarySize)) = malloc(sizeof(char) * strlen(addedWord) + 1);
    strcpy(*((*dictionary) + (*dictionarySize)), addedWord);

    // increasing external dictionarySize
    (*dictionarySize)++;

    return;
}

void printDictionary(
    char ** dictionary,
    size_t dictionarySize
)
{
    for(int i = 0; i < dictionarySize; i++)
    {
        printf("\n%s", *(dictionary + i));
    }

    return;
}

char * censorMessage(
    const char * message, 
    char ** dictionary,
    size_t dictionarySize
)
{
    char * censoredMessage = malloc(strlen(message) * sizeof(char) + 1);
    strcpy(censoredMessage, message);



    for(int i = 0; i < dictionarySize; i++)
    {
        censorWord(censoredMessage, *(dictionary + i));
    }

    return censoredMessage;
}

void censorWord(
    char * censoredMessage,
    const char * censoredWord
)
{
    char * censoredWordStart;
    while(1) 
    {
        censoredWordStart = strstr(censoredMessage, censoredWord);
        
        if(!censoredWordStart) { break; }

        for(int i = 0; i < strlen(censoredWord); i++)
        {
            *(censoredWordStart + i) = '*';
        }
    }
}

void printCensoredMessage(
    const char * message,
    char ** dictionary,
    size_t dictionarySize
)
{
    char * censoredMessage = censorMessage(message, dictionary, dictionarySize);
    printf("\n%s", censoredMessage);
    free(censoredMessage);
}