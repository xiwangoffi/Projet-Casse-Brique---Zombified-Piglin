#include "Canon.hpp"
#include "Mathematics.hpp"

Canon::Canon(int x, int y, int w, int h) : GameObject(x, y, w, h){
	pShape = new sf::RectangleShape(sf::Vector2f(w, h));
}

Canon::~Canon(){
}

void Canon::addCanonRotation(sf::Vector2i pos) {
    direction = sf::Vector2f(pos.x, pos.y) - getPosition();
    Mathematics::Normalize(&direction);
    float mouseAngle = -atan2(direction.x, direction.y) * 180 / 3.14159;
    setDirection(direction);

    setOrigin(size.x * 0.5, size.y * 0.5);
    setRotation(mouseAngle);
}