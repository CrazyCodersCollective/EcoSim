#pragma once
#include <string>
#include "AppState.h"
#include "PointerBag.h"

class AppInit_AppState : public AppState
{
public:
	AppInit_AppState(PointerBag* pointerBag) : pointerBag(pointerBag) { stateName = "AppInit";  }
	virtual ~AppInit_AppState() {}

	void OnEntry();
	void OnExit();
	void OnEvent(SDL_Event& event);
	void OnUpdate();
	void OnRender();
	void OnRenderUI();

private:
	/* Common stuff */
	PointerBag* pointerBag;
	SDL_Renderer* renderer;
};
