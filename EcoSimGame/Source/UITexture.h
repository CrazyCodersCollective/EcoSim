#pragma once
#include <string>
#include <SDL.h>

class UITexture
{
public:
	UITexture(SDL_Renderer* renderer, std::string filePath) { this->renderer = renderer; LoadFile(filePath); }
	virtual ~UITexture() { FreeTexture(); }

	SDL_Texture* GetTexture() { return texture; }
	SDL_Rect GetRect() { return rect; }

private:
	SDL_Renderer* renderer;

	SDL_Texture* texture;
	SDL_Rect rect;

	void LoadFile(std::string filePath);
	void FreeTexture();
};
