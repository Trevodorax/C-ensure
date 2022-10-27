#include "./main.h"


int main(int argc, char ** argv)
{
    // IF EMPTY STRING, CRASH !!!
    int i;
    char * censoredMessage;
    
    char ** dictionary = malloc(0);
    size_t dictionarySize = 0;

    char * userInput;
    char appState = 's';

    dictionarySize = getDictionary(&dictionary);

    while(1)
    {
        printMenu(appState);

        // if adding words, it stops at space, else it gets all input
        userInput = getInputString(appState == 'm' ? 0 : 1);

        // looking for keywords
        if(strcmp(userInput, "add") == 0)
        {
            appState = 'a';
            free(userInput);
            continue;
        }

        if(strcmp(userInput, "message") == 0)
        {
            appState = 'm';
            free(userInput);
            continue;
        }

        if(strcmp(userInput, "stop") == 0)
        {
            free(userInput);
            break;
        }

        // performing the right action with userInput
        switch(appState)
        {
            case 'a':
                addToDictionary(&dictionary, &dictionarySize, userInput);
                printf("\nAdded the phrase \"%s\" to the dictionary.\n", userInput);
                break;
            case 'm':
                printf("\n");
                printCensoredMessage(userInput, dictionary, dictionarySize);
                break;
        }

        free(userInput);

    }

    printf("\n");

    saveDictionary(dictionary, dictionarySize);

    for(i = 0; i < dictionarySize; i++)
    {
        free(*(dictionary + i));
    }
    free(dictionary);

    return 0;
}
