#pragma once
#include <SFML/Graphics.hpp>
class Object{
private:
    sf::RectangleShape squareShape;
protected:
    short x_coordinate;
    short y_coordinate;

public:
    Object(short initialX, short initialY);
    sf::Clock boostClock;  // SFML clock to measure boost duration
    const sf::Time boostDuration = sf::seconds(7.0f);  // boost duration in seconds
    short get_X();
    short get_Y();
    void setPosition(short x, short y);
};
