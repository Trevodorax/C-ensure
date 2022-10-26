#include "./main.h"


int main(int argc, char ** argv)
{
    int i;
    char * censoredMessage;
    
    char ** dictionary = malloc(0);
    size_t dictionarySize = 0;

    char * userInput;
    char appState = 's';

    while(1)
    {
        printMenu(appState);
        userInput = getInputString();

        // looking for keywords
        
        if(strcmp(userInput, "add") == 0)
        {
            appState = 'a';
            continue;
        }

        if(strcmp(userInput, "message") == 0)
        {
            appState = 'm';
            continue;
        }

        if(strcmp(userInput, "stop") == 0)
        {
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

    }
    
    free(userInput);

    printf("\n");

    for(i = 0; i < dictionarySize; i++)
    {
        free(*(dictionary + i));
    }
    free(dictionary);

    return 0;

    // int status;
    // status = initApp(argc, argv);

    // return status;

}
