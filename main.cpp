#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include "InputManager.hpp"
//#include "App.hpp"
    
using namespace sf;
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "My window", sf::Style::Default);
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
            Input::shoot();
            cout << "Shoot";
            bullet = 1;
            
        }
        window.clear();

        temp.centerOrigin();
        //temp.fixHitbox();
        temp.addPosition(0, -50, 2.f, dT);
        temp.addRotation(50.f, 2.f, dT);
        //temp.setRotation(temp.getRotation() + 10 * dT);
        window.draw(*test.GetShape());
        window.draw(*temp.GetShape());

        RectangleShape hitbox = RectangleShape(Vector2f(1, 1) * 100.f);
        hitbox.setFillColor(Color(255, 158, 9, 255));
        hitbox.setPosition(temp.getPosition());
        hitbox.setOrigin(Vector2f(1, 1) * 50.f);

        window.draw(hitbox);

        temp.isColliding(&test) ? cout << "colliding" << endl : cout << "no collision" << endl;

        window.display();

        dT = clock.restart().asSeconds();
    }

    return 0;
}