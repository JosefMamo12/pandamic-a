#include <iostream>
#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Dispatcher.hpp"

using namespace std;

namespace pandemic
{
    Player &Dispatcher::fly_direct(City c)
    {
        if (pandemic::Board::get_research_station().at(this->currentCity))
        {
            this->currentCity = c;
            return *this;
        }
        throw invalid_argument(NO_RESEARCH_CITY);
    }
}