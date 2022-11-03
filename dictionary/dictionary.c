#ifndef _DICTIONARY_H_
#include "./dictionary.h"
#endif

void addToDictionary(
    dictionary_t * dictionary,
    const char * addedWord
)
{
    // prevent duplicate in dictionary
    if(isInStringArray(dictionary->words, dictionary->size, addedWord) != -1)
    {
        printf("\nThis word is already in dictionary.\n");
        return;
    }

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
    // message that will be censored
    char * censoredMessage = malloc(strlen(message) * sizeof(char) + 1);
    strcpy(censoredMessage, message);

    // add stars instead of word for each censored word
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

    // for each occurence of the censoredWord, replace it with stars
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
    printf("%s", censoredMessage);
    free(censoredMessage);
}

// stores the content of the dictionary in a file for data persistance
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

// get the dictionary stored by potential previous executions
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
        // temporary storage as words are fetched char by char in the file
        currentWord = malloc(0);
        currentWordSize = 0;

        while(1)
        {
            nextChar = fgetc(storageFile);

            // finishes the program when it reaches the end of the file
            if(feof(storageFile))
            {
                free(currentWord);
                fclose(storageFile);
                return;
            }

            // at the end of each word, store it in the dictionary
            if(nextChar == '\n')
            {
                currentWord = realloc(currentWord, sizeof(char) * (currentWordSize + 1));
                *(currentWord + currentWordSize) = '\0';
                addToDictionary(dictionary, currentWord);
                break;
            }

            // if a normal character was found, add it to the current word
            currentWord = realloc(currentWord, sizeof(char) * (currentWordSize + 1));
            *(currentWord + currentWordSize) = nextChar;
            currentWordSize++;
        }

        free(currentWord);
    }

    fclose(storageFile);
    return;
}

void removeFromDictionary(
    dictionary_t * dictionary,
    const char * word
)
{
    removeFromStringArray(&(dictionary->words), &(dictionary->size), word);
}
