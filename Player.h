#pragma once
#include <iostream>
#include "PlayerType.h"

class Player
{
private:
    PlayerType PlayerSymbole;
    friend std::ostream &operator<<(std::ostream &strm, const Player &a);

public:
    // int getPos();
    Player(PlayerType type);
    int getPos();
    void changePlayer();
};

std::ostream &operator<<(std::ostream &strm, const Player &a);