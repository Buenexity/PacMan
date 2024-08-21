#include "../header/GameEngine.h"

GameEngine::GameEngine()
    : window(sf::VideoMode(21.f * 21.0f * 2, (16.0f + 21.f * 21.0f) * 2), "Sacman"),
      scatterDuration(sf::seconds(7.0f)),
      chaseDuration(sf::seconds(20.0f)),
      isScatterMode(false),
      pacman(new Pacman(1, false, false, 0.0f, 0.0f)) // Initialize the pacman object
{
    sf::View view(sf::FloatRect(0, 0, 21.0f * 21, 21.0f * 21)); // Adjust the FloatRect as needed
    window.setView(view);
    modeTimer.restart(); // Start the mode timer
    window.setFramerateLimit(60);; // Or a specific method to initialize the maze
}

void GameEngine::InitializeMap() {
    maze.set_Map(1); 
}

void GameEngine::run() {
    InitializeMap();
    InitializeAssets();
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close(); 
            }
        }
        
        window.clear();

        handleGhosts();
        handlePacman();
        render();

        window.display();
    }
}

void GameEngine::InitializeAssets() {
    
    for (auto& ghost : ghosts) {
        delete ghost;
    }
    ghosts.clear();
    maze.set_Map(1);
    maze.draw_Map(window);
    // Set the position of pacman
    pacman->setPosition(maze.pac_location.x, maze.pac_location.y);

    // Set the position of each ghost
    ghosts.push_back(new Ghost(maze.red_ghost_location.x, maze.red_ghost_location.y, 1, false, false, sf::Color::Red, RED_GHOST));
    ghosts.push_back(new Ghost(maze.blue_ghost_location.x, maze.blue_ghost_location.y, 1, false, false, sf::Color::Blue, BLUE_GHOST));
    ghosts.push_back(new Ghost(maze.pink_ghost_location.x, maze.pink_ghost_location.y, 1, false, false, sf::Color::Magenta, PINK_GHOST));
    ghosts.push_back(new Ghost(maze.orange_ghost_location.x, maze.orange_ghost_location.y, 1, false, false, sf::Color(255, 150, 0), ORANGE_GHOST));
}


void GameEngine::render() {
    maze.draw_Map(window);
    pacman->draw(window);
    for (int i = 0; i < ghosts.size(); i++) {
        ghosts[i]->draw(window);
    }
}

void GameEngine::handleGhosts() {
    // Ghost death, reset position
    for (int i = 0; i < ghosts.size(); i++) {
        if (ghosts[i]->getDeathStatus()) {
            ghosts[i]->setInitialPosition(ghosts[i]->getInitialPosition().first, ghosts[i]->getInitialPosition().second);
            ghosts[i]->setDeathStatus(false); 
        }
    }

    // Timer for ghosts
    sf::Time timepassed = modeTimer.getElapsedTime();

    if (timepassed.asSeconds() <= 4.0f) {
        for (int i = 0; i < ghosts.size(); i++) {
            ghosts[i]->target(pacman->get_X(), pacman->get_Y(), maze, *pacman);
            ghosts[i]->draw(window);
        }
    } 
    else {
        if (!isScatterMode && timepassed >= scatterDuration) {
            isScatterMode = true;
            modeTimer.restart();
        } else if (isScatterMode && timepassed >= chaseDuration) {
            isScatterMode = false;
            modeTimer.restart();
        }

        for (int i = 0; i < ghosts.size(); i++) 
        {

            if (isScatterMode)
                ghosts[i]->target(pacman->get_X(), pacman->get_Y(), maze, *pacman);
            else
                ghosts[i]->guard(maze, i + 1, *pacman);
            ghosts[i]->draw(window);
        }
    }
}

void GameEngine::handlePacman()
{
   vector<vector<string>> map = maze.GetMap();
   pacman->move(map,maze);
   pacman->draw(window);
}

   





