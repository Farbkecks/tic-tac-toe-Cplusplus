#include <iostream>
#include "PlayerType.h"

using namespace std;

std::ostream &operator<<(std::ostream &strm, const PlayerType &a)
{
    switch (a)
    {
    case X:
        return strm << "X";
    case O:
        return strm << "O";
    default:
            return strm << "EMPTY";
    }
}