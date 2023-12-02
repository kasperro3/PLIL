#include <stdio.h>
#include <math.h>

int main(void)
{
    int number, sum = 0, remainder, number_inpt;

    printf("Enter number: ");
    scanf("%i", &number_inpt);

    number = number_inpt;

    // separate number into digits
    while (number > 0)
    {
        // get a units digit
        remainder = number % 10;
        // add power of a single digit to a sum
        sum = sum + pow(remainder, 3);
        
        // remove last digit from the number
        number = number / 10;
    }

    if (sum != number_inpt)
    {
        printf("Number is not Armstrong\n");
    }
    else
    {
        printf("Number is Armstrong\n");
    }

    return 0;
}