#include "UITexture.h"
#include "SDL_ImageLoader.h"
#include <stdio.h>

void UITexture::LoadFile(const std::string& filePath)
{
	FreeTexture();

	texture = SDL_ImageLoader_LoadTexture(renderer, (char*)filePath.c_str());
	if (!texture)
	{
		// TODO(kim): Replace with proper error handler
		printf("ERROR: UITexture::LoadFile(%s) failed!\n", filePath.c_str());
		exit(1); // Exit hard!
	}
}

void UITexture::FreeTexture()
{
	if (texture)
		SDL_DestroyTexture(texture);
}
