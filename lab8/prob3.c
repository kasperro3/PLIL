#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define size 10

int *find_max(int array[], int arraySize);

int main(void)
{
    srand(time(0));
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand();
        printf("%d\n", arr[i]);
    }
    printf("Maximum from the array: %d\n", *find_max(&arr[0], size));
}

int *find_max(int *array, int arraySize)
{
    int *ptr;
    int max = (int) -INFINITY;
    for(int i = 0; i < arraySize; i++)
    {
        if(*(array + i) > max)
        {
            // assing address of max value to the ptr which is returned
            ptr = (array + i);
            // assing new max value
            max = *(array + i);
        }

    }

    return ptr;
}