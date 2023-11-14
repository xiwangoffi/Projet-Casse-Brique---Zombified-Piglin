#include "GameObject.hpp"
#include "Mathematics.hpp"

using namespace sf;
using namespace std;

#pragma region Constructor

GameObject::GameObject(int x, int y, int w, int h) {
	pShape = new RectangleShape(Vector2f(w, h));
	size = Vector2f(w, h);
	oHitBox.setSize(size);
	oHitBox.setFillColor(sf::Color::Green);
	//pShape->setScale(size.x / size.x, size.y / size.y);

	setPosition(Vector2f(x, y));
}

GameObject::GameObject(int x, int y, int radius, float dot) {
	pShape = new CircleShape(radius, dot);
	pShape->setOrigin(radius, radius);
	setPosition(Vector2f(x, y));
}

GameObject::~GameObject() {}

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
	addPosition(direction.x, direction.y, 125.f, dT);
}


void GameObject::setDirection(const sf::Vector2f& _direction) 
{
	direction = _direction;
	Mathematics::Normalize(&direction);
	cout << "direction x: " << direction.x << " direction.y: " << direction.y << endl;
}

void GameObject::multiplyDirection(float _factorX, float _factorY)
{
	direction.x *= _factorX;
	direction.y *= _factorY;
	cout << "direction x: " << direction.x << " direction y: " << direction.y << endl;
	//setDirection(sf::Vector2f(direction.x, direction.y));
}

#pragma endregion Position

#pragma region setColors

void GameObject::setFillColor(Color _color) {
	color = _color;
	pShape->setFillColor(color);
}

void GameObject::setOutlineColor(Color _outlineColor) {
	outlineColor = _outlineColor;
	pShape->setOutlineColor(outlineColor);
}

#pragma endregion setColors

#pragma region Rotation

void GameObject::setRotation(float _angle, float fAnchorX, float fAnchorY) {
	setOrigin(fAnchorX, fAnchorY);

	angle = _angle;
	pShape->setRotation(angle);
}

void GameObject::addRotation(float _angle, float speed, float dT, float fAnchorX, float fAnchorY) {
	float angle = pShape->getRotation();
	angle += _angle * speed * dT;
	setRotation(angle, fAnchorX, fAnchorY);
}

void GameObject::addCanonRotation(Vector2i pos) {
	if (pos.y < position.y) {
		float mouseAngle = -atan2(pos.x - position.x, pos.y - position.y) * 180 / 3.14159;
		pShape->setRotation(mouseAngle);
	}
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

void GameObject::setOutlineThickness(float _thickness) {
	thickness = _thickness;
	pShape->setOutlineThickness(thickness);
}

#pragma region Collision

bool GameObject::isColliding(const GameObject* entity) 
{
	/*
	cout << endl;
	cout << "t1: " << entity->position.x << ", " << position.x << ", " << size.x << endl;
	cout << "t2: " << entity->position.x << ", " << entity->size.x << ", " << position.x << endl;
	cout << "t3: " << entity->position.y << ", " << position.y << ", " << size.y << endl;
	cout << "t4: " << entity->position.y << ", " << entity->size.y << ", " << position.y << endl;*/

	return !((entity->position.x >= position.x + size.x) // trop à droite
		|| (entity->position.x + entity->size.x <= position.x) // trop à gauche
		|| (entity->position.y >= position.y + size.y) // trop en bas
		|| (entity->position.y + entity->size.y <= position.y)); // trop en haut
}

void GameObject::updateDirection(int side) {
	switch (side) {
	case 0: // Top collision
		setDirection(sf::Vector2f(direction.x, -std::abs(direction.y)));
		break;
	case 1: // Bottom collision
		setDirection(sf::Vector2f(direction.x, std::abs(direction.y)));
		break;
	case 2: // Left collision
		setDirection(sf::Vector2f(-std::abs(direction.x), direction.y));
		break;
	case 3: // Right collision
		setDirection(sf::Vector2f(std::abs(direction.x), direction.y));
		break;
	}
}


void GameObject::resolveCollision(const GameObject* entity, int side, float& dT) {
	float overlap = 5.0f;

	switch (side) {
	case 0: // Top collision
		// multiplyDirection(0.f, -1.f);
		updateDirection(side);
		break;
	case 1: // Bottom collision
		multiplyDirection(0, -1);
		updateDirection(side);
		break;
	case 2: // Left collision
		// multiplyDirection(-1.f, 0.f);
		updateDirection(side);
		break;
	case 3: // Right collision
		// multiplyDirection(-1.f, 0.f);
		updateDirection(side);
		break;
	}
}


int GameObject::getSideToCollide(const GameObject* entity, float dT) {
	float ball_bottom = position.y + size.y;
	float brick_bottom = entity->position.y + entity->size.y;
	float ball_right = position.x + size.x;
	float brick_right = entity->position.x + entity->size.x;

	float y_overlap = std::min(ball_bottom, brick_bottom) - std::max(position.y, entity->position.y);
	float x_overlap = std::min(ball_right, brick_right) - std::max(position.x, entity->position.x);

	float minOverlapThreshold = 5.0f;

	if (y_overlap > x_overlap && y_overlap > minOverlapThreshold && isColliding(entity)) {
		if (position.x < entity->position.x) {
			// Left collision
			resolveCollision(entity, 2, dT); 
			return 2;
		}
		else {
			// Right collision
			resolveCollision(entity, 3, dT);
			return 3;
		}
	}
	else if (x_overlap > minOverlapThreshold && isColliding(entity)) {
		if (position.y < entity->position.y) {
			// Top collision
			resolveCollision(entity, 0, dT);
			return 0;
		}
		else {
			// Bottom collision
			resolveCollision(entity, 1, dT);
			return 1;
		}
	}

	return -1; // No collision
}

#pragma endregion Collision


void GameObject::draw(sf::RenderWindow& window, bool bDrawHitBox)
{
	window.draw(*pShape);

	if (bDrawHitBox) 
	{
		window.draw(oHitBox);
	}
}
