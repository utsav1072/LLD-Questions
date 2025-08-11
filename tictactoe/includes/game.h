#ifndef GAME_H
#define GAME_H

#include<bits/stdc++.h>
#include "player.h"
#include "board.h"
using namespace std;

class Game{
    private:
        Player *p1;
        Player *p2;
        Player* winner;
        Board* board;
        bool draw;
    public:
        Game(Player *p1, Player *p2);
        void play();
        string getWinner();
        MoveResult playTurn(Player* player, int move);
};

#endif