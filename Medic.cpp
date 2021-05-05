#include <iostream>
#include "Medic.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;

namespace pandemic
{
    void Medic::if_cure_cure_it(City c)
    {
        if (!(pandemic::Board::get_isCured().at(pandemic::Board::get_cityColor().at(this->currentCity))))
        {
            return;
        }
        pandemic::Board::get_disease_map().at(this->currentCity) = 0;
    }
    Player &Medic::treat(City city)
    {
        if (this->currentCity == city)
        {
            if (pandemic::Board::get_disease_map().at(city) > 0)
            {
                pandemic::Board::get_disease_map().at(city) = 0;
            }
            else
            {
                throw invalid_argument(NO_DISEASE_LEVEL);
            }
        }
        else
        {
            throw invalid_argument(NOT_IN_CITY_MESSAGE);
        }
        return *this;
    }
    Player &Medic::fly_shuttle(City city)
    {
        if ((pandemic::Board::get_research_station().at(city)) && pandemic::Board::get_research_station().at(currentCity))
        {
            this->currentCity = city;
            if_cure_cure_it(this->currentCity);
            return *this;
        }
        throw invalid_argument(NO_RESEARCH_CITY);
    }
    Player &Medic::drive(City dest_city)
    {
        if (pandemic::Board::get_connections().at(this->currentCity).count(dest_city) != 0)
        {
            this->currentCity = dest_city;
            if_cure_cure_it(this->currentCity);
            return *this;
        }
        throw invalid_argument(NO_DIRECT_WAY);
    }
    Player &Medic::fly_charter(City city)
    {
        if (this->player_deck.find(currentCity) != this->player_deck.end())
        {
            this->player_deck.erase(currentCity);
            this->currentCity = city;
            if_cure_cure_it(this->currentCity);
            return *this;
        }
        throw invalid_argument(NOT_EXISITNG_CARD);
    }
    Player &Medic::fly_direct(City city)
    {
        if (this->player_deck.find(city) != this->player_deck.end())
        {
            this->player_deck.erase(city);
            this->currentCity = city;
            if_cure_cure_it(this->currentCity);
            return *this;
        }
        throw invalid_argument(NOT_EXISITNG_CARD);
    }

}
