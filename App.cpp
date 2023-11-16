#include "App.hpp"
#include "Mathematics.hpp"


using namespace std;

bool shoot;

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
				cout << "gsqcvZI§L%µ.LM?KNG?/GFDJVWDN?.VLNHJK.?RNG BJGHJKBRGN TVRGYFUBJN TVGHJ" << endl;
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
	go.push_back(new GameObject(500, 500, 100, 100)); // testeur
	canon = new Canon(window.getSize().x / 2, window.getSize().y - 300, 25, 70); // Canon
	//go.push_back(new Bullet(go[2]->getPosition().x - 100, go[2]->getPosition().y - 100, (sf::Vector2f)Input::GetInstance()->getMousePosition(window)));
	go.push_back(new Border(0, 0, 1, window.getSize().y));
	go.push_back(new Border(0, 0, window.getSize().x,1));
	go.push_back(new Border(window.getSize().x-1, 0, 1, window.getSize().y));
	go.push_back(new Border(0, window.getSize().y+60, window.getSize().x,1));


	go[0]->setFillColor(sf::Color(255, 100, 0, 255));
	go[1]->setDirection(sf::Vector2f(50,50));
	go[3]->setDirection(sf::Vector2f(Input::GetInstance()->getMousePosition(window).x, Input::GetInstance()->getMousePosition(window).y));

	sf::Vector2f pos(80, 500);
}

void App::Update() {

	sf::Clock clock;
	
	sf::Vector2i mouseAngle = sf::Mouse::getPosition(window);
	Input::GetInstance()->getMousePosition(window);
	window.clear();

	go[1]->move(dT);

	//std::cout << "x: " << mouseAngle.x << " y: " << mouseAngle.y << std::endl;
	canon->addCanonRotation(mouseAngle);


	for (int i = 0; i < go.size(); i++) {
		go[i]->draw(window);
	}
	canon->draw(window);

	//go[1]->isColliding(go[0]) ? cout << "colliding" << endl : cout << "no collision" << endl;

	for (int i = 0; i < go.size(); ++i) 
	{
		go[1]->getSideToCollide(go[i], dT);
	}

	/*
	if(!go[1]->getSideToCollide(go[6], dT)) {}
	*/
	/*
	if (!go[1]->getSideToCollide(go[6], dT)) {
		go[1]->toDestroy = true;
	}

	for (int i = 0; i < go.size() - 1; i++) {
		GameObject* objects = go[i];
		if (objects->toDestroy) {
			go.erase(go.begin() + i);
			delete objects;
		}
	}
	*/
	

	window.display();

	dT = clock.restart().asSeconds();
}

