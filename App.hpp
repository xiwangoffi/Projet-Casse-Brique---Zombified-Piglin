#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"

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
public:
	App(const WindowData& data);
	~App();
	void HandleEvent();
};

