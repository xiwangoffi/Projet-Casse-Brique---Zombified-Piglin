#include "GameObject.hpp"

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

void GameObject::addRotation(float _angle, float speed, float dT, float fAnchorX, float fAnchorY) { //C'est bugu� ici, hitbox d�cal�, going to cry
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

	return !((entity->position.x >= position.x + size.x) // trop � droite
		|| (entity->position.x + entity->size.x <= position.x) // trop � gauche
		|| (entity->position.y >= position.y + size.y) // trop en bas
		|| (entity->position.y + entity->size.y <= position.y)); // trop en haut
}

int GameObject::getSideToCollide(const GameObject* entity) {
	float ball_bottom = position.y + size.y;
	float brick_bottom = entity->position.y + entity->size.y;
	float ball_right = position.x + size.x;
	float brick_right = entity->position.x + entity->size.x;

	float b_collision = brick_bottom - position.y;
	float t_collision = ball_bottom - entity->position.y;
	float l_collision = ball_right - entity->position.x;
	float r_collision = brick_right - position.x;

	/*
	if (t_collision < b_collision && t_collision < l_collision && t_collision < r_collision) {
		return 0; // TOP COLLISION
	}
	if (b_collision < t_collision && b_collision < l_collision && b_collision < r_collision) {
		return 1; // BOTTOM COLLISION
	}
	if (l_collision < r_collision && l_collision < t_collision && l_collision < b_collision) {
		return 2; // LEFT COLLISION
	}
	if (r_collision < l_collision && r_collision < t_collision && r_collision < b_collision) {
		return 3; // RIGHT COLLISION
	}*/

	// Check for collision on each side with a minimum overlap threshold
	if (y_overlap > x_overlap && y_overlap > minOverlapThreshold) {
		if (position.x < entity->position.x) {
			// Left collision
			velocity.x = -std::abs(velocity.x); // Bounce in the opposite direction
			return 2;
		}
		else {
			// Right collision
			velocity.x = std::abs(velocity.x); // Bounce in the opposite direction
			return 3;
		}
	}
	else if (x_overlap > minOverlapThreshold) {
		if (position.y < entity->position.y) {
			// Top collision
			velocity.y = -std::abs(velocity.y); // Bounce in the opposite direction
			return 0;
		}
		else {
			// Bottom collision
			velocity.y = std::abs(velocity.y); // Bounce in the opposite direction
			return 1;
		}
	}
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