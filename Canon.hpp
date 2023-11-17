#pragma once
#include "GameObject.hpp"

class Canon : public GameObject {
private:
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Color color;
	sf::RectangleShape* pShape;
	sf::Vector2f direction;

public:
	Canon(int x, int y, int w, int h);
	~Canon();
	sf::Vector2f getDirection() const { return direction; }
	void addCanonRotation(sf::Vector2i pos);
};