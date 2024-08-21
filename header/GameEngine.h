#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Ghost.h"
#include "Pacman.h"
#include "map.h"

class GameEngine 
{
public:
    GameEngine();
    void run();
       void InitializeMap();
    void InitializeAssets();
   //void update();
    void render();
    //void handleEvents();
    void handleGhosts();
    void handlePacman();
    sf::RenderWindow window;
   
private:
    std::vector<Ghost*> ghosts;
    Map maze; 
    Pacman *pacman = new Pacman(1, false, false, 0.0f, 0.0f);
    sf::Clock modeTimer;
    sf::Time scatterDuration;
    sf::Time chaseDuration;
    bool isScatterMode; 
};




