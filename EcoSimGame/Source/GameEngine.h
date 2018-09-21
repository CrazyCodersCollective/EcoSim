#pragma once
#include <SDL.h>
#include "PointerBag.h"
#include "Application.h"
#include "AppFSM.h"
#include "RootNode.h"
#include "StateNode.h"
class GameEngine
{
public:
	GameEngine() {}
	virtual ~GameEngine() {}
	void Run();
	//RootNode screen;
	StateNode* states = nullptr;

protected:
	virtual void StartUp() = 0;
	virtual void Shutdown() = 0;
	PointerBag pointerBag; // origin
	

private:
	Application* application;

};
