#include <stdio.h>

int main(void)
{
    printf("Size of int in bits: %i\n", sizeof(int) * 8);
    printf("Size of int in bytes: %i\n", sizeof(int));
    printf("Size of float in bits: %i\n", sizeof(float) * 8);
    printf("Size of float in bytes: %i\n", sizeof(float));
    printf("Size of double in bits: %i\n", sizeof(double) * 8);
    printf("Size of double in bytes: %i\n", sizeof(double));
    printf("Size of long int in bits: %i\n", sizeof(long int) * 8);
    printf("Size of long int in bytes: %i\n", sizeof(long int));
    printf("Size of char in bits: %i\n", sizeof(char) * 8);
    printf("Size of char in bytes: %i\n", sizeof(char));

    return 0;
}
