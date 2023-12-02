#include <stdio.h>

int how_many_bills(int amount, int bill);

int main(void)
{
    int money = 412;

    // print out every denomination
    money = how_many_bills(money, 50);
    money = how_many_bills(money, 20);
    money = how_many_bills(money, 5);
    money = how_many_bills(money, 1);

    return 0;
}

// returns how many ${bill} bills can fit in a given amount
int how_many_bills(int amount, int bill)
{
    int count = 0;

    // iterate until no more ${bill} bills can fit in a given amount
    while (amount - bill >= 0)
    {
        amount -= bill;
        count++;
    }

    // print out how many {bill} dolar bills can fit in a given amount
    printf("%i of %i dollar bills\n", count, bill);
    // return an amount left
    return amount;
}