#pragma once
#include <string>
#include <vector>
#include "AppState.h"
#include <SDL.h>
#include "PointerBag.h"
#include "Font.h"
#include "Text.h"
#include "TitleMenu.h"

/*
	TODOs:
	1. Add button events
	2.0 Add static background (stage 1)
	2.1 Add parallax's background (stage 2)
	2.2 Add running animal (stage 3).  Too much? Requires timing.
*/

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
	Font* testFont;
	Text* testText;

	/* Title menu stuff */
	TitleMenu* titleMenu;
	UITexture* uiTextureButtons;
	UITexture* uiTextureBackground;
};
