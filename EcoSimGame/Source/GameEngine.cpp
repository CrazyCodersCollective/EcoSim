#include "GameEngine.h"
#include "Subsystems.h"

void GameEngine::Run()
{
	pointerBag.isRunning = true;

	Subsystems::Initialize();

	application = new Application(&pointerBag);
	application->Create();

	//appFSM = new AppFSM(&pointerBag);
	screen = RootNode(pointerBag.renderer, 0, 0);
	states = MenuNode(&pointerBag);

	// Setup the game
	StartUp();

	while (pointerBag.isRunning)
	{
		//appFSM->UpdateFSM();
		states.UpdateState();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			application->HandleEvent(event);
			HandleEvent(event);
			states.HandleEvent(event);
			// Piping the events through here
			//appFSM->OnEvent(event);
		}

		// Update the game
		//appFSM->OnUpdate();
		states.Update();
		// Render the game
		application->RenderBegin();
		//screen.render();
		states.render();
		//appFSM->OnRender();
		//appFSM->OnRenderUI();
		application->RenderEnd();
	}

	delete appFSM;
	screen.Destroy();//fix el
	application->Destroy();
	delete application;
	Subsystems::Shutdown();
}
