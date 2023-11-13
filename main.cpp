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
    GameObject canon(1920 * 0.45, 800, 100, 3.f);
    test.setFillColor(Color(255, 100, 0, 255));

    vector<GameObject> objList;
    objList.push_back(test);
    objList.push_back(temp);
    objList.push_back(canon);

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
            if (event.key.code == sf::Keyboard::Z)
                temp.addPosition(0, -50, 30.f, dT);            
            if (event.key.code == sf::Keyboard::S)
                temp.addPosition(0, +50, 30.f, dT);
            if (event.key.code == sf::Keyboard::Q)
                temp.addPosition(-50, 0, 30.f, dT);
            if (event.key.code == sf::Keyboard::D)
                temp.addPosition(50, 0, 30.f, dT);
        }
        if (!bullet){
            if (Input::shoot()) {
                cout << "Shoot !" << endl;
                bullet = 1;
            }            
        }

        window.clear();

        temp.addPosition(0, -50, 2.f, dT);
        canon.addCanonRotation(Mouse::getPosition(window));

        for (int i = 0; i < objList.size(); i++) {
            objList[i].draw(window);
        }

        temp.isColliding(&test) ? cout << "colliding" << endl : cout << "no collision" << endl;
        if (temp.getSideToCollide(&test, dT) == 0) {
            cout << "TOP" << endl;
        }
        if (temp.getSideToCollide(&test, dT) == 1) {
            cout << "BOTTOM" << endl;
        }
        if (temp.getSideToCollide(&test, dT) == 2) {
            cout << "LEFT" << endl;
        }
        if (temp.getSideToCollide(&test, dT) == 3) {
            cout << "RIGHT" << endl;
        }

        window.display();

        dT = clock.restart().asSeconds();
    }

    return 0;
}