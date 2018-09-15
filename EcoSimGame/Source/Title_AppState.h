#pragma once
#include <string>
#include <vector>
#include "AppState.h"
#include <SDL.h>
#include "PointerBag.h"
#include "Font.h"
#include "Text.h"

class Title_AppState : public AppState
{
public:
	Title_AppState(PointerBag* pointerBag) : pointerBag(pointerBag) { stateName = "Title"; }
	virtual ~Title_AppState() {}

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
	SDL_Texture* testObject;
	Font* testFont;
	Text* testText;
};
