#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TRDAYS 500
#define PLAYERNR 4

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
        priceHistory[i] = priceHistory[i - 1] * random * 100.0;

        for (int i = 0; i < PLAYERNR; i++)
        {
            int value = rand() % 99 + 1;

            if (value < 50)
                buy(&players[i], priceHistory[i]);
            else
                sell(&players[i], priceHistory[i]);
        }
    }

    for(int i = 0; i < PLAYERNR; i++)
    {
        printf("%f\n", players[i].money);
        printf("%i\n", players[i].stocks);
    }
}

void buy(Player *player, double price)
{
    player->money += 1.0;
}

void sell(Player *player, double price)
{
    player->stocks += 1;
}


