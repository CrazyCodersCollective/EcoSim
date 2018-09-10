#include "Image_Subsystem.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL_image.h>

void Image_Subsystem::Initialize()
{
	if (!IMG_Init(IMG_INIT_PNG)) // Returns: 0 on failure
	{
		printf("ERROR: Unable to initialize SDL_image: %s", IMG_GetError());
		exit(1); // Failed to init -> exit program
	}

}

void Image_Subsystem::Shutdown()
{
	IMG_Quit();
}
