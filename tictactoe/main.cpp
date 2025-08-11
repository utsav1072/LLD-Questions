#include <bits/stdc++.h>
#include "includes/game.h"
#include "includes/player.h"
using namespace std;

int main(){
    Player* player1 = new Player("utsav", 1);
    Player* player2 = new Player("Abhishek", 2);
    Game game(player1, player2);
    game.play();
    return 0;
}