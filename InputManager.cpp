#include "InputManager.hpp"


void Input::handleInputEvent(sf::Event* event, sf::RenderWindow& window) {
    switch (event->type) {
    case sf::Keyboard::Escape:
        window.close();
        break;
     case sf::Mouse::Right:
         std::cout << "shoot" << std::endl;
         break;
    default:
        break;
    }
}
int Input::mousePositionX(sf::RenderWindow& _window)
{
    sf::Vector2i localPosition = sf::Mouse::getPosition(_window);
    std::cout << "Vous etes ici en X :" << localPosition.x << std::endl;
    return  localPosition.x;
}

int Input::mousePositionY(sf::RenderWindow& _window)
{
    sf::Vector2i localPosition = sf::Mouse::getPosition(_window);
    std::cout << "Vous etes ici en Y :" << localPosition.y << std::endl;
    return  localPosition.y;
}