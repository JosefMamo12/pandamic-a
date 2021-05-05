#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include "Virologist.hpp"

using namespace std;

namespace pandemic
{
    Player &Virologist::treat(City c)
    {
        if (this->player_deck.find(c) != this->player_deck.end())
        {
            if (pandemic::Board::get_disease_map().at(c) > 0)
            {
                if (pandemic::Board::get_isCured().at(pandemic::Board::get_cityColor().at(c)))
                {
                    pandemic::Board::get_disease_map().at(c) = 0;
                }
                else
                {
                    pandemic::Board::get_disease_map().at(c)--;
                }
            }
            else
            {
                throw invalid_argument(NO_DISEASE_LEVEL);
            }
        }
        else
        {
            throw invalid_argument(NOT_EXISITNG_CARD);
        }
        return *this;
    }
}