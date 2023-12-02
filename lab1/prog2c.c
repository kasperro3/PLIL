#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s = "Kacper";

    // prints out numbers that correspond to each char
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%i\n", s[i]);
    }

    return 0;
}