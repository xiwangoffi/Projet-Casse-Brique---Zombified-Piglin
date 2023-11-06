#pragma once
#include "GameObject.hpp"

using namespace sf;

GameObject::GameObject(int x, int y, int w, int h) {
	pShape = new RectangleShape(Vector2f(w, h));
	pShape->setPosition(Vector2f(x, y));
}

GameObject::GameObject(int x, int y, int radius) {
	pShape = new CircleShape(radius);
	pShape->setPosition(Vector2f(x, y));
}

GameObject::~GameObject() {}

void GameObject::setPosition(Vector2f _position) {
	position = _position;
}

void GameObject::setSize(Vector2f _size) {
	size = _size;
}

void GameObject::setFillColor(Color _color) {
	color = _color;
	pShape->setFillColor(color);
}

void GameObject::setOutlineThickness(float _thickness) {
	thickness = _thickness;
}

void GameObject::setOutlineColor(Color tamère) {
	outlineColor = tamère;
}