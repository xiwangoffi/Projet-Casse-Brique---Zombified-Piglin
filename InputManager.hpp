#pragma once
#include "GameObject.hpp"

class Input {
private:
	sf::Vector2f mousePos;
	bool mouseClick;

public:
	sf::RenderWindow window;

	static bool shoot();
	static int mousePositionX(sf::RenderWindow window);
	static int mousePositionY(sf::RenderWindow window);
};
