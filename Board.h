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

        private:
            std::vector<std::vector<char>> gameBoard;


    };
}

#endif