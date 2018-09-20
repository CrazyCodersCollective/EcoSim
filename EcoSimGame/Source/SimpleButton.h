#pragma once
#include <string>
#include <SDL.h>
#include "Text.h"
#include "Font.h"

class SimpleButton
{
public:
	SimpleButton(SDL_Renderer* renderer, Font* font, SDL_Rect rect, const std::string& text, SDL_Color foreColor, SDL_Color backColor);
	virtual ~SimpleButton();

	bool EventMouseHover(SDL_Event& event);
	bool EventMouseDown(SDL_Event& event);
	bool EventMouseUp(SDL_Event& event);
	bool EventMouseClick(SDL_Event& event);

	void Render();


private:
	SDL_Renderer* renderer;

	// Properties
	SDL_Rect rect;
	std::string textString;
	SDL_Color foreColor;
	SDL_Color backColor;

	Text* text;
	Font* font;

	bool isDown;
	void ResetClickEvent() { isDown = false; }

	bool isPointInsideBox(int mx, int my, SDL_Rect box);
	
};
