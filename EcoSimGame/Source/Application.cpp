#include "Application.h"
#include <stdio.h>
#include "SDL_opengl.h"

Application::Application(PointerBag* pointerBag)
{
	pointerBag->application = this;
	this->pointerBag = pointerBag;
}

bool Application::Create()
{
	window = SDL_CreateWindow("EcoSim", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0); // See SDL_WindowFlags for more info.
	if (!window) {
		printf("ERROR: Could not create window: %s\n", SDL_GetError());
		pointerBag->isRunning = false;
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
	if (!renderer) {
		printf("ERROR: Could not create renderer: %s\n", SDL_GetError());
		pointerBag->isRunning = false;
		return false;
	}
	pointerBag->renderer = renderer; // a copy for quick lookup

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	return true;
}

void Application::Destroy()
{
	if(renderer)
		SDL_DestroyRenderer(renderer);

	if(window)
		SDL_DestroyWindow(window);
}

void Application::HandleEvent(SDL_Event& event)
{
	if (event.type == SDL_QUIT)
		pointerBag->isRunning = false;
}

void Application::RenderBegin()
{
	SDL_RenderClear(renderer);
}

void Application::RenderEnd()
{
	SDL_RenderPresent(renderer);
}
