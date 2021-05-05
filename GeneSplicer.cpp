#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include "GeneSplicer.hpp"

using namespace std;

namespace pandemic
{
    void GeneSplicer::erase5Cards()
    {
        uint counter = 0;
        for (auto it = this->player_deck.begin(); it != this->player_deck.end() && counter < GOT5CARDS;)
        {
            it = this->player_deck.erase(it);
            counter++;
            ++it;
        }
    }

    Player &GeneSplicer::discover_cure(Color c)
    {

        if (!(pandemic::Board::get_isCured().at(c)))
        {
            if (this->player_deck.size() > 4)
            {
                if (pandemic::Board:: get_research_station().at(this->currentCity))
                {
                    pandemic::Board:: get_isCured().at(c) = true;
                    erase5Cards();
                }
                else
                {
                    throw invalid_argument(NO_RESEARCH_CITY);
                }
            }
            else
            {
                throw invalid_argument(NOT_ENOUGH_CARDS_MESSAGE);
            }
        }
        return *this;
    }
}