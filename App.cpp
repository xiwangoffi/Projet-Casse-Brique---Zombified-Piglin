#include "App.hpp"
#include "InputManager.hpp"

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
	delete& go;
}

void App::HandleEvent() {
	sf::Event event;
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;
		default:
			Input::handleInputEvent(&event, window);
			break;
		}
	}
}

void App::Render() {

	int i = 5;
	int bullet = 0;
	go.clear();
	go.push_back(new GameObject(50, 50, 1000, 100));
	go.push_back(new GameObject(150, 500, 100, 100));
	go.push_back(new GameObject(1920 * 0.45, 800, 100, 3.f));

	go[0]->setFillColor(sf::Color(255, 100, 0, 255));
	go[1]->setDirection(sf::Vector2f(0, -50));

	sf::Vector2f pos(80, 500);
}

void App::Update() {

	sf::Clock clock;
	

	Input::getMousePositionX(window);
	Input::getMousePositionY(window);
	window.clear();

	go[1]->move(dT);


	go[2]->addCanonRotation(sf::Mouse::getPosition(window));

	for (int i = 0; i < go.size(); i++) {
		go[i]->draw(window);
	}

	go[1]->isColliding(go[0]) ? cout << "colliding" << endl : cout << "no collision" << endl;

	if (go[1]->getSideToCollide(go[0], dT) == 0) {
		cout << "TOP" << endl;
	}
	if (go[1]->getSideToCollide(go[0], dT) == 1) {
		cout << "BOTTOM" << endl;
	}
	if (go[1]->getSideToCollide(go[0], dT) == 2) {
		cout << "LEFT" << endl;
	}
	if (go[1]->getSideToCollide(go[0], dT) == 3) {
		cout << "RIGHT" << endl;
	}

	window.display();

	dT = clock.restart().asSeconds();
}

