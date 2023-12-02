// Declare an array representing the average daily temperarure in July as JulT emp. Fill it with
// random values between 18 and 28 DEG Celsius for each day. Calculate for the whole month the
// mean, the median value and the standard deviation. Print your results.

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define JULDAYS 30

float randomFloat(float mini, float maxi);
float mean(float days[], int arrSize);
float median(float days[], int arrSize);
float stdDev(float temps[], int arrSize);

int main(void)
{
    float JulTemp[JULDAYS];

    srand(time(0));
    for (int i = 0; i < JULDAYS; i++)
    {
        JulTemp[i] = randomFloat(18.0, 28.0);
    }

    float meanJul = mean(JulTemp, JULDAYS);
    float medianJul = median(JulTemp, JULDAYS);
    float stdDeviation = stdDev(JulTemp, JULDAYS);

    printf("Mean: %.1f\n", meanJul);
    printf("Median: %1.f\n", medianJul);
    printf("Standard deviation %.5f\n", stdDeviation);

}

float stdDev(float temps[], int arrSize)
{
    float setMean = mean(temps, arrSize), sigma = 0;

    for (int i = 0; i < arrSize; i++)
    {
        sigma += pow(temps[i] - setMean, 2);
    }

    return sqrt(sigma / arrSize);
}

float mean(float days[], int arrSize)
{
    float sum = 0;
    for (int i = 0; i < arrSize; i++)
    {
        sum += days[i];
    } 

    return sum / arrSize;  
}

float median(float days[], int arrSize)
{
    float sorted[arrSize];

    for (int i = 0; i < arrSize; i++)
    {
        sorted[i] = days[i];
    }

    for (int i = 0; i < arrSize; i++)
    {
        for (int j = i + 1; j < arrSize; j++)
        {
            if (sorted[i] > sorted[j])
            {
                int temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;            
            }
        }
    }

    if (arrSize % 2 == 0)
        return ((sorted[arrSize / 2] + sorted[arrSize / 2 + 1]) / 2);
    else
        return (sorted[arrSize / 2]);
}

float randomFloat(float mini, float maxi)
{
    return ((maxi - mini) * ((float)rand() / RAND_MAX)) + mini;
}