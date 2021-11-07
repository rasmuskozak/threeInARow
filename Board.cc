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

    void Board::makeMove(int col, int row, char symbol)
    {
        gameBoard[col][row] = symbol;
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

    bool Board::checkRow()
    {
        int cnt{0};
        for(int i{0}; i<3; ++i)
        {
            for(int j{1}; j<3; ++j)
            {
                if(gameBoard[i][j] == gameBoard[i][j-1] && gameBoard[i][j] != ' ')
                {
                    cnt++;
                }
            }

            std::cout << "cnt: " << cnt << std::endl;

            if(cnt == 3)
            {
                return true;
            }else
            {
                cnt = 0;
            }
        }
    }

    bool Board::checkCol()
    {
        int cnt{0};

        for(int i{0}; i<3; ++i)
        {
            for(int j{1}; j<3; ++j)
            {
                if(gameBoard[j][i] == ' ')
                {
                    break;
                }
                
                if(gameBoard[j][i] == gameBoard[j-1][i])
                {
                    cnt++;
                }
            }

            std::cout << "cnt2: " << cnt << std::endl;

            if(cnt == 3)
            {
                return true;
            }else
            {
                cnt = 0;
            }
        }
        
    }

    bool Board::checkDiag()
    {
        int cnt{0};

        if(gameBoard[1][1] == ' ')
        {
            return false;
        }

        if(gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2])
        {
            std::cout << "cnt3a: " << cnt << std::endl;
            return true;
            
        }else if(gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0])
        {
            std::cout << "cnt3b: " << cnt << std::endl;
            return true;

        }else{
            return false;
        }
        
    }

    bool Board::isWin()
    {
        if(checkCol() == true)
        {
            std::cout << " col = true" << std::endl;
        }
        if(checkRow() == true)
        {
            std::cout << " row = true" << std::endl;
        }
        if(checkDiag() == true)
        {
            std::cout << " diag = true" << std::endl;
        }
        if(checkCol() == true || checkRow() == true || checkDiag() == true)
        {
            return true;
        }else{
            return false;
        }

        
    }

}