#include "InputManager.hpp"


bool Input::shoot() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
        return true;
    }
}

int Input::mousePositionX(sf::RenderWindow _window)
{
    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
    std::cout << "Vous etes ici en X :" << localPosition.x << std::endl;
    return  localPosition.x;
}

int Input::mousePositionY(sf::RenderWindow _window)
{
    sf::Vector2i localPosition = sf::Mouse::getPosition(window);
    std::cout << "Vous etes ici en Y :" << localPosition.y << std::endl;
    return  localPosition.y;
}