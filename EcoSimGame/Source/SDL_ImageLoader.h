//
// SDL image loader for wrapping SDL_image
// 

#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

// Load PNG image from file into a SDL texture
static SDL_Texture* SDL_ImageLoader_LoadTexture(SDL_Renderer *renderer, const std::string & file_path)
{
	// The final texture
	SDL_Texture* newTexture = NULL;

	// Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(file_path.c_str());
	if (loadedSurface == NULL)
	{
		// On unixoid systems errors should be printed to std::cerr.
//		std::cerr << "ERROR: Unable to load image " << file_path
			//	  << "! SDL_image Error: " << IMG_GetError() << '\n';
		// TODO(kim): implement error logging
	}
	else
	{
		// Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL)
		{
			// On unixoid sysems errors should be printed to the error stream.
			//std::cerr << "ERROR: Unable to create texture from " << file_path
				//	  << "! SDL Error: " <<  SDL_GetError() << '\n';
			// TODO(kim): implement error logging
		}

		// Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

// Load PNG image from memory into a SDL texture
static SDL_Texture* SDL_ImageLoader_LoadFromMemoryTexture(SDL_Renderer *renderer, void* memory_location, int memory_size)
{
	SDL_RWops *rwops = SDL_RWFromMem(memory_location, memory_size);
	SDL_Texture* newTexture = IMG_LoadTextureTyped_RW(renderer, rwops, 1, "PNG");
	if (newTexture == NULL)
	{
		// Errors to error stream, not to the default.
		std::cerr << "ERROR: Unable to create texture from memory! SDL Error: "
				  << SDL_GetError() << '\n';
		// TODO(kim): implement error logging
	}

	return newTexture;
}
