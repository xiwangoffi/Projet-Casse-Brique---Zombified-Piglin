#include <iostream>
#include <SFML/Graphics.hpp>
#include "App.hpp"
    
using namespace sf;
using namespace std;

int main()
{
    WindowData data = {
		"Bricks",
        1920, 1080
	};

    App::Renderer();
    
    while (window.isOpen())
    {
        App::Update();
    }

    return 0;
}