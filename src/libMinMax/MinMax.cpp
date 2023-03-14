#include "MinMax.h"
#include <limits>

namespace {
    bool weniger(int x, int y){
        return x < y;
    }

    bool greater(int x, int y){
        return x > y;
    }
}


Board MinMax::minmax(const Board& board, bool turn, int depth, bool start) {
    Board bestBoard = board;
    bool firstBoard = false;
    int mult = turn ? 1:-1;
    auto funkt = turn ? greater : weniger;
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
            newBoard = MinMax::minmax(newBoard,!turn , depth+1, false);
        }
        if(!firstBoard){
            firstBoard = true;
            bestBoard = newBoard;
            if(!start) bestBoard.resetPos(i);
        }
        if(funkt(newBoard.getEvaluation(), bestBoard.getEvaluation())){
            bestBoard = newBoard;
            if(!start) bestBoard.resetPos(i);
        }
    }
    return bestBoard;
}


