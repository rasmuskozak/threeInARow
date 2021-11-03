#include "Board.h"
#include "Player.h"
#include "ASCIIPrinter.h"

#include <iostream>
#include <string>

int main()
{
    bool playGame{true};
    int col, row;
    std::string playerTurn;

    threeInARow::Board board;
    threeInARow::Player p1;
    threeInARow::Player p2;
    p1.setPlayerNumber(1);
    p2.setPlayerNumber(2);
    board.createBoard();
  

    std::cout << "\nWelcome to threeInARow!\nType 'q' to quit.\n" << std::endl;
    board.printBoard();

    while(playGame)
    {
        if(p1.getMyTurn() == true)
        {
            playerTurn = "Player 1";
        }else{
            playerTurn = "Player 2";
        }
        std::cout << playerTurn << "'s turn. Please make a move (col,row): ";
        std::cin >> col >> row;

        threeInARow::ASCIIPrinter::makeMove(board, col, row);
        board.printBoard();

        //Switch player
        if(p1.getMyTurn() == true)
        {
            p1.setMyTurn(false);
            p2.setMyTurn(true);
        }else{
            p1.setMyTurn(true);
            p2.setMyTurn(false);
        }
    }
}