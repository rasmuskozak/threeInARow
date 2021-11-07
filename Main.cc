#include "Board.h"
#include "Player.h"

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

    while(playGame)
    {
        board.printBoard();

        //Check win
        if(board.isWin())
        {
            std::cout << "You win!" << std::endl;
            playGame = false;
            break;
        }

        //Get input
        if(p1.getMyTurn() == true)
        {
            playerTurn = "Player 1";
        }else{
            playerTurn = "Player 2";
        }
        std::cout << playerTurn << "'s turn. Please make a move (row col): ";
        std::cin >> col >> row;

        std::cout << "Making move " << row <<", "<< col << ": " << std::endl;
        if(p1.getMyTurn() == true)
        {
            board.makeMove(col, row, p1.getPlayerSymbol());
        }else{
            board.makeMove(col, row, p2.getPlayerSymbol());
        }
        
        
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