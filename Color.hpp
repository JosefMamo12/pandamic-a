#pragma once

namespace pandemic
{
    enum Color
    {
        Red,
        Yellow,
        Blue,
        Black
    };
    static std::map<std::string, Color> const convert_string_to_Color{{"Red", Color::Red}, {"Yellow", Color::Yellow}, {"Blue", Color::Blue}, {"Black", Color::Black}};
    inline std::ostream &operator<<(std::ostream &out, const Color value)
    {
        static std::map<Color, std::string> strings;
        if (strings.size() == 0)
        {
#define INSERT_ELEMENT(p) strings[p] = #p
            INSERT_ELEMENT(Blue);
            INSERT_ELEMENT(Black);
            INSERT_ELEMENT(Yellow);
            INSERT_ELEMENT(Red);
#undef INSERT_ELEMENT
        }

        return out << strings[value];
    }
}