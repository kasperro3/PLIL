#include <stdio.h>
#include <stdlib.h>

int getSize();
void printPascals(int size);
int pascals(int column, int row);

int main(void)
{
    int size = getSize();
    printPascals(size);
}

// ensures valid input from user
int getSize()
{
    int input = 0;
    printf("Size of triangle: ");
    scanf("%d", &input);

    while (input <= 0)
    {
        printf("\nProvide valid size: ");
        scanf("%d", &input);
    }

    return input;
}

// uses recursive formula to generate pascals triangle numbers
int pascals(int column, int row) 
{ 
    if(column == 1 || column == row)
        return 1;
    else
        return pascals(column, row - 1) + pascals(column - 1, row - 1);
}

void printPascals(int size)
{
    for(int i = 0; i < size; i++)
    {
        for (int space = 1; space <= size - i; space++) 
            printf("  ");
        for(int j = 0; j <= i; j ++)
        {
            printf("%4d", pascals(j + 1, i + 1));
        }
        printf("\n");
    }
}
