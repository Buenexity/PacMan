
#include "catch.hpp"

#include "../header/ghost.h"
#include "../header/map.h"

TEST_CASE("Ghost Initialization", "[Ghost]") {
    // Create a Ghost instance for testing
    Ghost ghost(0.0f, 0.0f, 1, false, false, sf::Color::Red, RED_GHOST);

    SECTION("Check initial values") {
        REQUIRE(ghost.getHidingState() == false);
        REQUIRE(ghost.getDeathStatus() == false);
        REQUIRE(ghost.getCurrentDirection() == 1);
        REQUIRE(ghost.getRadius() == Approx(21.0f / 2));
        REQUIRE(ghost.getDoor() == true);
        REQUIRE(ghost.getShape().getPosition().x == Approx(0.0f));
        REQUIRE(ghost.getShape().getPosition().y == Approx(0.0f));
    }

}

TEST_CASE("Ghost Hiding State", "[Ghost]") {
    Ghost ghost(0.0f, 0.0f, 1, false, false, sf::Color::Red, RED_GHOST);

    SECTION("Initial hiding state") {
        REQUIRE(ghost.getHidingState() == false);
    }

    SECTION("Set and get hiding state") {
        ghost.setHidingState(true);
        REQUIRE(ghost.getHidingState() == true);

        ghost.setHidingState(false);
        REQUIRE(ghost.getHidingState() == false);
    }
}

TEST_CASE("Ghost Death Status", "[Ghost]") {
    Ghost ghost(0.0f, 0.0f, 1, false, false, sf::Color::Red, RED_GHOST);

    SECTION("Initial death status") {
        REQUIRE(ghost.getDeathStatus() == false);
    }

    SECTION("Set and get death status") {
        ghost.setDeathStatus(true);
        REQUIRE(ghost.getDeathStatus() == true);

        ghost.setDeathStatus(false);
        REQUIRE(ghost.getDeathStatus() == false);
    }
}

TEST_CASE("Ghost Right Direction", "[Ghost]") {
    Ghost ghost(0.0f, 0.0f, 1, false, false, sf::Color::Red, RED_GHOST);

    SECTION("Initial current direction") {
        REQUIRE(ghost.getCurrentDirection() == 1);
    }

    SECTION("Set and get current direction") {
        ghost.setCurrentDirection(1);
        REQUIRE(ghost.getCurrentDirection() == 1);
    }
}

TEST_CASE("Ghost Left Direction", "[Ghost]") {
    Ghost ghost(0.0f, 0.0f, 1, false, false, sf::Color::Red, RED_GHOST);

    SECTION("Set and get left direction") {
        ghost.setCurrentDirection(4);
        REQUIRE(ghost.getCurrentDirection() == 4);
    }
}

TEST_CASE("Ghost Up Direction", "[Ghost]") {
    Ghost ghost(0.0f, 0.0f, 1, false, false, sf::Color::Red, RED_GHOST);

    SECTION("Set and get up direction") {
        ghost.setCurrentDirection(2);
        REQUIRE(ghost.getCurrentDirection() == 2);
    }
}

TEST_CASE("Ghost Down Direction", "[Ghost]") {
    Ghost ghost(0.0f, 0.0f, 1, false, false, sf::Color::Red, RED_GHOST);

    SECTION("Set and get down direction") {
        ghost.setCurrentDirection(3);
        REQUIRE(ghost.getCurrentDirection() == 3);
    }
}

TEST_CASE("Ghost Radius", "[Ghost]") {
    Ghost ghost(0.0f, 0.0f, 1, false, false, sf::Color::Red, RED_GHOST);

    SECTION("Check initial radius") {
        REQUIRE(ghost.getRadius() == Approx(21.0f / 2));
    }
}

TEST_CASE("Ghost Shape", "[Ghost]") {
    Ghost ghost(0.0f, 0.0f, 1, false, false, sf::Color::Red, RED_GHOST);

    SECTION("Check initial shape") {
        const sf::CircleShape& shape = ghost.getShape();
        REQUIRE(shape.getPosition().x == Approx(0.0f));
        REQUIRE(shape.getPosition().y == Approx(0.0f));
    }
}

TEST_CASE("Ghost Set Door", "[Ghost]") {
    Ghost ghost(0.0f, 0.0f, 1, false, false, sf::Color::Red, RED_GHOST);

    SECTION("Set door to true") {
        ghost.setDoor(true);
        REQUIRE(ghost.getDoor() == true);
    }

    SECTION("Set door to false") {
        ghost.setDoor(false);
        REQUIRE(ghost.getDoor() == false);
    }
}

TEST_CASE("Ghost Get Door", "[Ghost]") {
    Ghost ghost(0.0f, 0.0f, 1, false, false, sf::Color::Red, RED_GHOST);

    SECTION("Initial door state is true") {
        REQUIRE(ghost.getDoor() == true);
    }
}

