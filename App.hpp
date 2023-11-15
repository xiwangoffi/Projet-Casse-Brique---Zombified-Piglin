#pragma once
#include "GameObject.hpp"
#include <vector>

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
	
public:
	App(const WindowData& data);
	~App();
	void HandleEvent();
	void Render();
	void Update();

	bool IsRunning() { return window.isOpen(); }
};