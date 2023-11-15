#include "App.hpp"
#include "InputManager.hpp"
#include "Bullet.hpp"
#include "Brick.hpp"
#include "Mathematics.hpp"

using namespace std;

Clock::Clock() {
	sf::Clock clock;
	fps = 0;
	deltaTime = 0;
	
}

Clock::~Clock() 
{}

App::App(const WindowData& data)
{	
	window.create(sf::VideoMode(data.width, data.height), data.title, sf::Style::Default);
}

App::~App()
{
	for (int i = 0; i < go.size(); i++) {
		delete go[i];
	}
}

void App::HandleEvent() {
	sf::Event event;
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			if (Input::handleKeyboardEvent(&event, window, sf::Keyboard::Escape)) {
				window.close();
			}
			break;
		case sf::Event::MouseButtonPressed:
			if (Input::handleMouseEvent(&event, window, sf::Mouse::Right)) {
				std::cout << "UwU Papagnan UwU" << std::endl;
			}
			break;
		default: 
			break;
		}
	}
}

void App::Render() {

	int i = 5;
	go.clear();
	go.push_back(new GameObject(50, 50, 1000, 100));
	go.push_back(new GameObject(1350, 500, 100, 100));
	go.push_back(new GameObject(1920 * 0.45, 800, 100, 3.f));
	go.push_back(new);

	go[0]->setFillColor(sf::Color(255, 100, 0, 255));
	go[1]->setDirection(sf::Vector2f(-50, -70));

	sf::Vector2f pos(80, 500);
}

void App::Update() {

	sf::Clock clock;
	

	Input::GetInstance()->getMousePosition(window);
	window.clear();

	go[1]->move(dT);


	go[2]->addCanonRotation(sf::Mouse::getPosition(window));

	for (int i = 0; i < go.size(); i++) {
		go[i]->draw(window);
	}

	go[1]->isColliding(go[0]) ? cout << "colliding" << endl : cout << "no collision" << endl;

	go[1]->getSideToCollide(go[0], dT);

	window.display();

	dT = clock.restart().asSeconds();
}

