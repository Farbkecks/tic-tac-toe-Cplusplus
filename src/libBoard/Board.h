#pragma once
#include "PlayerType.h"
#include <iostream>
#include <string>

class Board
{
private:
    PlayerType board[9];
    int laengeBoard = 9;
    int round = 0;

public:
    Board();
    void show();
     void change(int pos, PlayerType symbol);
     bool checkWin();
     int getRound();
};
