#include "App.hpp"
#include "InputManager.hpp"
#include "GameObject.hpp"
#include <SFML/Graphics.hpp>


Clock::Clock() {
	sf::Clock clock;
	fps = 0;
	deltaTime = 0;
	
}

Clock::~Clock() 
{}

App::App(const WindowData& data)
{	
	window.create(sf::VideoMode(data.width, data.height), data.title, sf::Style::Fullscreen);
}

App::~App()
{
}

void App::HandleEvent() {
	sf::Event event;
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			Input::handleInputEvent(&event,window);
			break;
		default:
			break;
		}
	}
}

void App::Renderer() {
	int bullet = 0;

	GameObject test(50, 50, 1000, 100);
	GameObject temp(150, 500, 100, 100);
	test.setFillColor(Color(255, 100, 0, 255));

	Vector2f pos(80, 500);
	float dT = 0.f;

	sf::Clock clock;
}

void App::Update() {

	//Input::mousePositionX(window);
	//Input::mousePositionY(window);
	window.clear();

	temp.centerOrigin();
	//temp.fixHitbox();
	temp.addPosition(0, -50, 2.f, dT);
	temp.addRotation(50.f, 2.f, dT);
	//temp.setRotation(temp.getRotation() + 10 * dT);
	window.draw(*test.GetShape());
	window.draw(*temp.GetShape());

	RectangleShape hitbox = RectangleShape(Vector2f(1, 1) * 100.f);
	hitbox.setFillColor(Color(255, 158, 9, 255));
	hitbox.setPosition(temp.getPosition());
	hitbox.setOrigin(Vector2f(1, 1) * 50.f);

	window.draw(hitbox);

	temp.isColliding(&test) ? cout << "colliding" << endl : cout << "no collision" << endl;

	window.display();

	dT = clock.restart().asSeconds();
}

