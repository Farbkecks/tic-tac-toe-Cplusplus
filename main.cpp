#include <iostream>
#include "Board.h"
#include "PlayerType.h"
#include "Player.h"

using namespace std;

int main()
{

     Board board;
     board.show();

     Player player(O);
     while (board.getRound() != 9)
     {
         board.show();
         player.changePlayer();
         board.change(player.getPos(), player.getPlayer());
         if (board.checkWin())
         {
             break;
         }
     }
     board.show();
}