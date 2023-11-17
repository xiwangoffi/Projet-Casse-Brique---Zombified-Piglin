#pragma once
#include "GameObject.hpp"

class Brick : public GameObject {
private:
	int life;

public:

	Brick(int x, int y, int _life);
	~Brick();

	void takeDamage(int _damage);
	int getHp() { return life; }

	void Update(float dT);
};