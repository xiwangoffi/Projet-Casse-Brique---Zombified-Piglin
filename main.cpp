#include <iostream>
#include <SFML/Graphics.hpp>
//#include "App.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "My window", sf::Style::Fullscreen);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(240);

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
        window.display();
    }

    return 0;
}