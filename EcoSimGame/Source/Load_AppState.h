#pragma once
#include <string>
#include "AppState.h"
#include <SDL.h>
#include "PointerBag.h"
#include "Font.h"
#include "Text.h"

class Load_AppState : public AppState
{
public:
	Load_AppState(PointerBag* pointerBag) : pointerBag(pointerBag) { stateName = "Load"; }
	virtual ~Load_AppState() {}

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

	/* Game stuffs */
	Font* testFont;
	Text* testText;
};
