#include "InputManager.hpp"


bool Input::shoot() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){
        return true;
    }
}
/*
sf::Vector2f Input::mousePosition()
{
    sf::Vector2i localPosition = sf::Mouse::getPosition();
    std::cout << "Vous etes ici en X :" << localPosition.x << std::endl;
    std::cout << "Vous etes ici en Y :" << localPosition.y << std::endl;


    return;
}*/
