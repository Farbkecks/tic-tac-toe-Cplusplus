#pragma once

#include <iostream>
#include <string>
using namespace std;

class Board
{
private:
    string board[9];
    int längeBoard = 9;
    int round = 0;

public:
    Board();
    void show();
    void change(int pos, string symbol);
    bool checkWin();
    int getRound();
};
