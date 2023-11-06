#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
//#include "App.hpp"
    
using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "My window", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(240);

    GameObject test(50, 50, 50);
    test.setFillColor(Color(255, 100, 0, 255));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.key.code == sf::Keyboard::Escape) {
				window.close();
            }
        }
        window.clear();

        Shape* shape = test.GetShape();
        window.draw(*test.GetShape());

        window.display();
    }

    return 0;
}