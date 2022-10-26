#define _DICTIONARY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addToDictionary(
    char *** dictionary,
    size_t * dictionarySize,
    const char * addedWord
);

void printDictionary(
    char ** dictionary,
    size_t dictionarySize
);

char * censorMessage(
    const char * message, 
    char ** dictionary,
    size_t dictionarySize
);

void censorWord(
    char * censoredMessage,
    const char * censoredWord
);

void printCensoredMessage(
    const char * message,
    char ** dictionary,
    size_t dictionarySize
);
