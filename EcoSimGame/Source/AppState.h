#pragma once
#include <string>
#include <SDL.h>
//#include <AppFSM.h>

class AppState
{
public:
	AppState() {}
	virtual ~AppState() {}

	virtual void OnEntry() = 0;
	virtual void OnExit() = 0;
	virtual void OnEvent(SDL_Event& event) = 0;
	virtual void OnUpdate() = 0;
	virtual void OnRender() = 0;
	virtual void OnRenderUI() = 0;

	std::string GetStateName() { return stateName; }
	
	//AppFSM* appFSM;

protected:
	std::string stateName;	
};
