#include "SDL_Subsystem.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

void SDL_Subsystem::Initialize()
{
	if (SDL_Init(SDL_INIT_EVERYTHING)) // Returns 0 on success or a negative error code on failure
	{
		printf("ERROR: Unable to initialize SDL: %s", SDL_GetError());
		exit(1); // Failed to init -> exit program
	}
}

void SDL_Subsystem::Shutdown()
{
	SDL_Quit();
}
