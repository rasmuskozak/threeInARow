#include "Player.h"

namespace threeInARow
{
    
oid Player::setPlayerNumber(int const& player)
    {
        if(player%2 == 0)
        {
            symbol = 'O';
            myTurn = false;
            name = "Player 2";
        }else{
            symbol = 'X';
            myTurn = true;
            name = "Player 1";
        }
    }

    void Player::setMyTurn(bool const& input)
    {
        myTurn = input;
    }

}