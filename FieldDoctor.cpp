#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include "FieldDoctor.hpp"

using namespace std;

namespace pandemic
{
    Player &FieldDoctor::treat(City city)
    {
        if (this->currentCity == city || pandemic::Board::get_connections().at(this->currentCity).find(city) != pandemic::Board::get_connections().at(this->currentCity).end())
        {

            if (pandemic::Board::get_disease_map().at(city) > 0)
            {
                if (pandemic::Board::get_isCured().at(pandemic::Board::get_cityColor().at(city)))
                {
                    pandemic::Board::get_disease_map().at(city) = 0;
                }
                else
                {
                    pandemic::Board::get_disease_map().at(city)--;
                }
            }
            else
            {
                throw invalid_argument(NO_DISEASE_LEVEL);
            }
        }
        else
        {
            throw invalid_argument("You are not in this city or this city isn't connected to current city ");
        }
        return *this;
    }
}