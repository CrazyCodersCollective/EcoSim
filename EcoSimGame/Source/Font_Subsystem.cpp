#include "Font_Subsystem.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL_ttf.h>

void Font_Subsystem::Initialize()
{
	if (TTF_Init()) // Returns: 0 on success, -1 on any error
	{
		printf("ERROR: Unable to initialize SDL_ttf: %s", TTF_GetError());
		exit(1); // Failed to init -> exit program
	}
}

void Font_Subsystem::Shutdown()
{
	TTF_Quit();
}
