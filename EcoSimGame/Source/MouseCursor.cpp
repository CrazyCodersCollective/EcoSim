#include "MouseCursor.h"
#include <string>
#include <SDL_image.h>
#include <stdio.h>

bool MouseCursor::Create(const std::string & filePath)
{
	// Load image at specified path
	//std::string file_path = "Resource/Textures/MouseCursorPointer.png";
	SDL_Surface* surface = IMG_Load(filePath.c_str());
	if (surface == NULL)
	{
		printf("ERROR: Unable to load image %s! SDL_image Error: %s\n", filePath.c_str(), IMG_GetError());
		// TODO(kim): implement error logging
		return false;
	}
	
	cursor = SDL_CreateColorCursor(surface, 0, 0);
	SDL_SetCursor(cursor);

	// Get rid of old loaded surface
	SDL_FreeSurface(surface);

	return true;
}

void MouseCursor::Destroy()
{
	SDL_FreeCursor(cursor);
}