TEST_CASE("Ghost Teleport", "[Ghost]") {
    Ghost ghost(0.0f, 0.0f, 1, false, false, sf::Color::Red, RED_GHOST);

    SECTION("Teleport when x_coordinate exceeds max_c") {
        // Set x_coordinate to a value greater than max_c
        ghost.setPosition(22.0f * 21.0f, 0.0f);
        
        // Call teleport and check if the position is reset to 0
        REQUIRE(ghost.teleport() == true);
        REQUIRE(ghost.get_X() == Approx(0.0f));
    }

    SECTION("Teleport when x_coordinate is less than 0") {
        // Set x_coordinate to a negative value
        ghost.setPosition(-5.0f, 0.0f);
        
        // Call teleport and check if the position is reset to max_c
        REQUIRE(ghost.teleport() == true);
        REQUIRE(ghost.get_X() == Approx(21.0f * 21.0f));
    }

    SECTION("No teleport when x_coordinate is within bounds") {
        // Set x_coordinate to a valid value
        ghost.setPosition(10.0, 10.0);
        
        // Call teleport and check if the position remains unchanged
        REQUIRE(ghost.teleport() == false);
        REQUIRE(ghost.get_X() == Approx(10.0f));
    }
}

// TEST_CASE("Ghost Target Coordinates", "[Ghost]") {
//     Ghost ghost(0.0f, 0.0f, 1, false, false, sf::Color::Red, RED_GHOST);

//     // Mocking the Map class 
//     class MockMap : public Map {
//     public:
//         MockMap() : Map() {}
//         std::vector<std::vector<std::string>> GetMap() const  {
//             // Mocked map for testing
//             return {
//                 {" ", " ", " ", " ", " "},
//                 {" ", " ", " ", " ", " "},
//                 {" ", " ", " ", " ", " "},
//                 {" ", " ", " ", " ", " "},
//                 {" ", " ", " ", " ", " "}
//             };
//         }
//     };

//     MockMap mockMap;
//     ghost.target_coords(3.0f * 21.0f, 2.0f * 21.0f, mockMap);

//     SECTION("Check if ghost moves towards target coordinates") {
//         REQUIRE(ghost.getCurrentDirection() == 2); // Ghost should move up towards target
//         REQUIRE(ghost.get_X() == Approx(0.0f)); // Ghost should be at x-coordinate 0
//         REQUIRE(ghost.get_Y() == Approx(0.0f)); // Ghost should be at y-coordinate 0
//     }

 
// }

// TEST_CASE("Ghost Targeting", "[Ghost]") {
//     Ghost ghost(0.0f, 0.0f, 1, false, false, sf::Color::Red, RED_GHOST);

//     // Mocking the Map class 
//     class MockMap : public Map {
//     public:
//         MockMap() : Map() {}
//         std::vector<std::vector<std::string>> GetMap() const {
//             // Mocked map for testing
//             return {
//                 {" ", " ", " ", " ", " "},
//                 {" ", " ", " ", " ", " "},
//                 {" ", " ", " ", " ", " "},
//                 {" ", " ", " ", " ", " "},
//                 {" ", " ", " ", " ", " "}
//             };
//         }
//     };

//     MockMap mockMap;
//     Pacman pacman(1, false, false, 1.0f, 1.0f);

//     SECTION("Red Ghost - Follows Pacman directly") {
//         ghost.target(3.0f * 21.0f, 2.0f * 21.0f, mockMap, pacman);

//         REQUIRE(ghost.getCurrentDirection() == 2); // Ghost should move up towards Pacman

//     }

// }

TEST_CASE("Ghost getOppositeDirection Function", "[Ghost]") {
    Ghost ghost(0.0f, 0.0f, 1, false, false, sf::Color::Red, RED_GHOST);

    SECTION("Opposite direction for currentDirection = 0 should be 0") {
        ghost.setCurrentDirection(0);
        REQUIRE(ghost.getOppositeDirection() == 0);
    }

    SECTION("Opposite direction for currentDirection = 1 should be 4") {
        ghost.setCurrentDirection(1);
        REQUIRE(ghost.getOppositeDirection() == 4);
    }

    SECTION("Opposite direction for currentDirection = 2 should be 3") {
        ghost.setCurrentDirection(2);
        REQUIRE(ghost.getOppositeDirection() == 3);
    }

    SECTION("Opposite direction for currentDirection = 3 should be 2") {
        ghost.setCurrentDirection(3);
        REQUIRE(ghost.getOppositeDirection() == 2);
    }

    SECTION("Opposite direction for currentDirection = 4 should be 1") {
        ghost.setCurrentDirection(4);
        REQUIRE(ghost.getOppositeDirection() == 1);
    }

    SECTION("Opposite direction for an unknown currentDirection should be 0") {
        ghost.setCurrentDirection(42); // Random unknown direction
        REQUIRE(ghost.getOppositeDirection() == 0);
    }
}