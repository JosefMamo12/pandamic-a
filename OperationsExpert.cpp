#include <iostream>
#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "OperationsExpert.hpp"

using namespace std;
namespace pandemic
{
    Player &OperationsExpert::build()
    {
        if (!(pandemic::Board::get_research_station().at(this->currentCity)))
        {
            pandemic::Board::get_research_station().at(this->currentCity) = true;
        }
        return *this;
    }

}