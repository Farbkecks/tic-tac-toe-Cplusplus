#pragma once
#include <iostream>
#include "PlayerType.h"

class Player
{
private:
    PlayerType PlayerSymbole;
    friend std::ostream &operator<<(std::ostream &strm, const Player &a);

public:
    // int getUserInput();
    Player(PlayerType type);
    void changePlayer();
    PlayerType getType();
};

std::ostream &operator<<(std::ostream &strm, const Player &a);