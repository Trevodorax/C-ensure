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

void saveDictionary(
    char ** dictionary,
    size_t dictionarySize
)
{
    FILE* storageFile;

    storageFile = fopen("./dictionary/storage", "w");
    
    for(int i = 0; i < dictionarySize; i++)
    {
        fputs(*(dictionary + i), storageFile);
        fputc('\n', storageFile);
    }

    fclose(storageFile);

    return;
}


size_t getDictionary(
    char *** dictionary
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
                return dictionarySize;
            }

            if(nextChar == '\n')
            {
                currentWord = realloc(currentWord, sizeof(char) * (currentWordSize + 1));
                *(currentWord + currentWordSize) = '\0';
                addToDictionary(dictionary, &dictionarySize, currentWord);
                break;
            }

            currentWord = realloc(currentWord, sizeof(char) * (currentWordSize + 1));
            *(currentWord + currentWordSize) = nextChar;
            currentWordSize++;
        }
        
        free(currentWord);
    }
    

    return dictionarySize;
}
