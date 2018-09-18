#include "Font.h"

bool Font::LoadFont(const std::string & path, int size)
{
	// Open the font
	ttf_font = TTF_OpenFont(path.c_str(), size);
	if (ttf_font == NULL)
	{
		printf("ERROR: Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
		return false; // Failed!
	}

	return true; // Success!
}

void Font::FreeFont()
{
	if (ttf_font)
		TTF_CloseFont(ttf_font);
}
