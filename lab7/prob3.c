#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int val1 = 50, val2;

    //a
    int *intPtr;
    //b
    intPtr = &val1;
    //c
    printf("Value intPtr points to: %d\n", *intPtr);
    //d
    val2 = *intPtr;

    printf("value2: %d\n", val2);
    printf("value1 address: %d\n", &val1);
    printf("intPtr: %d\n", intPtr);
}