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

#pragma region Constructor

	GameObject(int x, int y, int w, int h);//rectangle
	GameObject(int x, int y, int radius, float dot = NULL);//circle
	~GameObject();

#pragma endregion Constructor

	sf::Shape* GetShape() { return pShape; }
	void setOutlineThickness(float _thickness);

#pragma region Position

	void setPosition(sf::Vector2f _position);
	sf::Vector2f getPosition() { return pShape->getPosition(); }
	void addPosition(int x, int y, float speed, float dT);

#pragma endregion Position

#pragma region Color

	void setFillColor(sf::Color _color);
	void setOutlineColor(sf::Color _outlineColor);

#pragma endregion Color

#pragma region Rotation

	void setRotation(float _angle, float fAnchorX = 1/2.f, float fAnchorY = 1 / 2.f);
	void addRotation(float _angle, float speed, float dT, float fAnchorX = 1 / 2.f, float fAnchorY = 1 / 2.f);
	float getRotation() { return pShape->getRotation(); }
	void addCanonRotation(sf::Vector2i pos);

#pragma endregion Rotation

#pragma region Origin

	void setOrigin(float fAnchorX, float fAnchorY);
	void setOriginCenter();

#pragma endregion Origin

#pragma region Collision

	bool isColliding(const GameObject* entity);
	int getSideToCollide(const GameObject* entity);

#pragma endregion Collision

	void draw(sf::RenderWindow& window, bool bDrawHitBox = false);
};