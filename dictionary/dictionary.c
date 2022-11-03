#ifndef _DICTIONARY_H_
#include "./dictionary.h"
#endif

void addToDictionary(
    dictionary_t * dictionary,
    const char * addedWord
)
{
    // adding a memory slot for new word
    dictionary->words = realloc(dictionary->words, sizeof(char*) * (dictionary->size + 1));

    // creating new word at this slot
    *(dictionary->words + dictionary->size) = malloc(sizeof(char) * strlen(addedWord) + 1);
    strcpy(*(dictionary->words + dictionary->size), addedWord);

    // increasing external dictionarySize
    dictionary->size++;

    return;
}

void printDictionary(
    dictionary_t dictionary
)
{
    for(int i = 0; i < dictionary.size; i++)
    {
        printf("\n%s", *(dictionary.words + i));
    }

    return;
}

char * censorMessage(
    dictionary_t dictionary,
    const char * message
)
{
    char * censoredMessage = malloc(strlen(message) * sizeof(char) + 1);
    strcpy(censoredMessage, message);

    for(int i = 0; i < dictionary.size; i++)
    {
        censorWord(censoredMessage, *(dictionary.words + i));
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
    dictionary_t dictionary,
    const char * message
)
{
    char * censoredMessage = censorMessage(dictionary, message);
    printf("\n%s", censoredMessage);
    free(censoredMessage);
}

void saveDictionary(
    dictionary_t dictionary
)
{
    FILE* storageFile;

    storageFile = fopen("./dictionary/storage", "w");
    
    for(int i = 0; i < dictionary.size; i++)
    {
        fputs(*(dictionary.words + i), storageFile);
        fputc('\n', storageFile);
    }

    fclose(storageFile);

    return;
}


void getDictionary(
    dictionary_t * dictionary
)
{
    FILE* storageFile;
    storageFile = fopen("./dictionary/storage", "r");

    char nextChar;
    size_t dictionarySize = 0;

    char * currentWord;
    size_t currentWordSize;

    while(1)
    {
        currentWord = malloc(0);
        currentWordSize = 0;
        while(1)
        {
            nextChar = fgetc(storageFile);

            if(feof(storageFile))
            {
                free(currentWord);
                fclose(storageFile);
                return;
            }

            if(nextChar == '\n')
            {
                currentWord = realloc(currentWord, sizeof(char) * (currentWordSize + 1));
                *(currentWord + currentWordSize) = '\0';
                addToDictionary(dictionary, currentWord);
                break;
            }

            currentWord = realloc(currentWord, sizeof(char) * (currentWordSize + 1));
            *(currentWord + currentWordSize) = nextChar;
            currentWordSize++;
        }

        free(currentWord);
    }

    fclose(storageFile);
    return;
}
