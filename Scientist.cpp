#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include "Scientist.hpp"

using namespace std;

namespace pandemic
{
    void Scientist::eraseNCards()
    {
        uint counter = 0;
        for (auto it = this->player_deck.begin(); it != this->player_deck.end() && counter < this->num;)
        {
            if (pandemic::Board::get_cityColor().at(*it) != 0U)
            {
                it = this->player_deck.erase(it);
                counter++;
            }
            else
            {
                ++it;
            }
        }
    }

    bool Scientist::isExistNCards(set<City> &deck, Color c) const
    {
        if (deck.size() < this->num)
        {
            return false;
        }

        uint counter = 0;
        for (const auto &i : deck)
        {
            if (pandemic::Board::get_cityColor().at(i) == c){
                counter++;
            }
        }
        return counter >= this->num;
    }

    Scientist::Scientist(Board &b, City c, u_int n) : Player(b, c)
    {
        this->num = n;
    }
    Player &Scientist::discover_cure(Color c)
    {
        if (!(pandemic::Board::get_isCured().at(c)))
        {
            if (pandemic::Board::get_research_station().at(this->currentCity))
            {
                if (isExistNCards(this->player_deck, c))
                {
                    eraseNCards();
                    pandemic::Board::get_isCured().at(c) = true;
                }
                else
                {
                    throw invalid_argument("For this player there is no 4 cards of the same color");
                }
            }
            else
            {
                throw invalid_argument(NO_RESEARCH_CITY);
            }
        }
        return *this;
    }
}