#pragma once
#include "Player.h"
#include <iostream>
#include <string>
#include <windows.h>

class Board
{
private:
    int laengeBoard = 9;
    PlayerType board[9];
    int round = 0;
    int evaluation;
    HANDLE hConsole;

public:
    Board(int eva=0);
    void show();
    void setPos(const int& pos, PlayerType symbol);
    PlayerType checkWin() const;
    int getRound() const;
    int getUserInput(const PlayerType& type);
    int getLaengeBoard() const;
    PlayerType getPos(const int& pos) const;
    bool hasEmptyPace() const;
    int getEvaluation() const;
    void setEvaluation(const int& eva);
};
