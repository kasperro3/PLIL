#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float randomFloat(float min, float max);
void floatSwap(float *a, float *b);

int main(void)
{
    srand(time(0));
    float mini = 0, maxi = 10;

    float v1 = randomFloat(mini, maxi), v2 = randomFloat(mini, maxi);
    printf("Pre-swap\n");
    printf("Value 1: %.3f\n", v1);
    printf("Value 2: %.3f\n", v2);
    floatSwap(&v1, &v2);
    printf("After-swap\n");
    printf("Value 1: %.3f\n", v1);
    printf("Value 2: %.3f\n", v2);
}

void floatSwap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

float randomFloat(float min, float max)
{
    // generate random float
    float random = (float) rand() / (float) RAND_MAX;

    // make it in range [min, max]
    return max - random * (max - min);
}