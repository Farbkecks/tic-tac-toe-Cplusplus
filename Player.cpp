#include "Player.h"
#include <string>

using namespace std;

Player::Player(PlayerType type)
{
    this->PlayerSymbole = type;
}

std::ostream &operator<<(std::ostream &strm, const Player &a)
{
    if (a.PlayerSymbole == X)
    {
        return strm << "X";
    }
    else
    {
        return strm << "O";
    }
}

int Player::getPos()
{
    int pos;
    string input;
    while (true)
    {
        cout << *this << " ist dran, Welche Position: ";
        cin >> input;
        try
        {
            pos = stoi(input);
        }
        catch (...)
        {
            cout << "nur Zahlen" << endl;
            continue;
        }
        if (pos < 1 || pos > 9)
        {
            cout << "nur Zahlen von 1 bis 9" << endl;
            continue;
        }
        return pos - 1;
    }
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