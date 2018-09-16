#pragma once
#include <SDL.h>
#include "PointerBag.h"
#include "Application.h"
#include "AppFSM.h"
#include "MouseCursor.h"


class GameEngine
{
public:
	GameEngine() {}
	virtual ~GameEngine() {}

	void Run();

protected:
	virtual void Setup() = 0;

	AppFSM* appFSM;
	PointerBag pointerBag; // origin

private:
	Application* application;

	MouseCursor* mouseCursor;
};
