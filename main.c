/*
author  : Paul GAUDEAUX
purpose : Chatting app with censored messages
*/

#include "./main.h"


int main(int argc, char ** argv)
{
    // where all the censored words will be stored
    dictionary_t dictionary;
    dictionary.words = malloc(0);
    dictionary.size = 0;

    // temporary storage for what the user types
    char * userInput;

    // represents what the app is currently doing
    char appState = 's';

    // fetch existing dictionary from previous
    getDictionary(&dictionary);

    while(1)
    {
        // prints the right options according to appState
        printMenu(appState);

        // if adding words, it stops at space, else it gets all input
        userInput = getInputString(appState == 'm' ? 0 : 1);

        system("clear");

        if(strlen(userInput) == 0)
        {
            continue;
        }

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

        if(strcmp(userInput, "remove") == 0)
        {
            appState = 'r';
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
                addToDictionary(&dictionary, userInput);
                break;
            case 'm':
                printf("\n");
                printCensoredMessage(dictionary, userInput);
                break;
            case 'r':
                printf("\n");
                removeFromDictionary(&dictionary, userInput);
                break;
        }

        free(userInput);

    }

    printf("\n");

    // put the words in a storage file
    saveDictionary(dictionary);

    for(int i = 0; i < dictionary.size; i++)
    {
        free(*(dictionary.words + i));
    }
    free(dictionary.words);

    return 0;
}
