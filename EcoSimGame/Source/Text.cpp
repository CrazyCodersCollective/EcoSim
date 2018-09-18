#include "Text.h"
#include <SDL_image.h>

Text::Text(SDL_Renderer* renderer, const std::string& text, Font* font) : renderer(renderer), textString(text), font(font)
{
	//this->renderer = pointerBag->GetRenderer();
	this->activeCaching = false;
	this->bestQuality = true; // default
}

void Text::Create(float x, float y, SDL_Color color)
{
	textColor = color;
	SetPosition(x, y);
	UpdateTexture();
}

void Text::Destroy()
{
	if (texture)
		SDL_DestroyTexture(texture);
}

void Text::Render()
{
	if (renderer && texture)
		SDL_RenderCopy(renderer, texture, NULL, &dest);
}

void Text::SetPosition(float x, float y)
{
	posX = x;
	posY = y;
	dest.x = (int)x;
	dest.y = (int)y;
}

void Text::SetString(std::string newString)
{
	textString = newString;
	UpdateTexture();
}

void Text::SetColor(SDL_Color newColor)
{
	textColor = newColor;
	UpdateTexture();
}

void Text::SetColor(int r, int g, int b, int a)
{
	SetColor(SDL_Color { ClampUint8(r), ClampUint8(g), ClampUint8(b), ClampUint8(a) } );
}

void Text::SetColorNormalized(float r, float g, float b, float a)
{
	r = ClampFloat(r, 0.0f, 1.0f);
	g = ClampFloat(g, 0.0f, 1.0f);
	b = ClampFloat(b, 0.0f, 1.0f);
	a = ClampFloat(a, 0.0f, 1.0f);
	SetColor(SDL_Color{ (Uint8)r, (Uint8)g, (Uint8)b , (Uint8)a });
}

bool Text::UpdateTexture()
{
	if (texture)
		SDL_DestroyTexture(texture);

	if (activeCaching)
		return true; // Success!

	// Render text surface
	SDL_Surface* textSurface;
	if (bestQuality)
		textSurface = TTF_RenderUTF8_Blended(font->GetFont(), textString.c_str(), textColor);
	else
		textSurface = TTF_RenderText_Solid(font->GetFont(), textString.c_str(), textColor);
	if (textSurface == NULL)
	{
		printf("ERROR: Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
		return false; // Failed!
	}
	else
	{
		// Create texture from surface pixels
		texture = SDL_CreateTextureFromSurface(renderer, textSurface);
		if (texture == NULL)
		{
			printf("ERROR: Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
			return false; // Failed!
		}
		else
		{
			// Get image dimensions
			dest.w = textSurface->w;
			dest.h = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	}

	return true; // Success!
}

Uint8 Text::ClampUint8(int value)
{
	if (value < 0) value = 0;
	if (value > 255) value = 255;
	return value;
}

float Text::ClampFloat(float value, float min, float max)
{
	if (value < min) value = min;
	if (value > max) value = max;
	return value;
}

void Text::UpdateTextureExplicit()
{
	bool tempActiveCache = activeCaching;
	activeCaching = false;
	UpdateTexture();
	activeCaching = tempActiveCache;
}
