#pragma once
#include "GameObject.hpp"

class Bullet : public GameObject {
private:
	sf::Vector2f dir;
	float speed;

public:
	Bullet(int x, int y, sf::Vector2f _direction);
	~Bullet();

	bool isOutOfScreen(float screenWidth, float screenHeight);
};
