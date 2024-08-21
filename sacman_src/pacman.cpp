#include "../header/pacman.h"
#include "../header/collisions.h"

#include <iostream>


//Pacman iniatizer 
Pacman::Pacman(int initialDirection, bool invincible, bool dead, float initialX, float initialY)
    : Object(initialX, initialY) // Call base class constructor
{
    isInvincible = invincible;
    isDead = dead;
    currentDirection = initialDirection;
    radius = pac_size;
    lives = 3;
    x_coordinate = initialX;
    y_coordinate = initialY;

    pac.setRadius(radius);
    pac.setFillColor(sf::Color::Yellow);
    pac.setPosition(x_coordinate, y_coordinate);
}


//Setters and Getters
bool Pacman::getInvincibility() const
{
    return isInvincible;
}

void Pacman::setInvincibility(bool invincible)
{
    isInvincible = invincible;
    invincibleTimer.restart();
}

bool Pacman::getDeathStatus() const
{
    return isDead;
}

void Pacman::setDeathStatus(bool dead)
{
    isDead = dead;
}

int Pacman::getCurrentDirection() const
{
    return currentDirection;
}

void Pacman::setCurrentDirection(int direction) {
    currentDirection = direction;
}

float Pacman::getRadius() const {
    return radius;
}

int Pacman::getLives() const {
    return lives;
}

void Pacman::decrementLives() {
    lives--;
}

bool Pacman::getBoosted() const {
    return isBoosted;
}

void Pacman::setBoosted(bool boost) {
    isBoosted = boost;
    boostClock.restart();
}

void Pacman::move(vector<vector<string>>& maze, Map &m)
{

    collisions collide;
    std::array<bool, 4> walls
    {
    collide.map_collision(0, 0, pacspeed + x_coordinate, y_coordinate, maze,m),
    collide.map_collision(0, 0, x_coordinate, y_coordinate - pacspeed, maze,m),
    collide.map_collision(0, 0, x_coordinate, y_coordinate + pacspeed, maze,m),
    collide.map_collision(0, 0, x_coordinate - pacspeed, y_coordinate, maze,m)
    };


    //activate collect pellets;
    eatingPellet = collide.map_collision(1, 0, x_coordinate, y_coordinate, maze,m);

    //activate collect pellets for points/score;
    bool power_pellet = collide.map_collision(1, 0, x_coordinate, y_coordinate, maze,m);
    // score += collide.pellet_collision(x_coordinate, y_coordinate, maze,m);
    if (eatingPellet) {
        // score += collide.pellet_collision(x_coordinate, y_coordinate, maze,m);
        score += 10;
        cout << "Score: " << score << '\n';
    }
    

    // Accessing individual values in the walls array:
    bool right = walls[0];
    bool up = walls[1];
    bool down = walls[2];
    bool left = walls[3];

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if (!right)
            currentDirection = 1;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if (!up)
            currentDirection = 2;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        if (!down)
            currentDirection = 3;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if (!left)
            currentDirection = 4;
    }
    if(!walls[currentDirection-1])
    {
        // Adjust Pacman's position based on the chosen direction
        switch (currentDirection) 
        {
            case 1: // Right
                x_coordinate += pacspeed;
                break;
            case 2: // Up
                y_coordinate -= pacspeed;
                break;
            case 3: // Down
                y_coordinate += pacspeed;
                break;
            case 4: // Left
                x_coordinate -= pacspeed;
                break;
        }
    }

    //using teleporter
    if (x_coordinate > 21.0f * 21) {
        x_coordinate = 0.0f;
    }

    //using teleporter
    if (x_coordinate < 0.0f) {
        x_coordinate = 21.0f*21;
    }

    if (collide.map_collision(1,0, x_coordinate, y_coordinate, maze, m)) {
        setBoosted(true);
        setInvincibility(true);
    }
    if (isInvincible && invincibleTimer.getElapsedTime() >= boostDuration) {
        setInvincibility(false);
    }

}

bool Pacman::ghost_collision(Pacman& pacman, Ghost& ghost) {
    float x_distance = pacman.get_X() - ghost.get_X();
    float y_distance = pacman.get_Y() - ghost.get_Y();

    // distance equation -> sqrt(x^2 + y^2)
    float distance = std::sqrt((x_distance) * (x_distance) + (y_distance) * (y_distance));

    if (distance < (pacman.getRadius() + ghost.getRadius())) {
        return true;
    } else {
        return false;
    }
}



//Draw Pacman 
void Pacman::draw(sf::RenderWindow& window) {

    sf::Sprite sprite;
    sf::Texture texture;
    int offset = 5;
    sprite.setPosition(x_coordinate - offset, y_coordinate - offset);

    texture.loadFromFile("extraFiles/pacman_animation.png");

    int tileLength = 32;

    sprite.setTexture(texture);

    if (currentDirection > 0) {
        sprite.setTextureRect(sf::IntRect(0, tileLength * currentDirection - tileLength, tileLength, tileLength));
    }
    else {
        // Use a default frame when Pacman is not moving
        sprite.setTextureRect(sf::IntRect(0, tileLength * 5 - tileLength, tileLength, tileLength));
    }
    window.draw(sprite);
}