#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"

namespace pandemic{

    class Medic: public Player {
        // private:
        // City city;
        // Board board;

        public:
        Medic(Board b, City c):Player(b,c){};
    };
};