#include <stdio.h>
#include <string.h>
#include <ctype.h>

void withdraw(float* balanceUSD, float* balancePLN);
void put(float* balanceUSD, float* balancePLN);
void check(float balanceUSD, float balancePLN);
void convert(float* balanceUSD, float* balancePLN);

int main(void)
{
    float balanceUSD = 0;
    float balancePLN = 5467.00;
    char inpt;
    
    printf("W - withdraw the money\n");
    printf("P - put the money into account\n");
    printf("C - check the statement\n");
    printf("V - convert from USD to PLN or vice versa.\n");
    printf("E - exit\n");

    scanf(" %c", &inpt);

    switch(inpt)
    {
        case 'W':
            withdraw(&balanceUSD, &balancePLN);
            break;
        case 'P':
            put(&balanceUSD, &balancePLN);
            break;
        case 'C':
            check(balanceUSD, balancePLN);
            break;
        case 'V':
            convert(&balanceUSD, &balancePLN);
            break;
        case 'E':
            return 0;
            break;
        default:
            printf("Unknown input\n");
            return 1;
            break;
    }
}

void withdraw(float* balanceUSD, float* balancePLN)
{
    int input;
    float inptAmount;

    printf("1 - for PLN, 2 - for USD: \n");
    scanf(" %i", &input);

    printf("Enter amount to withdraw: \n");
    scanf(" %f", &inptAmount);

    if (inptAmount <= 0)
    {
        printf("Can't withdraw negative amount or 0\n");
    }

    switch (input)
    {
        case 1:

            if (*balancePLN >= inptAmount)
            {
                *balancePLN -= inptAmount;
                printf("Withdrawal succesful!\n");
            }
            else
            {
                printf("Not enough money!\n");
                return;
            }
            break;
        case 2:
            if (*balanceUSD >= inptAmount)
            {
                *balanceUSD -= inptAmount;
                printf("Withdrawal succesful!\n");
            }
            else
            {
                printf("Not enough money!\n");
                return;
            }
            break;
        default:
            printf("No such currency!\n");
            break;
    }
    
}
void put(float* balanceUSD, float* balancePLN)
{

    int input;
    float inptAmount;

    printf("1 - for PLN, 2 - for USD: \n");
    scanf(" %i", &input);

    printf("Enter amount to put: \n");
    scanf(" %f", &inptAmount);

    if (inptAmount <= 0)
    {
        printf("Can't put negative amount or 0\n");
    }

    switch (input)
    {
        case 1:
            *balancePLN += inptAmount;
            break;
        case 2:
            *balanceUSD += inptAmount;
            break;
        default:
            printf("No such currency!\n");
            break;
    }
}
void check(float balanceUSD, float balancePLN)
{
    printf("USD balance: %.2f\n", balanceUSD);
    printf("PLN balance: %.2f\n", balancePLN);
}
void convert(float* balanceUSD, float* balancePLN)
{
    int input;
    printf("USD balance: %f\n", *balanceUSD);
    printf("PLN balance: %f\n", *balancePLN);

    printf("1 - PLN to USD\n");
    printf("2 - USD to PLN\n");

    printf("Choose conversion direction: \n");
    scanf(" %i", &input);

    printf("Amount to be converted: \n");
    float amount;
    scanf(" %f", &amount);

    if (amount <= 0)
    {
        printf("Can't convert negative amount or 0\n");
    }

    switch(input)
    {
        case 1:
            if(*balancePLN >= amount)
            {
                *balanceUSD +=  amount * 0.24;
                printf("Conversion sucessfull!\n");
            }
            else
            {
                printf("Not enough money!\n");
            }
            break;
        case 2:
            if (*balanceUSD >= amount)
            {
                *balancePLN += (float) amount * 4.18;
                printf("Conversion sucessfull!\n");
            }
            else
            {
                printf("Not enough money!\n");
            }
            break;
        default:
            printf("No such currency!\n");
            break;
    }
}
