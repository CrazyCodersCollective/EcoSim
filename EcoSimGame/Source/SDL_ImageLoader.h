//
// SDL image loader for wrapping SDL_image
// 

#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

// Load PNG image from file into a SDL texture
static SDL_Texture* SDL_ImageLoader_LoadTexture(SDL_Renderer *renderer, char *file_path)
{
	// The final texture
 	SDL_Texture* newTexture = NULL;

	// Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(file_path);
	if (loadedSurface == NULL)
	{
		printf("ERROR: Unable to load image %s! SDL_image Error: %s\n", file_path, IMG_GetError());
		// TODO(kim): implement error logging
	}
	else
	{
		// Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("ERROR: Unable to create texture from %s! SDL Error: %s\n", file_path, SDL_GetError());
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
		printf("ERROR: Unable to create texture from memory! SDL Error: %s\n", SDL_GetError());
		// TODO(kim): implement error logging
	}

	return newTexture;
}
