#pragma once
#include "GameObject.hpp"

class Canon : public GameObject {
private:
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Color color;
	sf::RectangleShape* pShape;

public:
	Canon(int x, int y, int w, int h);
	~Canon();
	void addCanonRotation(sf::Vector2i pos);
};