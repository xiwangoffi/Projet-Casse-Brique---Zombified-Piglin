#pragma once
#include "GameObject.hpp"

class Input {
private:
	sf::Vector2f mousePos;
	bool mouseClick;
	sf::Event event;
public:
	static void handleInputEvent(sf::Event* event, sf::RenderWindow& window);
	static int mousePositionX(sf::RenderWindow& window);
	static int mousePositionY(sf::RenderWindow& window);
};
