#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include <iostream>

namespace pandemic {

    class Board {

        // static std::map<City, std::set<City>> connections;
        // std::map<City, int> diseas_cubes;
        // std::set<City> research_stations;
        // std::set<Color> cure_discoverd;
        bool cured[4] = {0};

        public:
            Board() {}

            void remove_cures();
            int& operator[](City c);
            static bool is_clean();
            static bool is_connected(City& c1, City& c2);
            void build_research_station(City c);
            static bool is_research_station(City c);
            void mark_cured(Color c);
            static bool is_cure_discoverd(City c);
            static Color color_of(City c);
            friend std::ostream& operator<<(std::ostream& out, Board& b);
    };



}