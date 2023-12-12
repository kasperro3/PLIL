#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int getSize();
void printPascals(int size, int **cache);
int pascals(int column, int row, int **cache);

int main(void)
{
    int size = getSize();
    int **cache = (int**) malloc(size + 1 * sizeof(int));

    for (int i = 0; i < size; i++)
        cache[i] = malloc((i + 1) * sizeof(int));

    // initiate computed with zero for ease of use
    for (int i = 0; i < size; i++)
    {   
        for (int j = 0; j < i + 1; j++)
            cache[i][j] = 0;
    }


    printPascals(size, cache);

    for (int i = 0; i < size; i++)
        free(cache[i]);

    free(cache);
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
int pascals(int row, int column, int **cache) 
{ 
    if (column == 0 || column == row)
    {
        cache[row][column] = 1;
        return 1;
    }
    else if (cache[row][column] != 0)
        return cache[row][column];
    else
    {
        cache[row][column] = pascals(row - 1, column, cache) + pascals(row - 1, column - 1, cache);
        return cache[row][column];
    }

}

void printPascals(int size, int **cache)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < i + 1; j++)
        {
            printf("%d ", pascals(i, j, cache));
        }
        printf("\n");
    }
}
