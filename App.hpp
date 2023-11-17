#pragma once
#include "GameObject.hpp"
#include "InputManager.hpp"
#include "Bullet.hpp"
#include "Brick.hpp"
#include "Border.hpp"
#include "Canon.hpp"
#include "LevelReader.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <SFML/Audio.hpp>

struct WindowData {
	const char* title;
	int width = 1920;
	int height = 1080;
};

class Clock {
private:
	int fps;
	double deltaTime;

public:
	Clock();
	~Clock();

	double DeltaTime() { return deltaTime; }
	int FPS() { return fps; }
};

class App {
private:
	sf::RenderWindow window;
	sf::Clock clock;
	float dT = 0.f;
	std::vector<GameObject*> go;
	std::vector<Bullet*> bullet;
	std::vector<Brick*> brick;
	Canon* canon;
	bool win = false;
	const char* path;
	sf::SoundBuffer damageSoundBuffer;
	sf::SoundBuffer deleteSoundBuffer;
	sf::SoundBuffer winSoundBuffer;
	sf::Sound sDamage;
	sf::Sound sDelete;
	sf::Sound sWin;

	
public:
	App(const WindowData& data);
	~App();

	void HandleEvent();
	void Render();
	void Update();

	bool IsRunning() { return window.isOpen(); }
};