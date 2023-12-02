#include <stdio.h>

void tower(int n);
void print_level(int count);

int main(void)
{
    int numberOfRows = 0;

    printf("Number of desired rows: ");
    scanf("%i", &numberOfRows);

    tower(numberOfRows);
}

void tower(int n)
{
    int level = 1;

    while (level <= n)
    {
        // print blanks
        for (int i = 1; i <= n - level; i++)
            printf(" ");

        //print left side
        print_level(level);

        // print gap
        printf("  ");

        //print right side
        print_level(level);

        // advance to the next level
        printf("\n");

        level++;
    }
}

void print_level(int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("#");
    }
}



