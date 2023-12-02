#include <stdio.h>

int main(void)
{
    for (int f = -50; f <= 200; f += 10)
    {
        printf("F: %i C: %.2f\n", f, (float) 5 / 9 * (f - 32));
    }   
}