#pragma once
#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <iostream>

using namespace std;

namespace pandemic
{
    class Virologist : public Player
    {
    public:
        using Player::Player;
        string role() { return "Virologist"; }
        Player &treat(City);
    };
}