#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TRDAYS 500

double find_min(double array[], int size);
double find_max(double array[], int size);

int main(void)
{
    double priceHistory[TRDAYS];
    double initPrice = 13.9;

    priceHistory[0] = initPrice;

    srand(time(0));
    for (int i = 1; i < TRDAYS; i++)
    {
        double random = (rand() % 21 + 90) / 100.0;
        priceHistory[i] = priceHistory[i - 1] * random;
    }

    printf("Minimum price was: %f$\n", find_min(priceHistory, TRDAYS));
    printf("Maximum price was: %f$\n", find_max(priceHistory, TRDAYS));

    
}

double find_min(double array[], int size)
{
    double min = INFINITY;

    for (int i = 0; i < size; i++)
    {
        if (array[i] < min)
            min = array[i];
    }

    return min;
}

double find_max(double array[], int size)
{
    double max = 0.0;

    for (int i = 0; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}
