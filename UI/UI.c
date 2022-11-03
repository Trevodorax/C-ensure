#ifndef _UI_H_
#include "./UI.h"
#endif

void printMenu(
    char appState
)
{
    // leading phrase according to appState
    if(appState == 'a')
    {
        printf("\nEnter the phrase you want to censor.");
    }

    if(appState == 'm')
    {
        printf("\nEnter the message you want to send.");
    }

    if(appState == 'r')
    {
        printf("\nEnter the word you want to remove from dictionary.");
    }

    // lists all other possibilities than current state
    if(appState != 'a')
    {
        printf("\nEnter \"add\" to add words to your censored words dictionary.");
    }

    if(appState != 'm')
    {
        printf("\nEnter \"message\" to write messages.");
    }

    if(appState != 'r')
    {
        printf("\nEnter \"remove\" to remove words from dictionary.");
    }

    printf("\nEnter \"stop\" to close the program.\n\n");

}


char * getInputString(
    // defines if getting input stops at space or line break
    int getWordOnly 
)
{
    // stores the user input
    char * inputString = malloc(0);
    size_t inputStringSize = 0;

    char nextChar;

    while(1)
    {
        // for each char in input, add a space to store it
        inputString = realloc(inputString, sizeof(char) * (inputStringSize + 1));
        nextChar = fgetc(stdin);

        // exit condition (line break or space)
        if(nextChar == '\n' || (getWordOnly && nextChar == ' ')) 
        { 
            *(inputString + inputStringSize) = '\0';
            break; 
        }

        *(inputString + inputStringSize) = nextChar;

        inputStringSize++;
    }

    return inputString;
}