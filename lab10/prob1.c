#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void floatSwap(float* a, float* b);

int main(void)
{
    srand(time(0));
    float x = ((float) rand() / (float) RAND_MAX), y = ((float) rand() / (float) RAND_MAX);

    printf("Pre-swap\n");
    printf("Float 1: %.3f\n", x);
    printf("Float 2: %.3f\n", y);

    floatSwap(&x, &y);

    printf("Post-swap\n");  
    printf("Float 1: %.3f\n", x);
    printf("Float 2: %.3f\n", y);
}


void floatSwap(float* a, float* b)
{
    // a contains a and b
    *a = *a + *b;
    // now b contains just (original) a
    *b = *a - *b;
    // now a contains  just (original) b
    *a = *a - *b;
}