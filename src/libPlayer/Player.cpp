#include "Player.h"
#include <string>

using namespace std;

Player::Player(PlayerType type)
{
    this->PlayerSymbole = type;
}

std::ostream &operator<<(std::ostream &strm, const Player &a)
{
        return strm << a.PlayerSymbole;
}

PlayerType Player::getType() {
    return this->PlayerSymbole;
}



void Player::changePlayer()
{
    if (PlayerSymbole == X)
    {
        PlayerSymbole = O;
    }
    else if (PlayerSymbole == O)
    {
        PlayerSymbole = X;
    }
};