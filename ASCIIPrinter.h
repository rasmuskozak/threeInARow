#pragma once

#include "Board.h"
//#include "Player.h"

namespace threeInARow
{
    class ASCIIPrinter
    {
        public:
            ASCIIPrinter(){};
            static void makeMove(Board& board, int const& col, int const& row);

    };
}