#include "catch.hpp"
#include "../header/collisions.h"
#include "../header/map.h"
#include "../header/pacman.h"

TEST_CASE("Map Collision Detection", "[collisions]") {
    collisions collisionDetector;
    Map map; 

    SECTION("Collision with Wall") {
        std::vector<std::vector<std::string>> i_map = {
            {"#####"},
            {"#...#"},
            {"#####"}
        };

        bool collision = collisionDetector.map_collision(false, false, 30, 30, i_map, map);

        CHECK(collision == true);
    }

}