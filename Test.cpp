#include "doctest.h"
#include "Board.hpp"
#include "Player.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include "OperationsExpert.hpp"
#include "Scientist.hpp"
#include "Researcher.hpp"
#include "Virologist.hpp"
#include "Medic.hpp"
#include "GeneSplicer.hpp"
#include "FieldDoctor.hpp"
#include "Dispatcher.hpp"
#include <string>

using namespace std;
using namespace pandemic;

// Give some four red cards to the given player, to initialize an example.
void take_four_red_cards(Player &player)
{
    player.take_card(City::Sydney)
        .take_card(City::HoChiMinhCity)
        .take_card(City::HongKong)
        .take_card(City::Bangkok);
}
void take_four_yellow_cards(Player &player)
{
    player.take_card(City::Bogota)
        .take_card(City::BuenosAires)
        .take_card(City::Kinshasa)
        .take_card(City::Santiago);
}

TEST_CASE("Role Function & Construtctor")
{
    Board board;

    OperationsExpert builder{board, City::Atlanta};
    CHECK_EQ(builder.role(), "OperationExpert");

    Medic doctor{board, City::Atlanta};
    CHECK_EQ(doctor.role(), "Medic");

    Virologist proffesor{board, City::Atlanta};
    CHECK_EQ(proffesor.role(), "Virologist");

    Scientist dexter{board, City::Atlanta, 3};
    CHECK_EQ(dexter.role(), "Scientist");

    Researcher research{board, City::Atlanta};
    CHECK_EQ(research.role(), "Researcher");

    GeneSplicer gene{board, City::Atlanta};
    CHECK_EQ(gene.role(), "GeneSplicer");

    FieldDoctor doc{board, City::Atlanta};
    CHECK_EQ(doc.role(), "FieldDoctor");

    Dispatcher disp{board, City::Atlanta};
    CHECK_EQ(disp.role(), "Dispatcher");
}

