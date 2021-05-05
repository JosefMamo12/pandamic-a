#pragma once
#include <iostream>
#include <map>
#include <string>

namespace pandemic
{
    enum City
    {
        Algiers,
        Atlanta,
        Baghdad,
        Bangkok,
        Beijing,
        Bogota,
        BuenosAires,
        Cairo,
        Chennai,
        Chicago,
        Delhi,
        Essen,
        HoChiMinhCity,
        HongKong,
        Istanbul,
        Jakarta,
        Johannesburg,
        Karachi,
        Khartoum,
        Kinshasa,
        Kolkata,
        Lagos,
        Lima,
        London,
        LosAngeles,
        Madrid,
        Manila,
        MexicoCity,
        Miami,
        Milan,
        Montreal,
        Moscow,
        Mumbai,
        NewYork,
        Osaka,
        Paris,
        Riyadh,
        SanFrancisco,
        Santiago,
        SaoPaulo,
        Seoul,
        Shanghai,
        StPetersburg,
        Sydney,
        Taipei,
        Tehran,
        Tokyo,
        Washington
    };
    static std::map<std::string, City> const convert_string_to_City = {
        {"Algiers", City::Algiers},
        {"Atlanta", City::Atlanta},
        {"Baghdad", City::Baghdad},
        {"Bangkok", City::Bangkok},
        {"Beijing", City::Beijing},
        {"Bogota", City::Bogota},
        {"BuenosAires", City::BuenosAires},
        {"Cairo", City::Cairo},
        {"Chennai", City::Chennai},
        {"Chicago", City::Chicago},
        {"Delhi", City::Delhi},
        {"Essen", City::Essen},
        {"HoChiMinhCity", City::HoChiMinhCity},
        {"HongKong", City::HongKong},
        {"Istanbul", City::Istanbul},
        {"Jakarta", City::Jakarta},
        {"Johannesburg", City::Johannesburg},
        {"Karachi", City::Karachi},
        {"Khartoum", City::Khartoum},
        {"Kinshasa", City::Kinshasa},
        {"Kolkata", City::Kolkata},
        {"Lagos", City::Lagos},
        {"Lima", City::Lima},
        {"London", City::London},
        {"LosAngeles", City::LosAngeles},
        {"Madrid", City::Madrid},
        {"Manila", City::Manila},
        {"MexicoCity", City::MexicoCity},
        {"Miami", City::Miami},
        {"Milan", City::Milan},
        {"Montreal", City::Montreal},
        {"Moscow", City::Moscow},
        {"Mumbai", City::Mumbai},
        {"NewYork", City::NewYork},
        {"Osaka", City::Osaka},
        {"Paris", City::Paris},
        {"Riyadh", City::Riyadh},
        {"SanFrancisco", City::SanFrancisco},
        {"Santiago", City::Santiago},
        {"SaoPaulo", City::SaoPaulo},
        {"Seoul", City::Seoul},
        {"Shanghai", City::Shanghai},
        {"StPetersburg", City::StPetersburg},
        {"Sydney", City::Sydney},
        {"Taipei", City::Taipei},
        {"Tehran", City::Tehran},
        {"SanFrancisco", City::SanFrancisco},
        {"Santiago", City::Santiago},
        {"SaoPaulo", City::SaoPaulo},
        {"Tokyo", City::Tokyo},
        {"Washington", City::Washington},
        {"StPetersburg", City::StPetersburg},
    };

    inline std::ostream &operator<<(std::ostream &out, const City value)
    {
        static std::map<City, std::string> strings;
        if (strings.size() == 0)
        {
#define INSERT_ELEMENT(p) strings[p] = #p
            INSERT_ELEMENT(Algiers);
            INSERT_ELEMENT(Atlanta);
            INSERT_ELEMENT(Baghdad);
            INSERT_ELEMENT(Bangkok);
            INSERT_ELEMENT(Beijing);
            INSERT_ELEMENT(Bogota);
            INSERT_ELEMENT(BuenosAires);
            INSERT_ELEMENT(Cairo);
            INSERT_ELEMENT(Chennai);
            INSERT_ELEMENT(Chicago);
            INSERT_ELEMENT(Delhi);
            INSERT_ELEMENT(Essen);
            INSERT_ELEMENT(HoChiMinhCity);
            INSERT_ELEMENT(HongKong);
            INSERT_ELEMENT(Istanbul);
            INSERT_ELEMENT(Jakarta);
            INSERT_ELEMENT(Johannesburg);
            INSERT_ELEMENT(Karachi);
            INSERT_ELEMENT(Khartoum);
            INSERT_ELEMENT(Kinshasa);
            INSERT_ELEMENT(Kolkata);
            INSERT_ELEMENT(Lagos);
            INSERT_ELEMENT(Lima);
            INSERT_ELEMENT(London);
            INSERT_ELEMENT(LosAngeles);
            INSERT_ELEMENT(Madrid);
            INSERT_ELEMENT(Manila);
            INSERT_ELEMENT(MexicoCity);
            INSERT_ELEMENT(Miami);
            INSERT_ELEMENT(Milan);
            INSERT_ELEMENT(Montreal);
            INSERT_ELEMENT(Moscow);
            INSERT_ELEMENT(Mumbai);
            INSERT_ELEMENT(NewYork);
            INSERT_ELEMENT(Osaka);
            INSERT_ELEMENT(Paris);
            INSERT_ELEMENT(Riyadh);
            INSERT_ELEMENT(SanFrancisco);
            INSERT_ELEMENT(Santiago);
            INSERT_ELEMENT(SaoPaulo);
            INSERT_ELEMENT(Seoul);
            INSERT_ELEMENT(Shanghai);
            INSERT_ELEMENT(StPetersburg);
            INSERT_ELEMENT(Sydney);
            INSERT_ELEMENT(Taipei);
            INSERT_ELEMENT(Tehran);
            INSERT_ELEMENT(Tokyo);
            INSERT_ELEMENT(Washington);
#undef INSERT_ELEMENT
        }

        return out << strings[value];
    }

}