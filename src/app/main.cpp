#include <iostream>
#include "Board.h"
#include "Player.h"


using namespace std;


int main()
{
     Board board;
     Player player(O);

     while (board.getRound() != 9)
     {
         board.show();
         player.changePlayer();
         board.change(board.getPos(player.getType()), player.getType());
         if (board.checkWin())
         {
             break;
         }
     }
     board.show();
}