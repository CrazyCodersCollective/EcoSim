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

	void SetPosition(float x, float y);
	void SetString(std::string newString);
	void SetColor(SDL_Color newColor);
	void SetColor(int r, int g, int b, int a);
	void SetColorNormalized(float r, float g, float b, float a);
	
	// With caching off we have to explicitly update the texture.
	void SetCachingMode(bool active) { activeCaching = active; }
	void UpdateTextureExplicit(); // Regardless to what texture caching is set to.

	// Text quality mode
	void SetQualityMode(bool best) { bestQuality = best; } // true: best quality and slow (default), false: quick and dirty

private:
	PointerBag* pointerBag;
	SDL_Renderer* renderer; // quick lookup

	Font* font;
	bool activeCaching;
	
	/* Text string */
	SDL_Color textColor;
	std::string textString;
	bool bestQuality;
	float posX;
	float posY;

	/* Texture */
	SDL_Texture* texture;
	SDL_Rect dest;
	bool UpdateTexture();

	/* Util stuff*/
	Uint8 ClampUint8(int value);
	float ClampFloat(float value, float min, float max);
};
