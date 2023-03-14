#include "Board.h"

class MinMax {
public:
    static Board minmax(const Board& board, bool turn, double depth, bool start);
};