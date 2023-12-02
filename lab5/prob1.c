#include <stdio.h>
#include <math.h>

// n is accuracy
// the higher the n the higher the accuracy

float integrate(float (*function_to_integrate)(float), float n, float a, float b);
float function(float x);
float poly(float x);


int main(void)
{
    printf("%.3f\n", integrate(function, 1000000, 0, 10));
}

float integrate(float (*function_to_integrate)(float), float n, float a, float b)
{
    float delta_x = (b - a) / n;
    float f;
    float result = 0.0;

    for (int i = 1; i <= n; i += 1)
    {
        // one result of a function
        f = (*function_to_integrate)(a + (i - 0.5) * delta_x);
        // sum the result
        result += f * delta_x;
    }

    return result;
}

// polynomial function to integrate
float poly(float x)
{
    return pow(x, 3) + pow(x, 4) + x;
}

// here put a function that you want to integrate
// for ex. poly(x) or sin(x)
float function(float x)
{
    return sin(x);
}
