#include <stdio.h>
#include <stdlib.h>

// array that holds numbers that compose our N
int numbers[200];
void partition(int sum, int max, int index);

int main(void)
{
    int numberToPartition = 3;

    partition(numberToPartition, numberToPartition, 1);
}

void partition(int sum, int max, int index)
{
    // everytime that remaining sum is equal to 0 we reached sum (within the array)
    // so we print the numbers that are in the array and those numbers create one of our possibilities
    if(sum == 0)
    {
        for(int i = 1; i < index; i++)
        {
            printf("%d ", numbers[i]);
        }
        printf("\n");

        return;
    }

    // if i can be substracted from our value we add it to the array
    for (int i = max; i >= 1; i--)
    {
        if (i <= sum)
        {
            numbers[index] = i;
            // to check if there is more numbers in this posibility we need to run the function again
            // this time with i substracted from the remaining sum and i as the maximum value
            // so we get the maximum value that fits within the new (sum - i) 
            partition(sum - i, i, index + 1);
        }
    }
}
