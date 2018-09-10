#pragma once
#include <string>
#include <SDL.h>
#include "Font.h"
#include "PointerBag.h"

class Text
{
public:
	Text(PointerBag* pointerBag, std::string text, Font* font);
	virtual ~Text() {}

	void Create(float x, float y, SDL_Color color);
	void Destroy();

	void Render();

	// TODOs(kim):
	// void SetPosition(..)
	// void SetString(..)
	// void SetColor(..)
	// void SetQuality(..)

private:
	PointerBag* pointerBag;
	SDL_Renderer* renderer; // quick lookup

	Font* font;
	SDL_Color textColor;
	SDL_Texture* texture;
	int textureWidth;
	int textureHeight;
	std::string textString;
	float positionX;
	float positionY;

	bool UpdateTexture();

	//
	SDL_Rect dest;
};
