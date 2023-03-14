#include <iostream>
#include "Board.h"
#include "Player.h"
#include "MinMax.h"


using namespace std;


int main()
{
    Board board;
    board.setPos(0,O);
    board.setPos(1,X);
    board.setPos(6,O);
    board.setPos(3,X);
    board.show();
    board = MinMax::minmax(board, true, 1);
    board.show();


    return 0;
    Player player(O);
    while (board.getRound() != 9)
    {
        board.show();
        player.changePlayer();
        board.setPos(board.getUserInput(player.getType()), player.getType());
        if (board.checkWin() != EMPTY)
        {
            break;
        }
    }
    board.show();
}