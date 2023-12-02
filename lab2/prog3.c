#include <stdio.h>

int main()
{
    int a = -7, b = -6, c = -9;
    int ab_max, bc_max, max;

    // get max from a and b
    ab_max = a*(a>b)+b*(b>=a);
    // get max from b and c
    bc_max = b*(b>c)+c*(c>=b);

    // get max from two variables 
    // that contain max from each pair 
    max = ab_max*(ab_max>bc_max) + bc_max*(bc_max>=ab_max);

    printf("%i\n", max);

    return 0;
}