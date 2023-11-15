#pragma once
#include "GameObject.hpp"

class Bullet : public GameObject {
private:
	sf::Vector2f dir;
	float speed;

public:
	Bullet(int x, int y, sf::Vector2f _direction, float _speed = 350);
	~Bullet();

	Bullet* setDirection(sf::Vector2f _direction);
	Bullet* setSpeed(float _speed);
	void IncreaseVelocity();

	
};
