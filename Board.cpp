#include "Board.h"
#include "colormod.h"
Color::Modifier red(Color::FG_RED);
Color::Modifier blue(Color::FG_BLUE);
Color::Modifier def(Color::FG_DEFAULT);

Board::Board()
{
    for (int i = 0; i < längeBoard; i++)
    {
        board[i] = to_string(i + 1);
    }
}

int Board::getRound()
{
    return this->round;
}

void Board::show()
{
    for (int i = 0; i < längeBoard; i += 3)
    {
        for (int y = 0; y < 3; y++)
        {
            string output = board[i + y];
            if (output == "X")
                cout << red;
            if (output == "O")
                cout << blue;
            cout << output;
            cout << def;
            if (y != 2)
            {
                cout << "|";
            }
        }
        cout << endl
             << "-----" << endl;
    }
}

void Board::change(int pos, string symbol)
{
    if (board[pos] != "X" && board[pos] != "O")
    {
        board[pos] = symbol;
    }
    round++;
}

bool Board::checkWin()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[0 + i] == board[3 + i] && board[3 + i] == board[6 + i])
        {
            return true;
        }
    }

    for (int i = 0; i < 9; i += 3)
    {
        if (board[0 + i] == board[1 + i] && board[1 + i] == board[2 + i])
        {
            return true;
        }
    }
    if (board[0] == board[4] && board[4] == board[8])
    {
        return true;
    }
    if (board[2] == board[4] && board[4] == board[6])
    {
        return true;
    }
    return false;
}