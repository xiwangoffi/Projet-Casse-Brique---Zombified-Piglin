#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

class GameObject {
private:
	int pos_x;
	int pos_y;
	sf::Color color;

public:
	GameObject();
	~GameObject();

	void drawRectangle()
};