#include <iostream>
#include "Board.h"

namespace threeInARow
{
    void Board::createBoard()
    {
        gameBoard.resize(3);

        //Init empty board
        for(int i{0}; i < 3; ++i)
        {
            gameBoard[i].resize(3 ,' ');
        }

    }

    void Board::printBoard()
    {

        //Top
        for(int i{0}; i < 3+4; ++i)
        {
            std::cout << "_";
        }
        std::cout << std::endl;

        //Body
        for(int i{0}; i < 3; ++i)
        {
            std::cout << "|";
            for(int j{0}; j < 3; ++j)
            {
                std::cout << gameBoard[i][j] << "|";
            }
            std::cout << std::endl;
        }

        //Bottom
        for(int i{0}; i < 3+4; ++i)
        {
            std::cout << "-";
        }
        std::cout << std::endl;
        
    }

}