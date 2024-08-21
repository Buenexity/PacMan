#include "../header/object.h" 

Object::Object(short initialX, short initialY)
    : x_coordinate(initialX), y_coordinate(initialY) {}

short Object::get_X() {
    return x_coordinate;
}

short Object::get_Y() {
    return y_coordinate;
}

void Object::setPosition(short x, short y) {
    x_coordinate = x;
    y_coordinate = y;
}
