#pragma once
#include <iostream>
#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;
namespace pandemic
{
    class Medic : public Player
    {

    public:
        using Player::Player;
        string role() { return "Medic"; }
        Player &treat(City);
        Player &drive(City);
        Player &fly_shuttle(City);
        Player &fly_direct(City);
        Player &fly_charter(City);
        void if_cure_cure_it(City);
    };
}