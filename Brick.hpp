#pragma once
#include "GameObject.hpp"

class Brick : public GameObject {
private:
	int life;

public:

	Brick(sf::Vector2f _position, int _life);
	~Brick();

	Brick* setHp(int _hp);
	bool isBroken();

	void Update(float dT);
};