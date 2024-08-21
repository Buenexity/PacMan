#include "catch.hpp"
#include "../header/Map.h"
#include "../header/object.h"
#include "../header/pacman.h"

TEST_CASE("Map class Initialization", "[Map]") {
    SECTION("Initialization") {
        Map map;

        REQUIRE(map.getRow() >= 0.0f);
        REQUIRE(map.getCol() >= 0.0f);
        REQUIRE(map.GetMap().empty());
        
    }
}


TEST_CASE("Map class Set Map1", "[Map]") {
    SECTION("Initialization and Set Map1") {
        Map map;

        std::vector<std::vector<std::string>> maptest1 = {
        {" TJJJJJJJJWJJJJJJJJA "},
        {" V........V........V "},
        {" VoER.EJR.M.EJR.ERoV "},
        {" V.................V "},
        {" V.ER.B.EJWJR.B.ER.V "},
        {" V....V...V...V....V "},
        {" LJJA.DJR M EJS.TJJK "},
        {"    V.V   0   V.V    "},
        {"JJJJK.M TR=EA M.LJJJJ"},
        {"     .  V123V  .     "},
        {"JJJJA.B LJJJK B.TJJJJ"},
        {"    V.V       V.V    "},
        {" TJJK.M EJWJR M.LJJA "},
        {" V........V........V "},
        {" V.EA.EJR.M.EJR.TR.V "},
        {" Vo.V.....P.....V.oV "},
        {" DR.M.B.EJWJR.B.M.ES "},
        {" V....V...V...V....V "},
        {" V.EJJQJR.M.EJQJJR.V "},
        {" V.................V "},
        {" LJJJJJJJJJJJJJJJJJK "}
        };

        SECTION("Initial values") {
            REQUIRE(map.getRow() >= 0.0f);
            REQUIRE(map.getCol() >= 0.0f);
            REQUIRE(map.GetMap().empty());
        }

        SECTION("Set Map 1") {
            map.set_Map(1);
            REQUIRE(map.GetMap() == maptest1);
        }

    }

}


TEST_CASE("Map class Set Map2", "[Map]") {
    SECTION("Initialization and Set Map2") {
        Map map;

        std::vector<std::vector<std::string>> maptest2 = {
        {" ################### "},
        {" #........#........# "},
        {" #o##.###.#.###.##o# "},
        {" #.................# "},
        {" #.##.#.     .#.##.# "},
        {" #....#...#...#....# "},
        {" ####.### # ###.#### "},
        {"    #.#   0   #.#    "},
        {"#####.# ##### #.#####"},
        {"     .  #123=  .     "},
        {"#####.# ##### #.#####"},
        {"    #.#       #.#    "},
        {" ####.# ##### #.#### "},
        {" #........#........# "},
        {" #.##.###.#.###.##.# "},
        {" #o.#.....P.....#.o# "},
        {" ##.#.#.#####.#.#.## "},
        {" #....#...#...#....# "},
        {" #.               .# "},
        {" #.................# "},
        {" ################### "}
        };

        SECTION("Initial values") {
            REQUIRE(map.getRow() >= 0.0f);
            REQUIRE(map.getCol() >= 0.0f);
            REQUIRE(map.GetMap().empty());
        }

        SECTION("Set Map 2") {
            map.set_Map(2);
            REQUIRE(map.GetMap() == maptest2);
        }
    }

}


TEST_CASE("Map class Modify Map 1", "[Map]") {
    SECTION("Initialization and Set Map1 to Modify") {
        Map map;

        std::vector<std::vector<std::string>> maptest1 = {
        {" TJJJJJJJJWJJJJJJJJA "},
        {" V........V........V "},
        {" VoER.EJR.M.EJR.ERoV "},
        {" V.................V "},
        {" V.ER.B.EJWJR.B.ER.V "},
        {" V....V...V...V....V "},
        {" LJJA.DJR M EJS.TJJK "},
        {"    V.V   0   V.V    "},
        {"JJJJK.M TR=EA M.LJJJJ"},
        {"     .  V123V  .     "},
        {"JJJJA.B LJJJK B.TJJJJ"},
        {"    V.V       V.V    "},
        {" TJJK.M EJWJR M.LJJA "},
        {" V........V........V "},
        {" V.EA.EJR.M.EJR.TR.V "},
        {" Vo.V.....P.....V.oV "},
        {" DR.M.B.EJWJR.B.M.ES "},
        {" V....V...V...V....V "},
        {" V.EJJQJR.M.EJQJJR.V "},
        {" V.................V "},
        {" LJJJJJJJJJJJJJJJJJK "}
        };

        SECTION("Modify Map") {
            Map map;
            map.set_Map(1);

            SECTION("Modify specific position") {
                map.modifyMap(0, 0, 'X');
                REQUIRE(map.GetMap()[0][0][0] == 'X');
            }
        }
    
    }
}



TEST_CASE("Map class Draw Map 1", "[Map]") {
    SECTION("Initialization and Set Map1") {
        Map map;

        std::vector<std::vector<std::string>> maptest1 = {
        {" TJJJJJJJJWJJJJJJJJA "},
        {" V........V........V "},
        {" VoER.EJR.M.EJR.ERoV "},
        {" V.................V "},
        {" V.ER.B.EJWJR.B.ER.V "},
        {" V....V...V...V....V "},
        {" LJJA.DJR M EJS.TJJK "},
        {"    V.V   0   V.V    "},
        {"JJJJK.M TR=EA M.LJJJJ"},
        {"     .  V123V  .     "},
        {"JJJJA.B LJJJK B.TJJJJ"},
        {"    V.V       V.V    "},
        {" TJJK.M EJWJR M.LJJA "},
        {" V........V........V "},
        {" V.EA.EJR.M.EJR.TR.V "},
        {" Vo.V.....P.....V.oV "},
        {" DR.M.B.EJWJR.B.M.ES "},
        {" V....V...V...V....V "},
        {" V.EJJQJR.M.EJQJJR.V "},
        {" V.................V "},
        {" LJJJJJJJJJJJJJJJJJK "}
        };

        SECTION("Draw Map") {
            Map map;
            sf::RenderWindow window(sf::VideoMode(800, 600), "Test Window");

            SECTION("Draw Map 1") {
                map.set_Map(1);
                map.draw_Map(window);
            }

        }
    }
}


TEST_CASE("Map class Draw Map 2", "[Map]") {
    SECTION("Initialization and Set Map2") {
        Map map;

        std::vector<std::vector<std::string>> maptest2 = {
        {" ################### "},
        {" #........#........# "},
        {" #o##.###.#.###.##o# "},
        {" #.................# "},
        {" #.##.#.     .#.##.# "},
        {" #....#...#...#....# "},
        {" ####.### # ###.#### "},
        {"    #.#   0   #.#    "},
        {"#####.# ##### #.#####"},
        {"     .  #123=  .     "},
        {"#####.# ##### #.#####"},
        {"    #.#       #.#    "},
        {" ####.# ##### #.#### "},
        {" #........#........# "},
        {" #.##.###.#.###.##.# "},
        {" #o.#.....P.....#.o# "},
        {" ##.#.#.#####.#.#.## "},
        {" #....#...#...#....# "},
        {" #.               .# "},
        {" #.................# "},
        {" ################### "}
        };

        SECTION("Draw Map") {
            Map map;
            sf::RenderWindow window(sf::VideoMode(800, 600), "Test Window");

            SECTION("Draw Map 2") {
                map.set_Map(2);
                map.draw_Map(window);
            }
        }
    }
}