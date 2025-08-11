#include "board.h"

Board::Board(){
    board.resize(3, vector<int> (3, 0));
    used = 0;
    diagonal_1 = 0;
    diagonal_2 = 0;
    rowSum.resize(3, 0);
    colSum.resize(3, 0);
}

MoveResult Board::makeMove(int player, int i, int j){
    if (i < 0 || i >= 3 || j < 0 || j >= 3) {
        return MoveResult::INVALID;
    }
    if(board[i][j] == 1 || board[i][j] == -1){
        return MoveResult::INVALID;
    }
    board[i][j] = player;
    used++;
    rowSum[i] += player;
    if(rowSum[i] == 3 || rowSum[i] == -3) return MoveResult::WIN;
    colSum[j] += player;
    if(colSum[j] == 3 || colSum[j] == -3) return MoveResult::WIN;
    if(i == j){
        diagonal_1 += player;
        if(diagonal_1 == 3 || diagonal_1 == -3) return MoveResult::WIN;
    }
    if(i == 2 - j){
        diagonal_2 += player;
        if(diagonal_2 == 3 || diagonal_2 == -3) return MoveResult::WIN;
    }
    if(used == 9) return MoveResult::DRAW;
    return MoveResult::VALID;
}