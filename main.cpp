#include <iostream>
// #include "Board.h"
#include "Player.h"
using namespace std;

int main()
{
    // Board board;
    // string player = "O";
    // while (board.getRound() != 9)
    // {
    //     board.show();
    //     changePlayer(player);
    //     board.change(getPos(player), player);
    //     if (board.checkWin())
    //     {
    //         break;
    //     }
    // }
    // board.show();

    Player x(O);
    cout << x << endl;
    x.changePlayer();
    cout << x << endl;
}