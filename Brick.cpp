#include "Brick.hpp"

Brick::Brick(int x, int y, int _life) : GameObject(x, y, 240, 80) {
	setPosition(sf::Vector2f(x, y));
	life = _life;
}

Brick::~Brick() {}

void Brick::takeDamage(int _damage) {
	life -= _damage;
}