# Stuff to do in this project

## Bugs
There is a memory leak in struct version, check if it exists in previous version too

## Code quality
* Lacking error and null handling
* Lacking comments
* Turn dictionary and dictionarySize into a struct
* Transform some functions and put them in utils for later use

## Features
### Prevent duplication in dictionary
#### utils/utils.c
int isInArray(char ** array, size_t arraySize, const char * word);
- returns -1 if not in array or the index if it is in array
#### dictionary/dictionary.c
addToDictionary
add condition that prevents adding if the word is already in dictionary
### Remove words from words list
#### utils/utils.c
int isInArray(char ** array, size_t arraySize, const char * word);
-returns -1 if not in array or the index if it is in array
#### dictionary/dictionary.c
void deleteFromDictionary(char *** dictionary, size_t * dictionarySize, const char * word)
- if word is in dictionary, remove it by reference
- reduce the size of the dictionary by 1 by reference
