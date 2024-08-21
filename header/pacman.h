#ifndef PACMAN_H
#define PACMAN_H
#include <SFML/Graphics.hpp>
#include "../header/object.h"
#include "../header/Move.h"
#include "../header/draw.h"
#include "../header/collisions.h"
#include "../header/ghost.h"
#include <array>
#include <vector>

using namespace std;

class Ghost;


class Pacman : public Object, public Drawable 
{
private:
    bool isInvincible;
    bool isDead;
    bool isBoosted;
    bool eatingPellet;
    int currentDirection;
    float radius;
    unsigned int lives;
    sf::CircleShape pac;
    std::vector<std::vector<bool>> pellets;

public:
    //setters and getters
    float pac_size = 21.0f/2;
    float pacspeed = 3.0f;
    int score = 0;
    sf::Clock invincibleTimer;

    Pacman(int initialDirection, bool invincible, bool dead, float initialX, float initialY);
    //Setters and Getters
    bool getInvincibility() const;
    void setInvincibility(bool invincible);

    // Death Status Getter and Setter
    bool getDeathStatus() const;
    void setDeathStatus(bool dead);

    // Set Direction getter or setter
    int getCurrentDirection() const;
    void setCurrentDirection(int direction);

    float getRadius() const;

    int getLives() const;
    void decrementLives();

    bool getBoosted() const;
    void setBoosted(bool boost);

    //bool getMunch();

    // Get Pacman's shape
    const sf::CircleShape& getShape() const;

    // Move Pacman (implements Movable interface)
    void move(vector<vector<string>> &i_map, Map &m);

    // Check if Pacman hits a ghost
    bool ghost_collision(Pacman& pacman, Ghost& ghost);

    // Draw Pacman (implements Drawable interface)
    void draw(sf::RenderWindow& window) override;
    //void move(Directions direction) override;

};
#endif // PACMAN_H