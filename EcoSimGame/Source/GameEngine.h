#pragma once
#include <SDL.h>
#include "PointerBag.h"
#include "Application.h"
#include "AppFSM.h"
#include "RootNode.h"
class GameEngine
{
public:
	GameEngine() {}
	virtual ~GameEngine() {}
	void Run();
	RootNode screen;

protected:
	virtual void StartUp() = 0;
	virtual void Shutdown() = 0;
	virtual void HandleEvent(SDL_Event& event) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	AppFSM* appFSM;
	PointerBag pointerBag; // origin

private:
	Application* application;
};
