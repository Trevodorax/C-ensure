#define _DICTIONARY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ** words;
    size_t size;
} dictionary_t;

void addToDictionary(
    dictionary_t * dictionary,
    const char * addedWord
);

void printDictionary(
    dictionary_t dictionary
);

char * censorMessage(
    dictionary_t dictionary,
    const char * message
);

void censorWord(
    char * censoredMessage,
    const char * censoredWord
);

void printCensoredMessage(
    dictionary_t dictionary,
    const char * message
);

void saveDictionary(
    dictionary_t dictionary
);

void getDictionary(
    dictionary_t * dictionary
);
