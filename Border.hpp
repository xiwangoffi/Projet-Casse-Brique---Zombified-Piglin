#pragma once
#include "GameObject.hpp"

class Border : public GameObject {
private:
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Color color;
	sf::Shape* pShape;

public:
	Border(int x, int y, int w, int h);
	~Border();
};