#include "MinMax.h"

namespace {
    bool weniger(int x, int y){
        return x < y;
    }

    bool mehr(int x, int y){
        return x > y;
    }
}


Board MinMax::minmax(const Board& board, bool turn, int depth) {
    Board bestBoard = board;
    int mult = turn ? 1:-1;
    auto funkt = turn ? mehr : weniger;
    PlayerType type = turn ? X : O;

    for(int i=0; i<board.getLaengeBoard(); i++){
        if(board.getPos(i) != EMPTY){
            continue;
        }
        Board newBoard = board;
        newBoard.setPos(i, type);
        if(newBoard.checkWin() != EMPTY){
            newBoard.setEvaluation(mult * depth);
        }else{
            newBoard = MinMax::minmax(newBoard,!turn , depth+1);
        }
        if(funkt(newBoard.getEvaluation(), bestBoard.getEvaluation())){
            bestBoard = newBoard;
        }
    }
    return bestBoard;
}


