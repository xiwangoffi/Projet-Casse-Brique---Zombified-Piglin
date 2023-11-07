#pragma once
#include "GameObject.hpp"

class Input {
private:
	sf::Vector2f mousePos;
	bool mouseClick;

public:
	static bool shoot();
	sf::Vector2f mousePosition();
};
