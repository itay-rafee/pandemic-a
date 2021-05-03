
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;

#include "doctest.h"
#include <vector>
#include <iostream>
#include <set>
#include <stdexcept>
using namespace std;


set<City> cities{
    Algiers,
    Atlanta,
    Baghdad,
    Bangkok,
    Beijing,
    Bogota,
    BuenosAires,
    Cairo,
    Chennai,
    Chicago,
    Delhi,
    Essen,
    HoChiMinhCity,
    HongKong,
    Istanbul,
    Jakarta,
    Johannesburg,
    Karachi,
    KePasio,
    Khartoum,
    Kinshasa,
    Kolkata,
    Lagos,
    Lima,
    London,
    LosAngeles,
    Madrid,
    Manila,
    MexicoCity,
    Miami,
    Milan,
    Montreal,
    Moscow,
    Mumbai,
    NewYork,
    Osaka,
    Paris,
    Riyadh,
    SanFrancisco,
    Santiago,
    SaoPaulo,
    Seoul,
    Shanghai,
    StPetersburg,
    Sydney,
    Taipei,
    Tehran,
    Tokyo,
    Washington
    };

TEST_CASE("Operators")
{
    Board board;
    board[City::Kinshasa] = 3;      // put 3 yellow disease cubes in Kinshasa.
    board[City::Kinshasa] = 2;      // change number of disease cubes in Kinshasa to 2.
    board[City::MexicoCity] = 3;    // put 3 yellow disease cubes in MexicoCity
    board[City::HoChiMinhCity] = 1; // put 1 red disease cube in HoChiMinhCity
    board[City::Chicago] = 1;       // put 1 blue disease cube in Chicago
    
	OperationsExpert player {board, City::Kolkata}; 
    
    for (auto city:cities)
    {
        player.take_card(city);
        player.fly_direct(city);
        switch (city)
        {
        case City::Kinshasa:
            player.treat(city);
            CHECK(board[City::Kinshasa] == 1);
            break;

        case City::MexicoCity:
            player.treat(city);
            CHECK(board[City::MexicoCity] == 2);
            break;

        case City::HoChiMinhCity:
            player.treat(city);
            CHECK(board[City::HoChiMinhCity] == 0);
            break;

        case City::Chicago:
            player.treat(city);
            CHECK(board[City::Chicago] == 0);
            break;

        
        default:
            CHECK_THROWS(player.treat(city));
            break;
        }        
    }
}