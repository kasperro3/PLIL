#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TRDAYS 500
#define PLAYERNR 6

typedef struct Player
{
    double money;
    int stocks;
} Player;

Player players[PLAYERNR];

void buy(Player *player, double price);
void sell(Player *player, double price);


int main(void)
{
    for (int i = 0; i < PLAYERNR; i++)
    {
        Player player;
        player.money = 100.0;
        player.stocks = 5;

        players[i] = player;
    }

    double priceHistory[TRDAYS];
    double initPrice = 13.9;

    priceHistory[0] = initPrice;

    srand(time(0));
    for (int i = 1; i < TRDAYS; i++)
    {
        double random = (rand() % 21 + 90) / 100.0;
        priceHistory[i] = priceHistory[i - 1] * random;

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
        printf("Total wealth of player %i: %.2f$\n",i + 1, players[i].money + players[i].stocks * priceHistory[TRDAYS - 1]);
    }
}

void buy(Player *player, double price)
{
    int maxToBuy = player->money / price;
    if (maxToBuy == 0)
        return;
    int amount = rand () % maxToBuy + 1;

    player->stocks += amount;
    player->money -= amount * price;
}

void sell(Player *player, double price)
{
    int maxToSell = player->stocks;
    if (maxToSell == 0)
        return;
    int amount = rand () % maxToSell + 1;

    player->stocks -= amount;
    player->money += amount * price;
}


