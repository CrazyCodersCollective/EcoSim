#pragma once
#include <vector>
#include <SDL.h>
#include "MenuButton.h"
#include "UITexture.h"

class TitleMenu
{
public:
	TitleMenu(SDL_Renderer* renderer) : renderer(renderer) {}
	virtual ~TitleMenu() { vMenuButtons.clear(); }

	//int Event(SDL_Event& event);
	int EventButtonPressed(SDL_Event& event);
	int EventButtonHovered(SDL_Event& event);

	void Render();

	void AddButton(UITexture* uiTexture, SDL_Rect srcRect, SDL_Rect dstRect);
	MenuButton* GetButton(int index) { return vMenuButtons.at(index); }

	void ClearHovers();

private:
	SDL_Renderer* renderer;

	std::vector<MenuButton*> vMenuButtons;

	// TODO(kim): Make AABB utility facility. This class shouldn't contain this kinda stuff.
	bool isPointInsideBox(int mx, int my, SDL_Rect box);
};
