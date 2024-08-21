#pragma once

#include <SFML/Graphics.hpp>
#include "../header/object.h"
#include "../header/move.h"
#include "../header/draw.h"
#include "../header/collisions.h"
#include "../header/map.h"
#include "../header/pacman.h" 
#include <array>
#include <cmath>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;


class Pacman;

enum GhostType {
    RED_GHOST,
    BLUE_GHOST,
    PINK_GHOST,
    ORANGE_GHOST
};

class Ghost : public Object, public GhostMovable, public Drawable {
private:
    bool isHiding;
    bool isDead;
    bool isFrightened;
    bool UseDoor;
    int currentDirection;
    float radius;
    sf::CircleShape ghost;
    GhostType type;
    pair<float, float> initialPos;

public:
    float ghost_speed;
    sf::Color originalRed = sf::Color::Red;
    sf::Color originalGreen = sf::Color::Green;
    sf::Color originalCyan = sf::Color::Cyan;
    sf::Color originalMagenta = sf::Color::Magenta;
    sf::Color frightenedColor = sf::Color::Blue;

    Ghost(float initialX, float initialY, int initialDirection, bool hiding, bool dead, sf::Color color, GhostType ghostType);

    bool getHidingState() const;
    void setHidingState(bool hiding);

    bool getDeathStatus() const;
    void setDeathStatus(bool dead);

    bool getDoor();
    void setDoor(bool usingDoor);

    bool getFrightenedState() const;
    void setFrightenedState(bool frightned, Map m);

    sf::Color getOriginalColor() const;

    float getRadius() const;

    int getCurrentDirection() const;
    void setCurrentDirection(int direction);
    int getOppositeDirection();



    const sf::CircleShape& getShape() const;

    void target(float pacmanX, float pacmanY, Map m, Pacman &p) override;
    void guard(Map m,int corner,Pacman &p) override;
    void scatter(Map) override;

    void target_coords(float pacmanX, float pacmanY, Map m);

    bool teleport();
    void draw(sf::RenderWindow& window);

    

    void setInitialPosition(float x, float y) {
        initialPos = std::make_pair(x, y);
    }
   
    std::pair<float, float> getInitialPosition() const {
        return initialPos;
    }

};