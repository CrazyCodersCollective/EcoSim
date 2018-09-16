#pragma once
#include <string>
#include "AppState.h"
#include <SDL.h>
#include "PointerBag.h"
#include "Font.h"
#include "Text.h"

class GameSetup_AppState : public AppState
{
public:
	GameSetup_AppState(PointerBag* pointerBag) : pointerBag(pointerBag) { stateName = "GameSetup"; }
	virtual ~GameSetup_AppState() {}

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
	Text* testText2;
};
