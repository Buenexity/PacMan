#include "catch.hpp"
#include "../header/object.h"

TEST_CASE("Object class functionality", "[Object]") {

    SECTION("Object initialization") {
        Object obj(10, 20);
        REQUIRE(obj.get_X() == 10);
        REQUIRE(obj.get_Y() == 20);
    }

}

TEST_CASE("Object class Setting and Getting Position Test1", "[Object]") {

    SECTION("Set and get position") {
        Object obj(0, 0);
        obj.setPosition(5, 15);
        REQUIRE(obj.get_X() == 5);
        REQUIRE(obj.get_Y() == 15);
    }

}

TEST_CASE("Object class Setting and Getting Position Test2", "[Object]") {

    SECTION("Set and get position") {
        Object obj(0, 0);
        obj.setPosition(-10, 30);
        REQUIRE(obj.get_X() == -10);
        REQUIRE(obj.get_Y() == 30);
    }

}