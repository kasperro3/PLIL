#ifndef TRADESTOCKS_H
    #define TRADESTOCKS_H

    #define TRDAYS 500
    #define PLAYERNR 6

    typedef struct Player
    {
        double money;
        int stocks;
        double wealth;

    } Player;

    void buy(Player *player, double price);
    void sell(Player *player, double price);
#endif