TEST_CASE("Drive ()")
{
    /*
     * Check Some other type of player and diffrent cities
    */

    Board b;
    OperationsExpert builder{b, City::Atlanta};
    CHECK_THROWS(builder.drive(City::Algiers));     /* Algiers is not a neighboor of Atlanta */
    CHECK_NOTHROW(builder.drive(City::Washington)); /* Washington is connected to Atlanta */

    Medic doc{b, City::Beijing};
    CHECK_THROWS(doc.drive(City::Algiers));   /* Algiers is not a neighboor of beijing*/
    CHECK_NOTHROW(doc.drive(City::Shanghai)); /* shangahi is connected to Beijing */

    Scientist sc{b, City::Baghdad};
    CHECK_THROWS(sc.drive(City::Khartoum)); /*Khartoum is not a neighboor of Baghdad*/
    CHECK_NOTHROW(sc.drive(City::Cairo));   /* Cairo is connected to Baghdad */
}
TEST_CASE("build() and Cure()") // Because its the only why we can check if exist research labrotory or not
{
    Board b;
    OperationsExpert builder{b, City::Atlanta};
    take_four_red_cards(builder);                    /*Now builder player has 4 red cards */
    builder.build();                                 /* He build research lab at atlanta without drop any card */
    CHECK_THROWS(builder.discover_cure(Color::Red)); /* builder need 5 red cards */
    builder.take_card(City::Baghdad);                /* Now he has 4 red cards and one black card */
    CHECK_THROWS(builder.discover_cure(Color::Red));
    builder.take_card(City::Taipei);
    CHECK_THROWS(builder.discover_cure(Color::Black)); /*Trying to discover a cure but he no have enough cards */
    CHECK_NOTHROW(builder.discover_cure(Color::Red));  /* Now he has 5 card suppose to discover cure and not throwing any problems */

    GeneSplicer gs{b, City::Shanghai};
    take_four_red_cards(gs);
    gs.take_card(City::Riyadh);
    gs.take_card(City::Tehran);
    gs.take_card(City::Khartoum);
    CHECK_THROWS(gs.build());                     /*sc dosent have ShangaiCard */
    CHECK_NOTHROW(gs.discover_cure(Color::Red));  /*Nothing should happend becasue already the builder discover the cure.*/
    CHECK_THROWS(gs.discover_cure(Color::Black)); /*There is no any labrotory in Shanghai */
    gs.drive(City::HongKong);
    CHECK_NOTHROW(gs.build());
    CHECK_NOTHROW(gs.discover_cure(Color::Black)); /*Should heppend because there is research station and there in cure to the black disease.*/
    CHECK_THROWS(gs.discover_cure(Color::Blue));   /*Should throw because he got only 1 card now */

    Researcher rs{b, City::Shanghai}; /*Researcher power is to cure without any search lab */
    b.remove_cures();                 /* CLEAR ALL DISEASES. */
    take_four_red_cards(rs);
    CHECK_THROWS(rs.discover_cure(Color::Red)); /*He dosent have enough red cards  */
    rs.take_card(City::Shanghai);
    CHECK_THROWS(rs.discover_cure(Color::Black)); /* He have 5 red cards no Black ONES */
    CHECK_NOTHROW(rs.discover_cure(Color::Red));  /* No research lab but still working */

    Scientist sc{b, City::SanFrancisco, 3};
    b.remove_cures();
    take_four_yellow_cards(sc);
    CHECK_THROWS(sc.discover_cure(Color::Yellow)); /* No searching lab */
    CHECK_THROWS(sc.build());
    sc.take_card(City::SanFrancisco);
    CHECK_NOTHROW(sc.build());
    CHECK_NOTHROW(sc.discover_cure(Color::Yellow)); /*should Discover a cure */
}
TEST_CASE("fly_direct()")
{
    Board b;
    Dispatcher dis{b, City::Riyadh};
    CHECK_THROWS(dis.fly_direct(City::SaoPaulo)); /* in this city not existing research lab*/
    dis.take_card(City::Riyadh);
    dis.build();
    CHECK_NOTHROW(dis.fly_direct(City::SaoPaulo)); /* dosent need SaoPaulo card */

    Virologist vir{b, City::Istanbul};
    take_four_red_cards(vir);
    CHECK_THROWS(vir.fly_direct(City::Jakarta)); /*She doesnt have this kind of card */
    CHECK_NOTHROW(vir.fly_direct(City::Sydney));
    CHECK_NOTHROW(vir.fly_direct(City::HoChiMinhCity));
    CHECK_THROWS(vir.fly_direct(City::Sydney)); /*To see if she lost this card earlier. */
}
TEST_CASE("fly_charter()")
{
    Board b;
    GeneSplicer gs{b, City::Atlanta};
    CHECK_THROWS(gs.fly_charter(City::Baghdad));
    gs.take_card(City::Atlanta);
    CHECK_NOTHROW(gs.fly_charter(City::Baghdad));

    FieldDoctor fd{b, City::Santiago};
    CHECK_THROWS(fd.fly_charter(City::Riyadh));
    take_four_yellow_cards(fd);
    CHECK_NOTHROW(fd.fly_charter(City::Bangkok));
}
TEST_CASE("fly_shuttle()")
{
    Board b;
    OperationsExpert builder{b, City::Atlanta};
    builder.build();
    CHECK_THROWS(builder.fly_shuttle(City::Baghdad)); // Only one research lab

    FieldDoctor fd{b, City::Santiago};
    CHECK_THROWS(fd.fly_shuttle(City::Riyadh));
    take_four_yellow_cards(fd);
    fd.build();
    CHECK_NOTHROW(fd.fly_shuttle(City::Atlanta));
}
TEST_CASE("operator [] and treat()")
{
    Board b;
    CHECK_NOTHROW(b[City::Algiers] = 5);
    CHECK_NOTHROW(b[City::Madrid] = 8);
    CHECK_NOTHROW(b[City::Atlanta] = 3);
    CHECK_NOTHROW(b[City::Cairo] = 150);

    FieldDoctor fd{b, City::Algiers};
    CHECK_THROWS(fd.treat(City::MexicoCity)); /*He is not associated to mexico city */

    CHECK_NOTHROW(fd.treat(City::Algiers)); /* Self city now 5 suppose to be 4 */
    CHECK_EQ(b[City::Algiers], 4);

    CHECK_NOTHROW(fd.treat(City::Madrid)); /*Was 8 need to be after this task 7 associated city */
    CHECK_EQ(b[City::Madrid], 7);

    CHECK_NOTHROW(fd.treat(City::Cairo)); /*Was 150 need to be after this task 149 associated city */
    CHECK_EQ(b[City::Cairo], 149);

    Virologist viro{b, City::Bogota};
    b[City::Bogota] = 1;

    CHECK_THROWS(viro.treat(City::Bogota)); /*Dosent have this card */
    take_four_yellow_cards(viro);
    CHECK_NOTHROW(viro.treat(City::Bogota)); /*Took the specify card */
    CHECK_EQ(b[City::Bogota], 0);
    CHECK_THROWS(viro.treat(City::Bogota)); /*After she treat she suppose to drop the bogota card */
    b[City::Riyadh] = 3;

    viro.take_card(City::Riyadh);
    CHECK_NOTHROW(viro.treat(City::Riyadh));
    CHECK_EQ(b[City::Riyadh], 2);

    viro.take_card(City::Atlanta); /* another checking */
    CHECK_NOTHROW(viro.treat(City::Atlanta));
    CHECK_EQ(b[City::Atlanta], 2);

    Medic med{b, City::Atlanta};
    CHECK_NOTHROW(med.treat(City::Atlanta));
    CHECK_EQ(b[City::Atlanta], 0);          /* was 2 now zero */
    CHECK_THROWS(med.treat(City::Atlanta)); /*Suppose to throw because city level is 0 */
    med.take_card(City::Atlanta);

    /*Checked fly direct and drive */
    med.build();
    b[City::HongKong] = 150;
    b[City::Taipei] = 10;
    take_four_red_cards(med);
    med.take_card(Jakarta);
    med.discover_cure(Color::Red); /* Exist Cure for the red disease */
    take_four_red_cards(med);
    med.fly_direct(City::HongKong);
    CHECK_EQ(b[City::HongKong], 0); // because he flied direct to a city with a cure so it suppose to be zero;
    med.take_card(HongKong);
    med.build();
    med.drive(City::Taipei);
    CHECK_EQ(b[City::Taipei], 0); /*Checked drive */
    med.drive(City::HongKong);

    /*Checked fly shuttle */
    b[City::Washington] = 123;
    OperationsExpert builder{b, City::Washington};
    builder.build();
    med.take_card(City::Washington);
    med.take_card(City::Paris);
    med.take_card(City::SanFrancisco);
    med.take_card(City::Madrid);
    med.take_card(City::Montreal);
    med.discover_cure(Color::Blue);
    med.fly_shuttle(City::Washington);
    CHECK_EQ(b[City::Washington], 0);
    CHECK_THROWS(med.treat(City::Washington));

    /* Medic fly charter */
    b[City::Sydney] = 123230210;
    med.take_card(City::Washington);
    med.fly_charter(City::Sydney);
    CHECK_EQ(b[City::Sydney], 0);
    CHECK_THROWS(med.treat(City::Sydney));
}
