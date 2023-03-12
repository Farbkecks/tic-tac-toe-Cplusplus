#pragma once
#include "Player.h"
#include <iostream>
#include <string>
#include <windows.h>

class Board
{
private:
    PlayerType board[9];
    int laengeBoard = 9;
    int round = 0;
    HANDLE hConsole;

public:
    Board();
    void show();
     void change(int pos, PlayerType symbol);
     bool checkWin();
     int getRound();
     int getPos(PlayerType type);
};
