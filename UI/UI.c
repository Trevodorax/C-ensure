#ifndef _UI_H_
#include "./UI.h"
#endif

void printMenu(
    char appState
)
{
    if(appState == 'a')
    {
        printf("\nEnter the phrase you want to censor.");
    };

    if(appState == 'm')
    {
        printf("\nEnter the message you want to send.");
    };

    if(appState != 'a')
    {
        printf("\nEnter \"add\" to add words to your censored words dictionary.");
    }

    if(appState != 'm')
    {
        printf("\nEnter \"message\" to write messages.");
    }

    printf("\nEnter \"stop\" to close the program.\n\n");

}


char * getInputString()
{
    char * inputString = malloc(0);
    size_t inputStringSize = 0;
    char nextChar;

    while(1)
    {
        inputString = realloc(inputString, sizeof(char) * (inputStringSize + 1));
        nextChar = fgetc(stdin);
        if(nextChar == '\n') 
        { 
            *(inputString + inputStringSize) = '\0';
            break; 
        }

        *(inputString + inputStringSize) = nextChar;

        inputStringSize++;
    }

    return inputString;
}