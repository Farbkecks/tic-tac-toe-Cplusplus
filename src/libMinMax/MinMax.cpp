#include "MinMax.h"


Board MinMax::minmax(const Board& board, Player player, int depth) {
    int mult;
    Board bestBoard;
    int bestEvaluation;
    switch(player.getType()){
        case PlayerType::X: mult = 1; break;
        case PlayerType::O: mult = -1; break;
        default: throw 126;
    }
    for(int i=0; i<board.getLaengeBoard(); i++){
        if(board.getPos(i) == EMPTY){
            Board newBoard = board;
            newBoard.setPos(i, player.getType());
            if(newBoard.checkWin() != EMPTY){
                newBoard.setEvaluation(mult * depth);
            }
            if(newBoard.getEvaluation() > bestEvaluation){
                bestEvaluation = newBoard.getEvaluation();
                bestBoard = newBoard;
            }
        }
    }
}
