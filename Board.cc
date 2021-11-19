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

    bool Board::isAllowedMove(int const& col, int const& row) const
    {
        if(gameBoard[col][row] == ' ')
        {
            return true;
        }else
        {
            std::cout << "Not allowed move." << std::endl;
            return false;
        }
    }

    bool Board::countSymbols(char const& symbol)
    {
        int cnt{0};
        for(int i{0}; i < 3; ++i)
        {
            for(int j{0}; j < 3; ++j)
            {
                if(gameBoard[i][j] == symbol)
                {
                    cnt++;
                }

            }
        }

        if(cnt == 3)
        {
            return false;
        }else{
            return true;
        }


    }

    bool Board::makeMove2(int const& removeCol, int const& removeRow, int const& col,
        int const& row, char const& symbol)  
    {
        gameBoard[removeCol][removeRow] = ' ';
        Board::makeMove(col, row, symbol);
    }

    bool Board::makeMove(int const& col, int const& row, char const& symbol)
    {
        if(isAllowedMove(col, row))
        {
            gameBoard[col][row] = symbol;
            return true;
        }else
        {
            return false;
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

            if(cnt == 2)
            {
                return true;
            }else
            {
                cnt = 0;
            }
        }

        return false;
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

            if(cnt == 2)
            {
                return true;
            }else
            {
                cnt = 0;
            }
        }

        return false;
        
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
            return true;
            
        }else if(gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0])
        {
            return true;

        }else{
            return false;
        }
        
    }

    bool Board::isWin()
    {
        if(checkCol() == true || checkRow() == true || checkDiag() == true)
        {
            return true;
        }else{
            return false;
        }
    }

}