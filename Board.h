#pragma once

#ifndef BOARD_H
#define BOARD_H


#include <vector>
#include "Player.h"

namespace threeInARow
{
    int const MAXIMUM_SYMBOLS{3};

    class Board
    {
        public:
            Board(){};
            ~Board(){};

            void createBoard();
            void printBoard();

            bool makeMove(int const& col, int const& row, char const& symbol);
            bool isAllowedMove(int const& col, int const& row) const;
            bool countSymbols(char const& symbol);
            bool makeMove2(int const& removeCol, int const& removeRow, int const& col, int const& row,
                char const& symbol);

            bool isWin();
            bool checkCol();
            bool checkRow();
            bool checkDiag();

        private:
            std::vector<std::vector<char>> gameBoard;
    };
}

#endif