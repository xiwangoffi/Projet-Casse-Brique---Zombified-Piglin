#include "App.hpp"
    
using namespace sf;
using namespace std;

int main()
{
    WindowData data = {
		"Brick my ass",
        1920, 1080
	};
    App app(data);
    app.Render();
    
    while (app.IsRunning())
    {
        app.Update();
        app.HandleEvent();
    }

    return 0;
}