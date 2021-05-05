#include <iostream>
#include "Researcher.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"

using namespace std;

namespace pandemic
{
    Player &Researcher::discover_cure(Color c)
    {
        if (!(pandemic::Board::get_isCured().at(c)))
        {
            if (pandemic::Player::isExist5Cards(this->player_deck, c))
            {
                pandemic::Player::erase5Cards(c);
                pandemic::Board::get_isCured().at(c) = true;
            }
            else
            {
                throw invalid_argument("For this player there is no 5 cards of the same color");
            }
        }
        return *this;
    }

}
