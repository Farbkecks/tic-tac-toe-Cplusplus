#pragma once
#include "PlayerType.h"
#include <iostream>
#include <string>

// class Board
// {
// private:
//     string board[9];
//     int längeBoard = 9;
//     int round = 0;

// public:
//     Board();
//     void show();
//     void change(int pos, string symbol);
//     bool checkWin();
//     int getRound();
// };

class Cell
{
private:
    string zahl;
    PlayerType player;

public:
    Cell(string zahl);
    Cell(PlayerType player);
    string getValue();
};
