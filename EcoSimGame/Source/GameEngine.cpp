#include "GameEngine.h"
#include "Subsystems.h"

void GameEngine::Run()
{
	pointerBag.isRunning = true;

	Subsystems::Initialize();

	application = new Application(&pointerBag);
	application->Create();

	//appFSM = new AppFSM(&pointerBag);
	//screen = RootNode(pointerBag.renderer, 0, 0);
	states = new StateNode(&pointerBag);

	// Setup the game

	StartUp();
	states->SetState(0);
	states->StateNow->StartUp();

	while (pointerBag.isRunning)
	{
		//appFSM->UpdateFSM();
		//states.UpdateState();
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			application->HandleEvent(event);
			//HandleEvent(event);
			states->StateNow->HandleEvent(event);
			// Piping the events through here
			//appFSM->OnEvent(event);
		}

		// Update the game
		//appFSM->OnUpdate();
		states->StateNow->Update();
		// Render the game
		application->RenderBegin();
		//screen.render();
		states->StateNow->render();
		//appFSM->OnRender();
		//appFSM->OnRenderUI();
		application->RenderEnd();
	}

	//delete appFSM;
	//screen.Destroy();//fix el
	states->Destroy();//todo test el
	application->Destroy();
	delete application;
	Subsystems::Shutdown();
}
