#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define size 6

void reverseArray(int *array, int arraySize);

int main(void)
{
    srand(time(0));
    int arr[size];

    printf("Pre-swap\n");
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand();
        printf("%d\n", arr[i]);
    }

    // passing a pointer to the first element of array
    reverseArray(arr, size);

    printf("Post-swap\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
}

void reverseArray(int *array, int arraySize)
{
    // swap elements (first - last) every iteration increase first and decrease last by i
    for(int i = 0, *last = array + arraySize - 1, temp; i < arraySize / 2; i++, array++)
    {
        temp = *array;
        *array = *(last - i);
        *(last - i) = temp;
    }
}