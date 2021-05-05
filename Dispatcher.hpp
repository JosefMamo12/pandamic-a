#pragma once
#include <iostream>
#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic
{
    class Dispatcher : public Player
    {

    public:
        using Player::Player;
        string role() { return "Dispatcher"; }
        Player &fly_direct(City c);
    };
}