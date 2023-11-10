#include "InputManager.hpp"


bool Input::shoot() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
        return true;
    }
}

int Input::getMousePositionX(sf::RenderWindow& _window)
{
    sf::Vector2i localPosition = sf::Mouse::getPosition(_window);
    std::cout << "Vous etes ici en X :" << localPosition.x << std::endl;
    return  localPosition.x;
}

int Input::getMousePositionY(sf::RenderWindow& _window)
{
    sf::Vector2i localPosition = sf::Mouse::getPosition(_window);
    std::cout << "Vous etes ici en Y :" << localPosition.y << std::endl;
    return  localPosition.y;
}