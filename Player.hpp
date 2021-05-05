#pragma once
#include <iostream>
#include "City.hpp"
#include "Color.hpp"
#include <string>
#include <set>

using namespace std;

const uint GOT5CARDS = 5;
const string NO_DIRECT_WAY = "There is no direct way between this two cities";
const string NOT_EXISITNG_CARD = "This player dont have this specified card";
const string NO_DISEASE_LEVEL = "This city has no disease cubes";
const string NO_RESEARCH_CITY = "There is research station at the current city";
const string NOT_IN_CITY_MESSAGE = "You are not in this city";
const string NOT_ENOUGH_CARDS_MESSAGE ="You dont have enoguh cards to do that task";

namespace pandemic
{
    class Player
    {
    protected:
        City currentCity;
        Board board;
        set<City> player_deck;

    public:
        static bool isExist5Cards(set<City> &deck, Color c);
        virtual void erase5Cards(Color c);
        Player(Board &b, City c) : board(b), currentCity(c){};
        virtual Player &drive(City city);
        virtual Player &fly_direct(City city);
        virtual Player &fly_charter(City city);
        virtual Player &fly_shuttle(City city);
        virtual Player &build();
        virtual Player &discover_cure(Color color);
        virtual Player &treat(City city);
        virtual Player &take_card(City city);
        virtual string role() = 0;
    };
}