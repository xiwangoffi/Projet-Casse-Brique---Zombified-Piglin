#include "Border.hpp"

Border::Border(int x, int y, int w, int h)
{
	GameObject(x,y,w,h);
}

Border::~Border()
{
	std::cout << "oh oui d�truit moi, vas-y, oui, aller, aller" << std::endl;
}
