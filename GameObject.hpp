#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

class GameObject {
private:
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Color color;
	sf::Shape* pShape;
	sf::Color outlineColor;
	float thickness;

public:
	GameObject(int x, int y, int w, int h);//rectangle
	GameObject(int x, int y, int radius);//circle
	~GameObject();

	sf::Shape* GetShape() { return pShape; }

	//void drawRectangle(sf::Vector2f _position, sf::Vector2f _size, sf::Color _color, float _thickness, sf::Color _outlineColor);
	//void drawCircle(sf::Vector2f _position, sf::Vector2f _size, sf::Color _color, float _thinckness, sf::Color _outlineColor);
	void setPosition(sf::Vector2f _position);
	void setSize(sf::Vector2f _size);
	void setFillColor(sf::Color _color);
	void setOutlineThickness(float _thickness);
	void setOutlineColor(sf::Color _outlineColor);
};