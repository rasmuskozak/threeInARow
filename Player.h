#pragma once

#ifndef PLAYER_H
#define PLAYER_H


#include "Board.h"
#include <string>

namespace threeInARow{

    int const MAXIMUM_SYMBOLS{3};

    class Player
    {
        public:
            void setPlayerNumber(int const& input);
            char getPlayerSymbol() const { return symbol;}

            void setMyTurn(bool const& input);
            bool getMyTurn(){ return myTurn; }

            std::string printName(){ return name;}

        private:
            char symbol;
            int symbolsPlaced{0};
            bool myTurn;
            std::string name;

    };
}

#endif