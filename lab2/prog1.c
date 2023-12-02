#include <stdio.h>
#include <math.h>

int main(void)
{
    float height = 12.4, base = 18.61, hypotenuse;

    area = (height * base) / 2;
    //apply pythagorean theorem
    hypotenuse = (float) sqrt(((height * height) + (base * base)));

    printf("%.3f\n", area);
    printf("%.3f\n", hypotenuse);

    return 0;
}