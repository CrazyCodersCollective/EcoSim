#include "Text.h"
#include <SDL_image.h>

Text::Text(PointerBag* pointerBag, std::string text, Font* font) : pointerBag(pointerBag), textString(text), font(font)
{
	this->renderer = pointerBag->GetRenderer();
}

void Text::Create(float x, float y, SDL_Color color)
{
	textColor = color;
	positionX = x;
	positionY = y;

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
	{
		SDL_RenderCopy(renderer, texture, NULL, &dest);
	}
}

bool Text::UpdateTexture()
{
	if (texture)
		SDL_DestroyTexture(texture);

	// Render text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(font->GetFont(), textString.c_str(), textColor);
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
			textureWidth = textSurface->w;
			textureHeight = textSurface->h;

			// Update
			dest.x = (int)positionX;
			dest.y = (int)positionY;
			dest.w = textureWidth;
			dest.h = textureHeight;
		}

		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	}

	return true; // Success!
}