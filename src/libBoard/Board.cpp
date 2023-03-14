#include "Board.h"

using namespace std;


Board::Board(int eva) {
    this->evaluation = eva;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < laengeBoard; i++)
    {
        board[i] = EMPTY;
    }
}


int Board::getUserInput(const PlayerType& type)
{
    int pos;
    string input;
    while (true)
    {

        if(type == X) {
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        }else{
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
        }
        cout << type;
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        cout << " ist dran, Welche Position: ";
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

        if(board[pos-1] != EMPTY){
            cout << "Platz schon belegt" << endl;
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
                if(board[i + y] == X) {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
                }else{
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                }
                cout << board[i + y];
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
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

 void Board::setPos(const int& pos, PlayerType symbol)
 {
    if (board[pos] != X && board[pos] != O)
    {
        board[pos] = symbol;
    }
 }

 PlayerType Board::checkWin() const
 {
     for (int i = 0; i < 3; i++)
     {
         if (board[0 + i] == board[3 + i] && board[3 + i] == board[6 + i])
         {
             if(board[0+i] == EMPTY) continue;
             return board[0+i];
         }
     }

     for (int i = 0; i < 9; i += 3)
     {
         if (board[0 + i] == board[1 + i] && board[1 + i] == board[2 + i])
         {
             if(board[0+i] == EMPTY) continue;
             return board[0+i];
         }
     }
     if (board[0] == board[4] && board[4] == board[8])
     {
         if(board[0] != EMPTY) return board[0];
     }
     if (board[2] == board[4] && board[4] == board[6])
     {
         if(board[2] != EMPTY) return board[2];
     }
     return EMPTY;
 }

int Board::getLaengeBoard() const {
    return this->laengeBoard;
}

PlayerType Board::getPos(const int& pos) const {
    return this->board[pos];
}

bool Board::hasEmptyPace() const {
    for(int num : board){
        if(num != EMPTY) return false;
    }
    return true;
}

int Board::getEvaluation() const {
    return this->evaluation;
}

void Board::setEvaluation(const int& eva) {
    this->evaluation = eva;
}

void Board::resetPos(int i) {
    board[i] = EMPTY;
}

