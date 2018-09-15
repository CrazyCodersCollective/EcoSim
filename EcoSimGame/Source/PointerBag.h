#pragma once
#include <SDL.h>

class Application;
class AppFSM;

struct PointerBag
{
	// Application
	Application* application = nullptr;
	bool isRunning;

	// Application FSM
	AppFSM* appFSM = nullptr;

	// Renderer
	SDL_Renderer* renderer = nullptr; // just a quick lookup, not the source
	SDL_Renderer* GetRenderer() { return renderer; }
};
