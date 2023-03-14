#include "MinMax.h"

namespace {
    bool less(double x, double y){
        return x < y;
    }

    bool greater(double x, double y){
        return x > y;
    }
}


Board MinMax::minmax(const Board& board, bool turn, double depth, bool start) {
    Board bestBoard = board;
    bool firstBoard = true;
    int mult = turn ? 1:-1;
    auto funkt = turn ? greater : less;
    PlayerType type = turn ? X : O;

    for(int i=0; i<Board::getLaengeBoard(); i++){
        if(board.getPos(i) != EMPTY){
            continue;
        }
        Board newBoard = board;
        newBoard.setPos(i, type);
        if(newBoard.checkWin() != EMPTY){
            newBoard.setEvaluation(mult * depth);
        }else{
            newBoard = MinMax::minmax(newBoard,!turn , depth/2, false);
        }
        if(firstBoard){
            firstBoard = false;
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

bool MinMax::canWin(const Board &board, bool turn) {
    if(board.checkWin() != EMPTY) return true;
    PlayerType type = turn ? X : O;
    for(int i=0; i<Board::getLaengeBoard(); i++){
        if(board.getPos(i) != EMPTY){
            continue;
        }
        Board newBoard = board;
        newBoard.setPos(i, type);
        if(newBoard.checkWin() != EMPTY){
            return true;
        }else{
            if(MinMax::canWin(newBoard,!turn)) return true;
        }
    }
    return false;
}




