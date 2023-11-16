#include "Border.hpp"

Border::Border(int x, int y, int w, int h) : GameObject(x,y,w,h){
	Border::pShape = new sf::RectangleShape(sf::Vector2f(w,h));
}

Border::~Border(){
}


