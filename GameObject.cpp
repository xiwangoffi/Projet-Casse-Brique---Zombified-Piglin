#include "GameObject.hpp"

using namespace sf;
using namespace std;

#pragma region Constructor

GameObject::GameObject(int x, int y, int w, int h) {
	pShape = new RectangleShape(Vector2f(w, h));
	setPosition(Vector2f(x, y));
	setSize(Vector2f(w, h));
}

GameObject::GameObject(int x, int y, int radius) {
	pShape = new CircleShape(radius);
	setPosition(Vector2f(x, y));
}

GameObject::~GameObject() {}

#pragma endregion Constructor

#pragma region Position

void GameObject::setPosition(Vector2f _position) {
	position = _position;
	pShape->setPosition(position);
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

void GameObject::setRotation(float _angle) {
	angle = _angle;
	pShape->setRotation(angle);
}

void GameObject::addRotation(float _angle, float speed, float dT) {
	float angle = pShape->getRotation();
	angle += _angle * speed * dT;
	setRotation(angle);
}

#pragma endregion Rotation

void GameObject::setSize(Vector2f _size) {
	size = _size;
	//pShape->setScale(size);
	pShape->setScale(Vector2f(1, 1));
}

void GameObject::setOutlineThickness(float _thickness) {
	thickness = _thickness;
	pShape->setOutlineThickness(thickness);
}


bool GameObject::isColliding(const GameObject* entity) 
{
	return !((entity->position.x >= position.x + size.x) // trop à droite
		|| (entity->position.x + entity->size.x <= position.x) // trop à gauche
		|| (entity->position.y >= position.y + size.y) // trop en bas
		|| (entity->position.y + entity->size.y <= position.y)); // trop en haut
}