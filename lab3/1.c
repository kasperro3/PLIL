#include <stdio.h>

int main(void)
{
    int input;

    printf("Enter score from class: ");
    scanf("%i", &input);

    //define what grade should be rewarded
    if (input > 100 || input < 0)
    {
        printf("Invalid input\n");
    }
    else if (input < 60)
    {
        printf("F\n");
    }
    else if (input < 70)
    {
        printf("D\n");
    }
    else if (input < 80)
    {
        printf("C\n");
    }
    else if (input < 90)
    {
        printf("B\n");
    }
    else if (input < 100)
    {
        printf("A\n");
    }
    else
    {
        printf("A+\n");
    }

    return 0;
}