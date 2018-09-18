#pragma once
#include <string>
#include <SDL.h>

class UITexture
{
public:
	UITexture(SDL_Renderer* renderer, const std::string& filePath)
    { this->renderer = renderer; LoadFile(filePath); }

	virtual ~UITexture() { FreeTexture(); }

	SDL_Texture* GetTexture() { return texture; }
	SDL_Rect GetRect() { return rect; }

private:
	SDL_Renderer* renderer;

	SDL_Texture* texture = nullptr;
	SDL_Rect rect;

	void LoadFile(const std::string& filePath);
	void FreeTexture();
};
