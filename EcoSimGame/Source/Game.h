#pragma once
#include <SDL.h>

class Game
{
public:
	Game() {}
	virtual ~Game() {}

	void init();
	void loadResources();
	void update();
	void events();
	void display();
	void quit();

	bool isRunning;

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Texture* testObject;
};
