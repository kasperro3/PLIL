#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 5

int *findMax(int *array, int arraySize);

int main(void)
{
    int array[SIZE];

    srand(time(0));
    for(int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % 1000;
        printf("%d\n", array[i]);
    }

    printf("Maxiumum from the array: %d\n", *(findMax(array, SIZE)));
}

int *findMax(int *array, int arraySize)
{
    int max = (int) -INFINITY;
    int *result;

    for(int i = 0; i < arraySize; i++)
    {
        if(array[i] > max)
        {
            max = array[i];
            result = array + i;
        }
    }

    return result;
}