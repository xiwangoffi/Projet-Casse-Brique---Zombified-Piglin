#pragma once
#include "GameObject.hpp"

class Input {
private:
	sf::Vector2f mousePos;
	bool mouseClick;

public:
	static bool shoot();
	static int getMousePositionX(sf::RenderWindow& window);
	static int getMousePositionY(sf::RenderWindow& window);
};
