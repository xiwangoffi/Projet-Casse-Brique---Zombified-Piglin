#include "GameObject.hpp"

using namespace sf;
using namespace std;

GameObject::GameObject(int x, int y, int w, int h) {
	pShape = new RectangleShape(Vector2f(w, h));
	setPosition(Vector2f(x, y));
}

GameObject::GameObject(int x, int y, int radius) {
	pShape = new CircleShape(radius);
	setPosition(Vector2f(x, y));
}

GameObject::~GameObject() {}

void GameObject::setPosition(Vector2f _position) {
	position = _position;
	pShape->setPosition(position);
}

void GameObject::setSize(Vector2f _size) {
	size = _size;
	pShape->setScale(size);
}

void GameObject::setFillColor(Color _color) {
	color = _color;
	pShape->setFillColor(color);
}

void GameObject::setOutlineThickness(float _thickness) {
	thickness = _thickness;
	pShape->setOutlineThickness(thickness);
}

void GameObject::setOutlineColor(Color _outlineColor) {
	outlineColor = _outlineColor;
	pShape->setOutlineColor(outlineColor);
}

void GameObject::setRotation(float _angle) {
	angle = _angle;
	pShape->setRotation(angle);
}

bool IsInsideInterval(int v, int vMin, int vMax) 
{
	return v >= vMin && v <= vMax;
}

bool GameObject::isColliding(const GameObject entity) 
{
	bool b1 = IsInsideInterval(entity.position.x, position.x, size.x);
	bool b2 = IsInsideInterval(entity.position.x, entity.size.x, position.x);
	bool b3 = IsInsideInterval(entity.position.y, position.y, size.y);
	bool b4 = IsInsideInterval(entity.position.y, entity.size.y, position.y);
	/*
	cout << "Cond 1: entP-x: " << entity.position.x << ", posX: " << position.x << ", sizeX:" << size.x << endl;
	cout << "Cond 2: entP-x: " << entity.position.x << ", entSize-x: " << entity.size.x << ", posX:" << position.x << endl;
	cout << "Cond 3: entP-y: " << entity.position.y << ", posY: " << position.x << ", sizeY:" << size.y << endl;
	cout << "Cond 4: entP-y: " << entity.position.y << ", entSize-y: " << entity.size.y << ", sizeY:" << size.y << endl;
	
	b1 ? cout << "b1 true" << endl : cout << "b1 false" << endl;
	b2 ? cout << "b2 true" << endl : cout << "b2 false" << endl;
	b3 ? cout << "b3 true" << endl : cout << "b3 false" << endl;
	b4 ? cout << "b4 true" << endl : cout << "b4 false" << endl;*/

	return (entity.position.x < position.x + size.x ||
		entity.position.x + entity.size.x > position.x ||
		entity.position.y < position.y + size.y ||
		entity.position.y + entity.size.y > position.y);
}