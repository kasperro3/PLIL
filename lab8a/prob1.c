
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

void swap (int *inputArray, int leftIndex, int rightIndex);

int main(void)
{
    // set rand seed as current time
    srand(time(0));

    int arr[N];

    // fill and print the array
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % (2000 - 0) + 0;
        printf("%d\n", arr[i]);
    }

    swap(arr, 0, N - 1);
    printf("POST SWAP\n");
    
    for (int i = 0; i < N; i++)
    {
        printf("%d\n", arr[i]);
    }
}

// this function does not work on an array, it only works on two elements that are indicated (pointed on) by leftIndex and rightIndex (combined with pointer inputArray)
// to know the exact position of the element IN the array we add inputArray (which points to the first element) and one of the indexes
// knowing their position we now can swap them as below

// swapping array recursivly, each level of recursion swaps leftIndex and rightIndex 
// until they meet or leftIndex is grater then rightIndex (for odd arrays it indicates that everything was swapped)
void swap (int *inputArray, int leftIndex, int rightIndex)
{
    int temp = *(inputArray + leftIndex);
    *(inputArray + leftIndex) = *(inputArray + rightIndex);
    *(inputArray + rightIndex) = temp;

    // other possibility without temp
    // inputArray[leftIndex] is the same as *(inputArray + leftIndex) this can also be applied above
    // inputArray[leftIndex] += inputArray[rightIndex];
    // inputArray[rightIndex] = inputArray[leftIndex] - inputArray[rightIndex];
    // inputArray[rightIndex] = inputArray[leftIndex] - inputArray[rightIndex];

    leftIndex++;
    rightIndex--;
    if (rightIndex <= leftIndex)
        return;
    else
        swap(inputArray, leftIndex, rightIndex);
}