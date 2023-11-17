#include "GameObject.hpp"
#include "Mathematics.hpp"

using namespace sf;
using namespace std;

#pragma region Constructor

GameObject::GameObject(int x, int y, int w, int h) { // RectangleShape constructor
	pShape = new RectangleShape(Vector2f(w, h));
	size = Vector2f(w, h);
	oHitBox.setSize(size);
	oHitBox.setFillColor(sf::Color::Green);

	setPosition(Vector2f(x, y));
	toDestroy = false;
}

GameObject::GameObject(int x, int y, int radius, float dot) { // CircleShape constructor
	pShape = new CircleShape(radius, dot);
	pShape->setOrigin(radius, radius);
	setPosition(Vector2f(x, y));
}

GameObject::~GameObject() {
	
}

#pragma endregion Constructor

#pragma region Position

void GameObject::setPosition(Vector2f _position) {
	position = _position;
	pShape->setPosition(position);
	oHitBox.setPosition(position);
}

void GameObject::addPosition(int x, int y, float speed, float dT) {
	Vector2f pos = pShape->getPosition();
	pos += Vector2f(x, y) * speed * dT;
	setPosition(pos);
}

void GameObject::move(float dT) 
{

	Vector2f newPos = position + direction * dT * 330.f;
	setPosition(newPos);
}


void GameObject::setDirection(const sf::Vector2f& _direction) 
{
	direction = _direction;
	Mathematics::Normalize(&direction);
}

void GameObject::multiplyDirection(float _factorX, float _factorY)
{
	direction.x *= _factorX;
	direction.y *= _factorY;
}

GameObject* GameObject::setVelocity(Vector2f _velocity) {
	velocity = _velocity;
	return this;
}

void GameObject::update(float dT)
{
	move(dT);
}

#pragma endregion Position

#pragma region setColors

void GameObject::setFillColor(Color _color) {
	color = _color;
	pShape->setFillColor(color);
}

void GameObject::setTexture(const char* path) {
	sf::Texture texture;
	texture.loadFromFile(path);
	pShape->setTexture(&texture);
}

void GameObject::setOutlineColor(Color _outlineColor) {
	outlineColor = _outlineColor;
	pShape->setOutlineColor(outlineColor);
}

#pragma endregion setColors

#pragma region Rotation

void GameObject::setRotation(float _angle, float fAnchorX, float fAnchorY) { // Static rotation
	setOrigin(fAnchorX, fAnchorY);

	angle = _angle;
	pShape->setRotation(angle);
}

void GameObject::addRotation(float _angle, float speed, float dT, float fAnchorX, float fAnchorY) { // Dynamic rotation
	float angle = pShape->getRotation();
	angle += _angle * speed * dT;
	setRotation(angle, fAnchorX, fAnchorY);
}

#pragma endregion Rotation

#pragma region Origin

void GameObject::setOrigin(float fAnchorX, float fAnchorY)
{
	float fX = fAnchorX * size.x;
	float fY = fAnchorY * size.y;

	pShape->setOrigin(fX, fY);
	oHitBox.setOrigin(fX, fY);
}

void GameObject::setOriginCenter() {
	setOrigin(1/2.f, 1 / 2.f);
}

#pragma endregion Origin

#pragma region Collision

bool GameObject::isColliding(const GameObject* entity) // Detect Collider AABB
{
	return !((entity->position.x >= position.x + size.x) // trop à droite
		|| (entity->position.x + entity->size.x <= position.x) // trop à gauche
		|| (entity->position.y >= position.y + size.y) // trop en bas
		|| (entity->position.y + entity->size.y <= position.y)); // trop en haut
}

void GameObject::updateDirection(int side) { // Adjust directions when colliding
	switch (side) {
	case 0: // Top collision
		setDirection(sf::Vector2f(direction.x, -std::abs(direction.y)));
		break;
	case 1: // Bottom collision
		setDirection(sf::Vector2f(-direction.x, std::abs(direction.y)));
		break;
	case 2: // Left collision
		setDirection(sf::Vector2f(-std::abs(direction.x), direction.y));
		break;
	case 3: // Right collision
		setDirection(sf::Vector2f(std::abs(direction.x), direction.y));
		break;
	}
}


void GameObject::resolveCollision(const GameObject* entity, int side) { // Function to handle good collider side

	switch (side) {
	case 0: // Top collision
		updateDirection(side);
		break;
	case 1: // Bottom collision
		multiplyDirection(-1, -1);
		updateDirection(side);
		break;
	case 2: // Left collision
		updateDirection(side);
		break;
	case 3: // Right collision
		updateDirection(side);
		break;
	}
}

int GameObject::getSideToCollide(const GameObject* entity) { // Detect collision between CircleShape -> RectangleShape
	sf::CircleShape* ball = dynamic_cast<sf::CircleShape*>(pShape);
	if (!ball) {
		// Debug in case we send the wrong Shape to the collider
		return -1;
	}

	sf::Vector2f rectCenter(entity->position.x + 0.5f * entity->size.x, entity->position.y + 0.5f * entity->size.y);

	float deltaX = position.x - std::max(entity->position.x, std::min(position.x, entity->position.x + entity->size.x));
	float deltaY = position.y - std::max(entity->position.y, std::min(position.y, entity->position.y + entity->size.y));

	float distanceSquared = deltaX * deltaX + deltaY * deltaY;

	if (distanceSquared <= (ball->getRadius() * ball->getRadius())) {
		// Collision detected

		float overlapX = std::max(0.0f, std::min(position.x + ball->getRadius(), entity->position.x + entity->size.x) - std::max(position.x - ball->getRadius(), entity->position.x));
		float overlapY = std::max(0.0f, std::min(position.y + ball->getRadius(), entity->position.y + entity->size.y) - std::max(position.y - ball->getRadius(), entity->position.y));

		if (overlapX > overlapY) {
			// Collision on top or bottom
			if (position.y < entity->position.y + entity->size.y) {
				resolveCollision(entity, 0); // Top collision
				return 0;
			}
			else {
				resolveCollision(entity, 1); // Bottom collision
				return 1;
			}
		}
		else {
			// Collision on left or right
			if (position.x < entity->position.x) {
				resolveCollision(entity, 2); // Left collision
				return 2;
			}
			else {
				resolveCollision(entity, 3); // Right collision
				return 3;
			}
		}
	}

	return -1; // No collision
}

#pragma endregion Collision

void GameObject::setOutlineThickness(float _thickness) {
	thickness = _thickness;
	pShape->setOutlineThickness(thickness);
}

void GameObject::draw(sf::RenderWindow& window, bool bDrawHitBox)
{
	window.draw(*pShape);

	if (bDrawHitBox) 
	{
		window.draw(oHitBox);
	}
}
