#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getSize();
void pyramid(int rows);

int main(void)
{
    int size = getSize();

    pyramid(size);

    return 0;
}

// ensures valid input from user
int getSize()
{
    int input = 0;
    printf("Size of the pyramid: ");
    scanf("%d", &input);

    while (input <= 0)
    {
        printf("Provide valid size: ");
        scanf("%d", &input);
    }

    return input;
}

void pyramid(int rows)
{
    char *pyramid = malloc(rows + 2);
    memset(pyramid, ' ', rows + 2);

    for(int i = 0; i < rows; i++)
    {
        pyramid = realloc(pyramid, rows + 4 + i);
        pyramid[rows + 4 + i - 1] = '\0';
        pyramid[rows + 4 + i - 2] = '#';
        pyramid[rows - 1 - i] = '#';

        printf("%s\n", pyramid);
    }

    free(pyramid);
}