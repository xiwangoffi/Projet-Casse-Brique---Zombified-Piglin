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
	float angle;
	float origin_X;
	float origin_Y;

	sf::RectangleShape oHitBox;
	sf::Vector2f velocity;

public:
	GameObject(int x, int y, int w, int h);//rectangle
	GameObject(int x, int y, int radius);//circle
	~GameObject();

	sf::Shape* GetShape() { return pShape; }

	//void drawRectangle(sf::Vector2f _position, sf::Vector2f _size, sf::Color _color, float _thickness, sf::Color _outlineColor);
	//void drawCircle(sf::Vector2f _position, sf::Vector2f _size, sf::Color _color, float _thinckness, sf::Color _outlineColor);
	void setPosition(sf::Vector2f _position);
	void setFillColor(sf::Color _color);
	void setOutlineThickness(float _thickness);
	void setOutlineColor(sf::Color _outlineColor);
	void setRotation(float _angle, float fAnchorX = 1/2.f, float fAnchorY = 1 / 2.f);
	void addRotation(float _angle, float speed, float dT, float fAnchorX = 1 / 2.f, float fAnchorY = 1 / 2.f);
	sf::Vector2f getPosition() { return pShape->getPosition(); }
	float getRotation() { return pShape->getRotation(); }
	void addPosition(int x, int y, float speed, float dT);
	bool isColliding(const GameObject* entity);
	void setOrigin(float fAnchorX, float fAnchorY);
	void setOriginCenter();
	int getSideToCollide(const GameObject* entity);


	void draw(sf::RenderWindow& window, bool bDrawHitBox = false);
};