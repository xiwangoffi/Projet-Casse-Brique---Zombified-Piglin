#include "Canon.hpp"

Canon::Canon(int x, int y, int w, int h) : GameObject(x, y, w, h){
	pShape = new sf::RectangleShape(sf::Vector2f(w, h));
}

Canon::~Canon(){
}

void Canon::addCanonRotation(sf::Vector2i pos){
	std::cout << "M_x: " << pos.x << " S_x: " << getPosition().x << std::endl;
	std::cout << "M_y: " << pos.y << " S_y: " << getPosition().y << std::endl;
	std::cout << "x: " << pos.x - getPosition().x << " y: " << pos.y - getPosition().y << std::endl;
	if (pos.y < getPosition().y) {
		float mouseAngle = -atan2(pos.x - getPosition().x, pos.y - getPosition().y) * 180 / 3.14159;
		setOrigin(size.x * 0.5, size.y * 0.5);
		setRotation(mouseAngle);
	}
}
