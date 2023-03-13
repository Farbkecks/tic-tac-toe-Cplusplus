#include <iostream>
#include "Board.h"
#include "Player.h"
#include "MinMax.h"


using namespace std;


int main()
{
    Board board;
    Player player(X);
    board.setPos(0,O);
    board.setPos(1,O);
    board.setPos(6,O);
    board.setPos(2,X);
    board.setPos(3,X);
    board.setPos(4,X);
    board.show();
    MinMax::minmax(board, player, 1);


    return 0;

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