#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tradestocks.h"

// player buys stocks
void buy(Player *player, double price)
{
    int maxToBuy = player->money / price;
    if (maxToBuy == 0)
        return;
    int amount = rand () % maxToBuy + 1;

    player->stocks += amount;
    player->money -= amount * price;
}

// player sells stocks
void sell(Player *player, double price)
{
    int maxToSell = player->stocks;
    if (maxToSell == 0)
        return;
    int amount = rand () % maxToSell + 1;

    player->stocks -= amount;
    player->money += amount * price;
}

