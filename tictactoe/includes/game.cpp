#include "game.h"


string Game::getWinner(){
    if(!draw){
        return winner->showName();
    }
    return "Draw";
}

Game::Game(Player* p1, Player* p2)
    : p1(p1), p2(p2), board(new Board()), draw(true) {}

MoveResult Game::playTurn(Player* player, int move){
    cout << player->showName() << " Please Make Your Move\n";
    int row, col;
    cout << "Which Row ?\n";
    cin >> row;

    cout << "Which Column ?\n";
    cin >> col;

    MoveResult didWin = board->makeMove(move, row, col);
    if(didWin == MoveResult::INVALID){
        cout << "INVALID MOVE\n";
        return MoveResult::INVALID;
    }
    if(didWin == MoveResult::WIN){
        cout << "Player " << player->showName() << " Won";
        winner = player;
        draw = false;
        return MoveResult::WIN;
    }
    if(didWin == MoveResult::DRAW){
        cout << "Draw\n";
        return MoveResult::DRAW;
    }
    return MoveResult::VALID;
}

void Game::play(){
    bool turn = 0;
    while(true){
        MoveResult result = playTurn(!turn ? p1 : p2, !turn ? 1 : -1);
        if(result == MoveResult::DRAW || result == MoveResult::WIN) break;
        if(result == MoveResult::VALID)
            turn^=1; 
    }
}