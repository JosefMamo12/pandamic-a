#pragma once
#include <iostream>
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <string>
#include <set>

using namespace std;


namespace pandemic
{
    class Board
    {
        static map<City, int> _disease_level;
        static map<City, Color> _cityColor;
        static map<City, set<City>> _connections;
        static map<City, bool> _research_station;
        static map<Color, bool> _isCured;

    public:
        static void read_units(ifstream &);
        Board();
        static void show();
        static bool is_clean();
        int &operator[](City city);
        static map<City, int> &get_disease_map()
        {
            return _disease_level;
        }
        static map<City, Color> &get_cityColor()
        {
            return _cityColor;
        }
        static map<City, set<City>> &get_connections()
        {
            return _connections;
        }
        static map<City, bool> &get_research_station()
        {
            return _research_station;
        }
        static map<Color, bool> &get_isCured()
        {
            return _isCured;
        }
        static void remove_cures();
        friend ostream &operator<<(ostream &os, const Board &a);
    };
}