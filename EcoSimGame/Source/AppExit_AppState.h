#pragma once
#include <string>
#include "AppState.h"
#include "PointerBag.h"

class AppExit_AppState : public AppState
{
public:
	AppExit_AppState(PointerBag* pointerBag) : pointerBag(pointerBag) { stateName = "AppExit"; }
	virtual ~AppExit_AppState() {}

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
