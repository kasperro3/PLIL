#include <stdio.h>

int main(void)
{
    int kwh;
    float price = 0;

    printf("Input power usage in kWh: ");
    scanf("%i", &kwh);

    // add amount due for execess above 5000
    if (kwh > 5000)
    {
        price += (kwh - 5000) * 2.3;
        kwh -= kwh - 5000;
    }

    // add amount due for execess above 2000
    if (kwh > 2000)
    {
        price += (kwh - 2000) * 1.55;
        kwh -= kwh - 2000;
    }

    // add amount due for standard limit
    price += kwh * 0.96;


    printf("%.3f\n", price);

}