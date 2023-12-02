#include <stdio.h>

int main(void)
{
    int age = 20;

    printf("Age in days: %i\n", age * 365);
    printf("Age in hours: %i\n", age * 365 * 24);
    printf("Age in minutes: %i\n", age * 365 * 24 * 60);
    printf("Age in seconds: %i\n", age * 365 * 24 * 60 * 60);

    return 0;
}