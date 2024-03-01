#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getSize();
double averageValue(double *array, int n);

int main(void)
{
    int size = getSize();
    double *array = malloc(size * sizeof(double));

    srand(time(0));

    // check allocation
    if (array != NULL)
    {
        for (int i = 0; i < size; i++)
        {
            array[i] = ((double) rand() * 10) / RAND_MAX;
        }

        averageValue(array, size);
    }   
    else
    {
        printf("Allocation error\n");
        return 1;
    }

    free(array);
    return 0;
}

// ensures valid input from user
int getSize()
{
    int input = 0;
    printf("Size of the array: ");
    scanf("%d", &input);

    while (input <= 0)
    {
        printf("Provide valid size: ");
        scanf("%d", &input);
    }

    return input;
}

double averageValue(double *array, int n)
{
    double sum = 0.0;

    for(int i = 0; i < n; i++)
    {   
        sum += array[i];
        printf("%lf\n", array[i]);
    }

    
    printf("Average: %lf\n", sum / n);
    return sum / n;
}