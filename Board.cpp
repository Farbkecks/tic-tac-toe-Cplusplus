#include "Board.h"

using namespace std;

// Board::Board()
// {
//     for (int i = 0; i < längeBoard; i++)
//     {
//         board[i] = to_string(i + 1);
//     }
// }

// int Board::getRound()
// {
//     return this->round;
// }

// void Board::show()
// {
//     for (int i = 0; i < längeBoard; i += 3)
//     {
//         for (int y = 0; y < 3; y++)
//         {
//             cout << board[i + y];
//             if (y != 2)
//             {
//                 cout << "|";
//             }
//         }
//         cout << endl
//              << "-----" << endl;
//     }
// }

// void Board::change(int pos, string symbol)
// {
//     if (board[pos] != "X" && board[pos] != "O")
//     {
//         board[pos] = symbol;
//     }
//     round++;
// }

// bool Board::checkWin()
// {
//     for (int i = 0; i < 3; i++)
//     {
//         if (board[0 + i] == board[3 + i] && board[3 + i] == board[6 + i])
//         {
//             return true;
//         }
//     }

//     for (int i = 0; i < 9; i += 3)
//     {
//         if (board[0 + i] == board[1 + i] && board[1 + i] == board[2 + i])
//         {
//             return true;
//         }
//     }
//     if (board[0] == board[4] && board[4] == board[8])
//     {
//         return true;
//     }
//     if (board[2] == board[4] && board[4] == board[6])
//     {
//         return true;
//     }
//     return false;
// }

Cell::Cell(string zahl)
{
    this->zahl = zahl;
    this->player = EMPTY;
}

Cell::Cell(PlayerType type)
{
    this->player = type;
    this->zahl = nullptr;
}

string Cell::getValue()
{
    if (this->zahl != nullptr)
    {
        return this->zahl;
    }
    if (this->player != EMPTY)
    {
        switch (this->player)
        {
        case O:
            return "O";
        case X:
            return "X";
        default:
            throw 123;
        }
    }
}
