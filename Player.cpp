#include <iostream>
#include "Board.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include "City.hpp"

namespace pandemic
{
    void Player::erase5Cards(Color c)
    {
        uint counter = 0;
        for (auto it = this->player_deck.begin(); it != this->player_deck.end() && counter < GOT5CARDS;)
        {
            if (pandemic::Board::get_cityColor().at(*it) == c)
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

    bool Player::isExist5Cards(set<City> &deck, Color c)
    {
        if (deck.size() < GOT5CARDS)
        {
            return false;
        }
        uint counter = 0;
        for (const auto &i : deck)
        {
            if (pandemic::Board::get_cityColor().at(i) == c)
            {
                counter++;
            }
        }
        return counter >= GOT5CARDS;
    }
    Player &Player::take_card(City city)
    {
        if (this->player_deck.find(city) == this->player_deck.end())
        {
            this->player_deck.insert(city);
        }
        return *this;
    }

    Player &Player::drive(City dest_city)
    {
        if (pandemic::Board::get_connections().at(this->currentCity).count(dest_city) != 0)
        {
            this->currentCity = dest_city;
            return *this;
        }
        throw invalid_argument(NO_DIRECT_WAY);
    }
    Player &Player::build()
    {
        if (this->player_deck.find(this->currentCity) != this->player_deck.end() &&
            !(pandemic::Board::get_research_station().at(this->currentCity)))
        {
            this->player_deck.erase(this->currentCity);
            pandemic::Board::get_research_station().at(this->currentCity) = true;
        }
        else
        {
            throw invalid_argument(NOT_EXISITNG_CARD);
        }
        return *this;
    }
    Player &Player::discover_cure(Color c)
    {
        if (!(pandemic::Board::get_isCured().at(c)))
        {
            if (pandemic::Board::get_research_station().at(this->currentCity))
            {
                if (isExist5Cards(this->player_deck, c))
                {
                    erase5Cards(c);
                    pandemic::Board::get_isCured().at(c) = true;
                }
                else
                {
                    throw invalid_argument("For this player there is no 5 cards of the same color");
                }
            }
            else
            {
                throw invalid_argument(NO_RESEARCH_CITY);
            }
        }
        return *this;
    }
    Player &Player::treat(City city)
    {
        if (this->currentCity == city)
        {
            if (pandemic::Board::get_disease_map().at(city) > 0)
            {
                if (pandemic::Board::get_isCured().at(pandemic::Board::get_cityColor().at(this->currentCity)))
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
            throw invalid_argument(NOT_IN_CITY_MESSAGE);
        }
        return *this;
    }
    Player &Player::fly_shuttle(City city)
    {
        if ((pandemic::Board::get_research_station().at(city)) && pandemic::Board::get_research_station().at(currentCity))
        {
            this->currentCity = city;
            return *this;
        }
        throw invalid_argument(NO_RESEARCH_CITY);
    }
    Player &Player::fly_charter(City city)
    {
        if (this->player_deck.find(currentCity) != this->player_deck.end())
        {
            this->player_deck.erase(currentCity);
            this->currentCity = city;
            return *this;
        }
        throw invalid_argument(NOT_EXISITNG_CARD);
    }
    Player &Player::fly_direct(City city)
    {
        if (this->player_deck.find(city) != this->player_deck.end())
        {
            this->player_deck.erase(city);
            this->currentCity = city;
            return *this;
        }
        throw invalid_argument(NOT_EXISITNG_CARD);
    }
}