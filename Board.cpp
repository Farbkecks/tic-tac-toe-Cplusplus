#include "Board.h"

using namespace std;

Board::Board()
{
    for (int i = 0; i < laengeBoard; i++)
    {
        board[i] = EMPTY;
    }
}

 int Board::getRound()
 {
     return this->round;
 }

void Board::show()
{
    int count = 1;
    cout << endl;
    for (int i = 0; i < laengeBoard; i += 3)
    {
        for (int y = 0; y < 3; y++)
        {
            if (board[i + y] != EMPTY)
            {
                cout << board[i + y];
            }
            else
            {
                cout << count;
            }
            count++;

            if (y != 2)
            {
                cout << "|";
            }
        }
        cout << endl
             << "-----" << endl;
    }
}

 void Board::change(int pos, PlayerType symbol)
 {
     if (board[pos] != X && board[pos] != O)
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
             if(board[0+i] == EMPTY) continue;
             return true;
         }
     }

     for (int i = 0; i < 9; i += 3)
     {
         if (board[0 + i] == board[1 + i] && board[1 + i] == board[2 + i])
         {
             if(board[0+i] == EMPTY) continue;
             return true;
         }
     }
     if (board[0] == board[4] && board[4] == board[8])
     {
         if(board[0] != EMPTY) return true;
     }
     if (board[2] == board[4] && board[4] == board[6])
     {
         if(board[2] != EMPTY) return true;
     }
     return false;
 }
