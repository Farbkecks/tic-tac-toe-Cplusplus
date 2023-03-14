#include <iostream>
#include "Board.h"
#include "Player.h"
#include "MinMax.h"


using namespace std;


int main()
{
    Board board;
//    board.setPos(0,O);
//    board.setPos(1,X);
//    board.setPos(6,O);
//    board.setPos(3,X);
//    board.show();
//    board = MinMax::minmax(board, true, 1, true);
//    board.show();
//    return 0;
    Player player(O);
    int round = 0;
    while (round != 9)
    {
        round++;
        board.show();
        player.changePlayer();
        int pos;
        if(player.getType() == X){
            board.setPos(board.getUserInput(player.getType()), player.getType());
        }else{
            board = MinMax::minmax(board, false, 1, true);
        }
        if (board.checkWin() != EMPTY)
        {
            break;
        }
    }
    board.show();
}