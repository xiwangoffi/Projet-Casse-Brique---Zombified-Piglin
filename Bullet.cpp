#include "Bullet.hpp"
#include "Mathematics.hpp"

Bullet::Bullet(int x, int y, sf::Vector2f _direction, float _speed) : GameObject(x, y, 30, 30) {
	setDirection(_direction)->setSpeed(_speed);
}

Bullet::~Bullet() {}

Bullet* Bullet::setDirection(sf::Vector2f _dir) {
	dir = _dir;
	IncreaseVelocity();
	return this;
}

Bullet* Bullet::setSpeed(float _speed) {
	speed = _speed;
	IncreaseVelocity();
	return this;
}

void Bullet::IncreaseVelocity() {
	setVelocity(dir * speed);
}