#include "Board.h"
#include "Player.h"
#include "MinMax.h"


using namespace std;


int main()
{
    Board board;
    Player player(O);
    board.show();
    while (true)
    {
        player.changePlayer();
        if(player.getType() == X){
            board.setPos(board.getUserInput(player.getType()), player.getType());
            if(!MinMax::canWin(board, false)) break;
        }else{
            board = MinMax::minmax(board, false, 1, true);
            if(!MinMax::canWin(board, true)) break;
            board.show();
        }
        if (board.checkWin() != EMPTY)
        {
            break;
        }
    }
    board.show();
}