#pragma once
#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <iostream>

using namespace std;

namespace pandemic
{
    class GeneSplicer : public Player
    {
    public:
        using Player::Player;
        string role() { return "GeneSplicer"; }
        Player &discover_cure(Color);
        void erase5Cards();
    };
}