#include "GameEngine.h"
#include "Subsystems.h"

void GameEngine::Run()
{
	pointerBag.isRunning = true;

	Subsystems::Initialize();

	application = new Application(&pointerBag);
	application->Create();

	mouseCursor = new MouseCursor();
	mouseCursor->Create("Resource/Textures/MouseCursorPointer.png");

	appFSM = new AppFSM(&pointerBag);
	
	// Setup the game
	Setup();

	while (pointerBag.isRunning)
	{
		appFSM->UpdateFSM();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			application->HandleEvent(event);

			// Piping the events through here
			appFSM->OnEvent(event);
		}

		// Update the game
		appFSM->OnUpdate();

		// Render the game
		application->RenderBegin();
		appFSM->OnRender();
		appFSM->OnRenderUI();
		application->RenderEnd();
	}

	delete appFSM;

	mouseCursor->Destroy();
	delete mouseCursor;

	application->Destroy();
	delete application;

	Subsystems::Shutdown();
}
