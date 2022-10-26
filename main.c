#include "./main.h"


int main(int argc, char ** argv)
{
    int status;
    status = initApp(argc, argv);

    return status;

    // char ** dictionary = malloc(0);
    // size_t dictionarySize = 0;

    // addToDictionary(&dictionary, &dictionarySize, "Paul");
    // addToDictionary(&dictionary, &dictionarySize, "Loubna");
    // addToDictionary(&dictionary, &dictionarySize, "amour");

    // printf("\n%s", censorMessage("Paul is in love with Loubna (il a beaucoup d'amour!!)", dictionary, dictionarySize));

    // printf("\n");

    // return 0;
}

