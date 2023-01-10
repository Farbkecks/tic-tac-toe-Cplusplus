#include <iostream>
#include "Board.h"
using namespace std;

int getPos(string player)
{
    int pos;
    string input;
    while (true)
    {
        cout << player << " ist dran, Welche Position: ";
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

string changePlayer(string player)
{
    if (player == "X")
    {
        return "O";
    }
    else
    {
        return "X";
    }
}

int main()
{
    Board board;
    string player = "O";
    while (board.getRound() != 9)
    {
        board.show();
        player = changePlayer(player);
        board.change(getPos(player), player);
        if (board.checkWin())
        {
            break;
        }
    }
    board.show();
}