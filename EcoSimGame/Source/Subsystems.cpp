#include "Subsystems.h"
#include <stdlib.h> // atexit()
#include "SDL_Subsystem.h"
#include "Image_Subsystem.h"
#include "Font_Subsystem.h"

void Subsystems::Initialize()
{
	// On exit call for shutdown of subsystems
	atexit(Subsystems::Shutdown);

	SDL_Subsystem::Initialize();
	Image_Subsystem::Initialize();
	Font_Subsystem::Initialize();
}

void Subsystems::Shutdown()
{
	Font_Subsystem::Shutdown();
	Image_Subsystem::Shutdown();
	SDL_Subsystem::Shutdown();
}
