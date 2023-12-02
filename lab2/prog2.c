#include <stdio.h>

int main(void)
{
    int distance = 107;
    float liters = 13.19;

    //calculate consumption per km
    float consumption = liters / distance;

    printf("%.3f l/km\n", consumption);
    printf("%.3f l/100km\n", consumption * 100);

    return 0;
}