#pragma once
#include <SDL.h>
#include "PointerBag.h"

class Application
{
public:
	Application(PointerBag* pointerBag);
	virtual ~Application() {}

	bool Create();
	void Destroy();

	void HandleEvent(SDL_Event& event);

	void RenderBegin();
	void RenderEnd();

	SDL_Window* GetWindow() { return window; }
	SDL_Renderer* GetRenderer() { return renderer; }

private:
	PointerBag* pointerBag;

	SDL_Window* window;
	SDL_Renderer* renderer;
};
