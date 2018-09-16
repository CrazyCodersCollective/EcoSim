#pragma once
#include <SDL.h>
#include "UITexture.h"

class MenuButton
{
public:
	MenuButton(SDL_Renderer* renderer, UITexture* uiTexture, SDL_Rect srcRect, SDL_Rect dstRect);
	virtual ~MenuButton();

	void Render();

	SDL_Rect GetRect() { return dstRect; }

	void SetHover(bool hover) { isHovered = hover; }
	//bool GetHover() { return isHovered; }

private:
	SDL_Renderer* renderer;

	UITexture* uiTexture;
	SDL_Rect srcRect;
	SDL_Rect dstRect;

	bool isHovered;
};
