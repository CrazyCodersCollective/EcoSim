#pragma once
#include <SDL.h>

class Application;

struct PointerBag
{
	Application* application = nullptr;
	bool isRunning;

	SDL_Renderer* renderer = nullptr; // just a quick lookup, not the source
	SDL_Renderer* GetRenderer() { return renderer; }// this brakes in places, investigate 
};
