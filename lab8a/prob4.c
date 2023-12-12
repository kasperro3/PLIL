#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 5

int binSearch(int x, int *arr, int left, int right);

int main(void)
{
    srand(time(0));

    int arr[size];
    arr[0] = 0;
    int random = rand();

    for(int i = 1; i < size; i++)
    {
        arr[i] = arr[i-1] + random;
        printf("%d\n",arr[i]);
    }

    int search = arr[rand() % size];
    printf("Searching for %d\n", search);
    printf("Found at %d\n", binSearch(search, arr, 0, size));
}

int binSearch(int x, int *arr, int left, int right)
{
    int mid = (left + right) / 2; 
    if (arr[mid] == x)
        return mid;
    else if (arr[mid] > x)
        return binSearch(x, arr, left, mid);
    else
        return binSearch(x, arr, mid, right);
}