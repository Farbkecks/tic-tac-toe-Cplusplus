#pragma once

#include <iostream>

enum PlayerType
{
    X,
    O,
    EMPTY
};

std::ostream &operator<<(std::ostream &strm, const PlayerType &a);