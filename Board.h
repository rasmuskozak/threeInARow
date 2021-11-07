#pragma once

#ifndef BOARD_H
#define BOARD_H


#include <vector>
#include "Player.h"

namespace threeInARow
{
    class Board
    {
        public:
            Board(){};
            ~Board(){};

            void createBoard();
            void printBoard();
            void makeMove(int col, int row, char symbol);

            bool isWin();
            bool checkCol();
            bool checkRow();
            bool checkDiag();

        private:
            std::vector<std::vector<char>> gameBoard;
    };
}

#endif