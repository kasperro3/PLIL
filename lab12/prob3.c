#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 3

void fill(float array[SIZE][SIZE]);
void print(float array[SIZE][SIZE]);
void add(float array1[SIZE][SIZE], float array2[SIZE][SIZE], float result[SIZE][SIZE]);
void multiply(float array1[SIZE][SIZE], float array2[SIZE][SIZE], float result[SIZE][SIZE]);
float trace(float array1[SIZE][SIZE]);

int main(void)
{
    srand(time(0));
    float arr1[SIZE][SIZE], arr2[SIZE][SIZE], result[SIZE][SIZE];

    fill(arr1);
    fill(arr2);

    printf("Array 1:\n");
    print(arr1);

    printf("Array 2:\n");
    print(arr2);

    printf("Trace of A: %.3f\n", trace(arr1));
    printf("Trace of B: %.3f\n", trace(arr2));
    add(arr1, arr2, result);
    printf("Trace of A + B: %.3f\n", trace(result));

}

void fill(float array[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            array[i][j] = (float) rand() * 10 / (float) RAND_MAX;
    }   
}

void print(float array[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            printf("%.3f ", array[i][j]);
        printf("\n");
    }  
}

void add(float array1[SIZE][SIZE], float array2[SIZE][SIZE], float result[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            result[i][j] = array1[i][j] + array2[i][j];
    } 
}

void multiply(float array1[SIZE][SIZE], float array2[SIZE][SIZE], float result[SIZE][SIZE])
{
    float sum;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            sum = 0;
            for(int x = 0; x < SIZE; x++)
            {
                sum += array1[i][x] * array2[x][j];
            }

            result[i][j] = sum;
        }
    } 
}

float trace(float array1[SIZE][SIZE])
{
    float sum = 0;

    for (int i = 0; i < SIZE; i++)
        sum += array1[i][i];

    return sum;
}