#pragma once
#include <SFML/Graphics.hpp>

class Drawable {
public:
    virtual ~Drawable() {}
    virtual void draw(sf::RenderWindow& window) = 0;
};