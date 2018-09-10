#pragma once
#include <SDL.h>
#include "PointerBag.h"
#include "Application.h"

class GameEngine
{
public:
	GameEngine() {}
	virtual ~GameEngine() {}

	void Run();

protected:
	virtual void StartUp() = 0;
	virtual void Shutdown() = 0;
	virtual void HandleEvent(SDL_Event& event) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

	PointerBag pointerBag; // origin
	SDL_Renderer* renderer; // for quick lookup (not the source)

private:
	Application* application;
};
