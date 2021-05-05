#pragma once
#include <iostream>
#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"

using namespace std;

namespace pandemic
{
    class Researcher : public Player
    {

    public:
        using Player::Player;
        string role() { return "Researcher"; }
        Player &discover_cure(Color c);
    };
}