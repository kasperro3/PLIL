#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5

void reverseArray(int* array , int arraySize);

int main(void)
{
    int array[SIZE];

    printf("Pre-reverse\n");
    srand(time(0));
    for(int i = 0; i < SIZE; i++)
    {
        array[i] = rand();
        printf("%d\n", array[i]);
    }

    reverseArray(array, SIZE);

    printf("Post-reverse\n");
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d\n", array[i]);
    }
}

void reverseArray(int* array , int arraySize)
{
    int last = arraySize - 1;
    int temp;

    for(int i = 0, n = arraySize / 2; i < n; i++)
    {
        temp = array[i];
        array[i] = array[last - i];
        array[last - i] = temp;
    }
}