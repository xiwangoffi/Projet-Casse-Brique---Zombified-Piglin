#pragma once
#include "GameObject.hpp"

class Input {
private:
	sf::Vector2f mousePos;
	bool mouseClick;
	sf::Event event;

public:
	Input();
	~Input();

	static Input* Instance;
	static Input* GetInstance() { return Instance; }
	static void Initialize();

	static bool handleMouseEvent(sf::Event* event, sf::RenderWindow& window, sf::Mouse::Button click);
	static bool handleKeyboardEvent(sf::Event* event, sf::RenderWindow& window, sf::Keyboard::Key key);

	sf::Vector2i getMousePosition(sf::RenderWindow& window);
};
