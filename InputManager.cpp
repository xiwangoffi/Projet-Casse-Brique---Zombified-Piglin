#include "InputManager.hpp"

Input* Input::Instance = nullptr;

Input::Input() {
    
}

Input::~Input() {
    delete Input::Instance;
}

void Input::Initialize() {
    if (Input::Instance != nullptr)
        return;

    Input::Instance = new Input();
}

bool Input::handleMouseEvent(sf::Event* event, sf::RenderWindow& window, sf::Mouse::Button click)
{
    return sf::Mouse::isButtonPressed(click);
}

bool Input::handleKeyboardEvent(sf::Event* event, sf::RenderWindow& window, sf::Keyboard::Key key)
{
    return sf::Keyboard::isKeyPressed(key);
}

sf::Vector2i Input::getMousePosition(sf::RenderWindow& _window)
{
    return sf::Mouse::getPosition(_window);
}

