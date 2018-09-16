#include "GameEngine.h"
#include "Subsystems.h"
#include "RootNode.h"

void GameEngine::Run()
{
	pointerBag.isRunning = true;

	Subsystems::Initialize();

	application = new Application(&pointerBag);
	application->Create();
	renderer = pointerBag.GetRenderer();
	if (!renderer)printf("null pointer in gameengin init");
	//screen = RootNode(renderer, 0 ,0);//defult screen
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
		for (int i = 0; i < screen.children.size(); i++) {
			screen.children[i]->render();
		}
		Render();
		application->RenderEnd();
	}

	// Shutdown the game
	for (int i = 0; i < screen.children.size(); i++) {
		screen.children[i]->Destroy();
		Shutdown();

		application->Destroy();
		delete application;

		Subsystems::Shutdown();
	}
}

void GameEngine::AddChild(Node* item){
	screen;//add sorting by darw order
	//add 

};