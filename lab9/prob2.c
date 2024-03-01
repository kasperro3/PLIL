#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxLength 100

int main(void)
{
    // allocate memory for two strings with maxLength
    char *first = malloc(maxLength);
    char *second = malloc(maxLength);

    printf("Enter first string: ");
    fgets(first, sizeof(first), stdin);

    printf("Enter second string: ");
    fgets(second, sizeof(second), stdin);

    int lengthF = strlen(first);
    int lengthS = strlen(second);

    // allocate memory for result knowing lengths of two original strings + one for \0
    char *result = malloc((lengthF + lengthS + 1));

    // in order to connect two strings together we need to remove endline character from both strings
    // (they are here from fgets() I think)
    *strchr(first, '\n') = ' ';
    *strchr(second, '\n') = 0;
    
    // concatenate first and then second string with result, to create one long string
    strcat(result, first);
    strcat(result, second);

    printf("Result: %s\n", result);

    free(result);
    free(first);
    free(second);
    return 0;
}