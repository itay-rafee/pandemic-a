#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include "Player.hpp"

using namespace pandemic;
using namespace std;
set<City> cards;

Player &Player::take_card(City c)
{
        cards.insert(c);
        return *this;
}
Player &Player::drive(City c)
{
        if (board.is_connected(city, c))
        {
                city = c;
        }
        else
        {
                throw invalid_argument("Not Neighbor City");
        }
        return *this;
}
Player &Player::fly_direct(City c)
{
        if (cards.count(c) != 0)
        {
                city = c;
                cards.erase(c);
        }
        else
        {
                throw invalid_argument("Not in the cards!");
        }
        return *this;
}
Player &Player::fly_charter(City c)
{
        if (cards.count(city) != 0)
        {
                cards.erase(city);
                city = c;
        }
        else
        {
                throw invalid_argument("Not in the cards!");
        }
        return *this;
}
Player &Player::fly_shuttle(City c)
{
        if (board.is_research_station(city) && board.is_research_station(c))
        {
                city = c;
        }
        else
        {
                throw invalid_argument("there is not research station");
        }
        return *this;
}
Player &Player::build()
{
        if (board.is_research_station(city))
        {
                return *this;
        }

        if (cards.count(city) != 0)
        {
                board.build_research_station(city);
                cards.erase(city);
        }

        return *this;
}
Player &Player::discover_cure(Color c)
{
        return *this;
}
Player &Player::treat(City c)
{
        if (c == city && board[c] > 0)
        {
                if (board.is_cure_discoverd(c))
                {
                        board[c] = 0;
                }
                else
                {
                        board[c]--;
                }
        }
        return *this;

        // throw invalid_argument("illigel treat");
}
string Player::role() { return type; }
