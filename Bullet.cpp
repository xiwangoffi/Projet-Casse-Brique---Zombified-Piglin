#include "Bullet.hpp"
#include "Mathematics.hpp"

Bullet::Bullet(int x, int y, sf::Vector2f _direction) : GameObject(x, y, 15, 100.f) {
	dir = _direction;
	setDirection(dir);
}

Bullet::~Bullet() {}

bool Bullet::isOutOfScreen(float screenWidth, float screenHeight) {
	sf::Vector2f position = getPosition();
	return (position.x < 0 || position.x > screenWidth || position.y < 0 || position.y > screenHeight);
}
