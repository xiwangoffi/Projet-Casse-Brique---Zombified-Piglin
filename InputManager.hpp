#pragma once
#include "GameObject.hpp"

class Input {
private:
	sf::Vector2f mousePos;
	bool mouseClick;
	sf::Event event;
public:
	static void handleInputEvent(sf::Event* event, sf::RenderWindow& window);
	static int getMousePositionX(sf::RenderWindow& window);
	static int getMousePositionY(sf::RenderWindow& window);
};
