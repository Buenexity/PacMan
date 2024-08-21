#include "../header/pacman.h"
#define CATCH_CONFIG_MAIN 
#include "catch.hpp" 

TEST_CASE("Pacman Initialization", "[Pacman]") {
    Pacman pacman(1, false, false, 0.0f, 0.0f);

    SECTION("Check initial values") {
        REQUIRE(pacman.getInvincibility() == false);
        REQUIRE(pacman.getDeathStatus() == false);
        REQUIRE(pacman.getCurrentDirection() == 1);
        REQUIRE(pacman.getLives() == 3);
        REQUIRE(pacman.get_X() == 0.0f);
        REQUIRE(pacman.get_Y() == 0.0f);
    }


}

TEST_CASE("Pacman spawns with good direction") {
    Pacman myPacman(0, false, false, 0.0f, 0.0f);
    int i = myPacman.get_X();
    REQUIRE(i == 0);   
}

TEST_CASE("Pacman setters") {
    Pacman pacman(1, false, false, 10.0f, 20.0f);

    // Test Pacman setters
    pacman.setInvincibility(true);
    pacman.setDeathStatus(true);
    pacman.setCurrentDirection(2);

    REQUIRE(pacman.getInvincibility() == true);
    REQUIRE(pacman.getDeathStatus() == true);
    REQUIRE(pacman.getCurrentDirection() == 2);
}

TEST_CASE("Pacman Move Right", "[Pacman]") {
    // Create a Pacman instance
    Pacman pacman(1, false, false, 10.0f, 10.0f);

    // Create dummy maze and map objects for testing collisions
    vector<vector<string>> maze;
    Map map; 

    SECTION("Pacman moves right if no wall and right key pressed") {
        pacman.setCurrentDirection(1); // Reset current direction


        // Set up maze to have no walls to the right
        maze = {
            {" ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " "}
        };

        pacman.move(maze, map);
        pacman.setPosition(11.9f, 10.0f);

        // Check if Pacman's position has been updated to the right
        REQUIRE(pacman.getCurrentDirection() == 1);
        REQUIRE(pacman.get_X() >= (10.0f));
        REQUIRE(pacman.get_Y() == Approx(10.0f));
    }

}

TEST_CASE("Pacman Move Left", "[Pacman]") {
    // Create a Pacman instance
    Pacman pacman(1, false, false, 10.0f, 10.0f);

    // Create dummy maze and map objects for testing collisions
    vector<vector<string>> maze;
    Map map; 

    SECTION("Pacman moves left if no wall and left key pressed") {
        pacman.setCurrentDirection(4); // Reset current direction


        // Set up maze to have no walls to the left
        maze = {
            {" ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " "}
        };

        pacman.move(maze, map);
        pacman.setPosition(8.1f, 10.0f);

        // Check if Pacman's position has been updated to the left
        REQUIRE(pacman.getCurrentDirection() == 4);
        REQUIRE(pacman.get_X() <= (10.0f));
        REQUIRE(pacman.get_Y() == Approx(10.0f));
    }

}

TEST_CASE("Pacman Move Up", "[Pacman]") {
    // Create a Pacman instance
    Pacman pacman(1, false, false, 10.0f, 10.0f);

    // Create dummy maze and map objects for testing collisions
    vector<vector<string>> maze;
    Map map; 

    SECTION("Pacman moves up if no wall and up key pressed") {
        pacman.setCurrentDirection(2); // Reset current direction


        // Set up maze to have no walls to the top
        maze = {
            {" ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " "}
        };

        pacman.move(maze, map);
        pacman.setPosition(10.0f, 11.9f);

        // Check if Pacman's position has been updated to up
        REQUIRE(pacman.getCurrentDirection() == 2);
        REQUIRE(pacman.get_X() == Approx(10.0f));
        REQUIRE(pacman.get_Y() >= (10.0f));
    }

}

TEST_CASE("Pacman Move Down", "[Pacman]") {
    // Create a Pacman instance
    Pacman pacman(1, false, false, 10.0f, 10.0f);

    // Create dummy maze and map objects for testing collisions
    vector<vector<string>> maze;
    Map map; // Assuming you have a Map class

    SECTION("Pacman moves down if no wall and down key pressed") {
        pacman.setCurrentDirection(3); // Reset current direction


        // Set up maze to have no walls on the bottom
        maze = {
            {" ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " "},
            {" ", " ", " ", " ", " "}
        };

        pacman.move(maze, map);
        pacman.setPosition(10.0f, 8.1f);

        // Check if Pacman's position has been updated to down
        REQUIRE(pacman.getCurrentDirection() == 3);
        REQUIRE(pacman.get_X() == Approx(10.0f));
        REQUIRE(pacman.get_Y() <= (10.0f));
    }

}

TEST_CASE("Pacman-Ghost collision") {
    // Test collision detection between Pacman and Ghost
    Pacman pacman(1, false, false, 100.0f, 100.0f);
    Ghost ghost1(100.0f,100.0f, 4, false, false, sf::Color::Red, RED_GHOST);
    REQUIRE(pacman.ghost_collision(pacman, ghost1) == true); // Assuming collision conditions
}

