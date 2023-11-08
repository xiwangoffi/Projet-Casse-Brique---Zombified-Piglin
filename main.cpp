#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "InputManager.hpp"
//#include "App.hpp"
    
using namespace sf;
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "My window", sf::Style::Fullscreen);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(240);
    int bullet = 0;

    GameObject test(50, 50, 1000, 100);
    GameObject temp(150, 500, 100, 100);
    test.setFillColor(Color(255, 100, 0, 255));

    Vector2f pos(80, 500);
    float dT = 0.f;
    
    Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
           if (event.key.code == sf::Keyboard::Escape)
				window.close();
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (!bullet){
            if (Input::shoot()) {
                cout << "Shoot !" << endl;
                bullet = 1;
            }            
        }
        //Input::mousePositionX(window);
        //Input::mousePositionY(window);
        window.clear();

        temp.addPosition(0, -1, 50.f, dT);
        temp.addRotation(5, 20.f, dT);

        window.draw(*test.GetShape());
        window.draw(*temp.GetShape());

        //temp.isColliding(&test) ? cout << "colliding" << endl : cout << "no collision" << endl;

        window.display();

        dT = clock.restart().asSeconds();
    }

    return 0;
}