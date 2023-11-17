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
	window.create(sf::VideoMode(data.width, data.height), data.title, sf::Style::Fullscreen);
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
	go.clear();
	brick.clear();
	bullet.clear();

	sf::Texture background;
	background.loadFromFile("Ressources/Images/nether.png");
	sf::Sprite backgroundSprite(background);
	window.draw(backgroundSprite);
	
	canon = new Canon(window.getSize().x / 2, window.getSize().y - 100, 25, 70);//Canon
	go.push_back(new Border(0, 0, 1, window.getSize().y));//left
	go.push_back(new Border(0, 0, window.getSize().x,1));//top
	go.push_back(new Border(window.getSize().x-1, 0, 1, window.getSize().y));//right
	
	std::string text = LevelReader::SheetReader("Ressources/Levels/level1.txt");
	int line = 0;
	int column = 80;

	for (int i = 0; i < text.length(); i++) // LevelReader
	{
		if (text[i] == ' ') {
			line += 140;
		}
		else if (text[i] == '/') {
			column += 100;
			line = 0;
		}
		else if (text[i] == '5') {
			brick.push_back(new Brick(line, column, 5));
			line += 140;
		}
		else if (text[i] == '*') {
			break;
		}
	}
	

	for(int i = 0; i < brick.size(); ++i) {
		brick[i]->setFillColor(sf::Color::Blue);
	}

	//SoundBuffer init
	if (!damageSoundBuffer.loadFromFile("Ressources/Sounds/damage.wav")) {
		std::cerr << "Erreur lors du chargement de damage.wav" << std::endl;
	}

	if (!deleteSoundBuffer.loadFromFile("Ressources/Sounds/delete.wav")) {
		std::cerr << "Erreur lors du chargement de delete.wav" << std::endl;
	}

	if (!winSoundBuffer.loadFromFile("Ressources/Sounds/win.wav")) {
		std::cerr << "Erreur lors du chargement de win.wav" << std::endl;
	}

	//Sound init
	sDamage.setBuffer(damageSoundBuffer);
	sDelete.setBuffer(deleteSoundBuffer);
	sWin.setBuffer(winSoundBuffer);
	sDamage.setVolume(100.f);
	sDelete.setVolume(100.f);
	sWin.setVolume(100.f);
}

void App::Update() {
	if(win == false) {
		bool brickDestroyed = false;
		sf::Clock clock;
	
		sf::Vector2i mouseAngle = sf::Mouse::getPosition(window);
		Input::GetInstance()->getMousePosition(window);
		window.clear();

		canon->addCanonRotation(mouseAngle);

		for (int i = 0; i < go.size(); i++) {
			go[i]->draw(window);
		}
		for(int i = 0; i < brick.size(); ++i) {
			brick[i]->draw(window);
		}
		canon->draw(window);

		for (int i = 0; i < bullet.size(); ++i) { // Handle bullet (Collider, Delete)
			bullet[i]->move(dT);
			bullet[i]->draw(window);
			bullet[i]->canCollide = true;

			for (int j = 0; j < go.size(); ++j) {
				bullet[i]->getSideToCollide(go[j]);
			}
			for (int w = brick.size() - 1; w >= 0; --w) {
				int collisionSide = bullet[i]->getSideToCollide(brick[w]);
				if (collisionSide != -1 && bullet[i]->canCollide == true) {
					bullet[i]->canCollide = false;
					brick[w]->takeDamage(1);
					sDamage.play();

					if (brick[w]->getHp() == 0) {
						delete brick[w];
						brick.erase(brick.begin() + w);
						brickDestroyed = true;
						sDelete.play();
					}

					if (brickDestroyed) {
						break;
					}

					if (brick[w]->getHp() == 4) { // Handle Brick texture on damage taken
						brick[w]->setFillColor(sf::Color::Magenta);
					}
					if (brick[w]->getHp() == 3) {
						brick[w]->setFillColor(sf::Color::Cyan);
					}
					if (brick[w]->getHp() == 2) {
						brick[w]->setFillColor(sf::Color::Yellow);
					}
					if (brick[w]->getHp() == 1) {
						brick[w]->setFillColor(sf::Color::Red);
					}

					break;
				}
			}

 
			if (bullet[i]->isOutOfScreen(window.getSize().x, window.getSize().y)) { // Delete bullet when out of window
				delete bullet[i];
				bullet.erase(bullet.begin() + i);
				--i;
			}
		}

		if(brick.size() == 0) {
			win = true;
		}

	
 		window.display();

		dT = clock.restart().asSeconds();
	} else {
		std::cout << "YOU WIN" << std::endl;
		sWin.play();
	}
}

