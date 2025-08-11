#ifndef BOARD_H
#define BOARD_H

#include <bits/stdc++.h>
using namespace std;

enum class MoveResult {
    INVALID,
    VALID,
    WIN,
    DRAW
};


class Board{
    private:
        vector<vector<int>> board;
        int used;
        int diagonal_1;
        int diagonal_2;
        vector<int> rowSum;
        vector<int> colSum;
    public:
        Board();
        MoveResult makeMove(int player, int i, int j);
};

#endif