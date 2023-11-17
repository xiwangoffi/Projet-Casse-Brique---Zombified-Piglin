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
	sf::Vector2f velocity;
	float thickness;
	float angle;
	float origin_X;
	float origin_Y;

	sf::RectangleShape oHitBox;
	sf::Vector2f direction;

public:
	bool toDestroy;

	void setDirection(const sf::Vector2f& _direction);
	virtual void move(float dT);
	void multiplyDirection(float _factorX, float _factorY);

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
	sf::Vector2f getPosition() const { return sf::Vector2f(position.x, position.y); }
	sf::Vector2f getSize() const { return sf::Vector2f(size.x, size.y); }
	void addPosition(int x, int y, float speed, float dT);
	GameObject* setVelocity(sf::Vector2f _velocity);
	void update(float dT);

#pragma endregion Position

#pragma region Color

	void setFillColor(sf::Color _color);
	void setOutlineColor(sf::Color _outlineColor);

#pragma endregion Color

#pragma region Rotation

	void setRotation(float _angle, float fAnchorX = 1/2.f, float fAnchorY = 1 / 2.f);
	void addRotation(float _angle, float speed, float dT, float fAnchorX = 1 / 2.f, float fAnchorY = 1 / 2.f);
	float getRotation() { return pShape->getRotation(); }

#pragma endregion Rotation

#pragma region Origin

	void setOrigin(float fAnchorX, float fAnchorY);
	void setOriginCenter();

#pragma endregion Origin

#pragma region Collision

	bool isColliding(const GameObject* entity);
	void updateDirection(int side);
	void resolveCollision(const GameObject* entity, int side);
	int getSideToCollide(const GameObject* entity);

#pragma endregion Collision

	void draw(sf::RenderWindow& window, bool bDrawHitBox = false);
};