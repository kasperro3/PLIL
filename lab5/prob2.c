#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// n is accuracy
// the higher the n the higher the accuracy

float function(float x);
float find_0(float (*function_to_find)(float), float a, float b, float n);

int main(void)
{
    printf("%.3f\n", find_0(function, -3, 0, 100));
}

float find_0(float (*function_to_find)(float), float a, float b, float n)
{
    float c;

    for (int i = 1; i <= n; i++)
    {
        // get the middle
        c = (float) ((a + b) / 2.0);

        // check if values of a function of a and c have opposite signs
        if (function_to_find(a) * function_to_find(c) < 1e-9)
            // if f(a) and f(c) have different signs make range smaller from b side
            b = c;
        else
            // if f(a) and f(c) have same signs make range smaller from a side
            a = c;
    }
    return c;
}

// here put any (monotonous) function that you want to find a root of
float function(float x)
{
    return 3 * pow(x, 2) - 8;
}
