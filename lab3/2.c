#include <stdio.h>

int main(void)
{
    int angle_count = 3;
    int angles[angle_count];

    //initialize a pointer to first cell of an array
    int *a = &angles[0];
    printf("Enter three angles:");
    scanf("%i%i%i", a, a + 1, a+2);

    int sum = 0;

    //check for incorrect angles and sum all angles
    for(int i = 0; i < 3;i++)
    {
        if (angles[i] <= 0)
        {
            printf("Angle can not be negative\n");
            return 0;
        }

        sum += angles[i];
    }

    // based on a sum of angles determine if triangle can be formed
    if (sum != 180)
    {
        printf("Triangle can not be formed from given angles\n");
    }
    else
    {
        printf("Triangle can be formed\n");
    }

    return 0;
}