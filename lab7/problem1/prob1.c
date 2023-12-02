#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "tradestocks.h"

void bubble_sort();
double find_min();
double find_max();

Player players[PLAYERNR];

int main(void)
{
    // generate players
    for (int i = 0; i < PLAYERNR; i++)
    {
        Player player;
        player.money = 100.0;
        player.stocks = 5;
        player.wealth = 0;

        players[i] = player;
    }

    double priceHistory[TRDAYS];
    double initPrice = 13.9;

    priceHistory[0] = initPrice;

    srand(time(0));
    for (int i = 1; i < TRDAYS; i++)
    {
        // fill array with random price (90-110% of prev day price)
        double random = (rand() % 21 + 90) / 100.0;
        priceHistory[i] = priceHistory[i - 1] * random;

        // randomise selling or buying of each player
        for (int j = 0; j < PLAYERNR; j++)
        {
            int value = rand() % 99 + 1;

            if (value < 50)
                buy(&players[j], priceHistory[i]);
            else
                sell(&players[j], priceHistory[i]);
        }
    }

    for(int i = 0; i < PLAYERNR; i++)
    {
        // calculate players wealth at the end of trading
        players[i].wealth = players[i].money + players[i].stocks * priceHistory[TRDAYS - 1];
    }

    printf("Unsorted\n");
    for (int i = 0; i < PLAYERNR; i++)
    {
        printf("%i. %.2f\n", i + 1, players[i].wealth);
    }

    bubble_sort();

    printf("Sorted\n");
    for (int i = 0; i < PLAYERNR; i++)
    {
        printf("%i. %.2f\n", i + 1, players[i].wealth);
    }

    printf("Maximum wealth: %.2f\n", find_max());
    printf("Minimum wealth: %.2f\n", find_min());

}

void bubble_sort()
{
    for (int i = 0; i < PLAYERNR - 1; i++)
    {
        for (int j = i + 1; j < PLAYERNR; j++)
        {
            if(players[i].wealth < players[j].wealth)
            {
                Player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }
}

double find_min()
{
    double min = INFINITY;

    for (int i = 0; i < PLAYERNR; i++)
    {
        if (players[i].wealth < min)
            min = players[i].wealth;
    }

    return min;
}

double find_max()
{
    double max = 0.0;

    for (int i = 0; i < PLAYERNR; i++)
    {
        if (players[i].wealth > max)
            max = players[i].wealth;
    }

    return max;
}


