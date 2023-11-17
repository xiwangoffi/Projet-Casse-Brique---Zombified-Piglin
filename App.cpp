#include "App.hpp"
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
				bullet.push_back(new Bullet(canon->getPosition().x, canon->getPosition().y - 50, canon->getDirection()));
			}
			break;
		default: 
			break;
		}
	}
}

void App::Render() {
	window.getSize().x;
	window.getSize().y;
	int i = 5;
	go.clear();
	go.push_back(new GameObject(50, 50, 1000, 100)); // Brick de référence
	go.push_back(new GameObject(500, 500, 50, 50)); // testeur
	go.push_back(new Border(0, 0, 1, window.getSize().y));
	go.push_back(new Border(0, 0, window.getSize().x,1));
	go.push_back(new Border(window.getSize().x-1, 0, 1, window.getSize().y));
	go.push_back(new Border(0, window.getSize().y+60, window.getSize().x,1));

	canon = new Canon(window.getSize().x / 2, window.getSize().y - 300, 25, 70);

	go[0]->setFillColor(sf::Color(255, 100, 0, 255));
	go[1]->setDirection(sf::Vector2f(-50, -70));

}

void App::Update() {

	sf::Clock clock;
	
	sf::Vector2i mouseAngle = sf::Mouse::getPosition(window);
	Input::GetInstance()->getMousePosition(window);
	window.clear();

	go[1]->move(dT);

	canon->addCanonRotation(mouseAngle);

	for (int i = 0; i < go.size(); i++) {
		go[i]->draw(window);
	}
	canon->draw(window);

	for (int i = 0; i < bullet.size(); ++i) {
		bullet[i]->move(dT);
		bullet[i]->draw(window);

		if (bullet[i]->isOutOfScreen(window.getSize().x, window.getSize().y)) {
			delete bullet[i];
			bullet.erase(bullet.begin() + i);
			--i;
		}
	}

	
	window.display();

	dT = clock.restart().asSeconds();
}

