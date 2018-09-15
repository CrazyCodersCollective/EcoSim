#include "GameEngine.h"
#include "Subsystems.h"

void GameEngine::Run()
{
	pointerBag.isRunning = true;

	Subsystems::Initialize();

	application = new Application(&pointerBag);
	application->Create();
	renderer = pointerBag.GetRenderer();

	// Startup the game
	StartUp();

	while (pointerBag.isRunning)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			application->HandleEvent(event);
			
			// Piping the events through here
			HandleEvent(event);
		}

		// Update the game
		Update();

		// Render the game
		application->RenderBegin();
		for (int i = 0; i < items.size(); i++) {
			items[i]->render();
		}
		Render();
		application->RenderEnd();
	}

	// Shutdown the game
	Shutdown();

	application->Destroy();
	delete application;

	Subsystems::Shutdown();
}

void GameEngine::AddChild(Node* item) {
	items.push_back(item);//add sorting by darw order
	//add 

}