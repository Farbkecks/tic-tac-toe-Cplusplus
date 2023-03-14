#pragma once
#include "Player.h"
#include <iostream>
#include <string>
#include <windows.h>

class Board
{
private:
    static const int laengeBoard = 9;
    PlayerType board[9];
    double evaluation;
    HANDLE hConsole;

public:
    Board(int eva=0);
    void show();
    void setPos(const int& pos, PlayerType symbol);
    PlayerType checkWin() const;
    int getUserInput(const PlayerType& type);
    static int getLaengeBoard() ;
    PlayerType getPos(const int& pos) const;
    double getEvaluation() const;
    void setEvaluation(const double & eva);
    void resetPos(int i);
};
