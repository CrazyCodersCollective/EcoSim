#include "GameSetup_AppState.h"
#include <stdio.h>
#include "SDL_ImageLoader.h"
#include "AppFSM.h"

void GameSetup_AppState::OnEntry()
{
	//printf("GameSetup_AppState::OnEntry\n");

	renderer = pointerBag->GetRenderer();

	testFont = new Font();
	testFont->LoadFont("Resource/Fonts/monogram.ttf", 28);
	
	testText = new Text(pointerBag, "GameSetup! Press Q to return.", testFont);
	testText->Create(200, 300, SDL_Color{ 255,0,0,255 });

	testText2 = new Text(pointerBag, "Press ENTER to start game.", testFont);
	testText2->Create(200, 350, SDL_Color{ 255,0,0,255 });
}

void GameSetup_AppState::OnExit()
{
	//printf("GameSetup_AppState::OnExit\n");

	if (testText)
		testText->Destroy();

	if (testText2)
		testText2->Destroy();

	if (testFont)
		testFont->FreeFont();
}

void GameSetup_AppState::OnEvent(SDL_Event& event)
{
	//printf("GameSetup_AppState::OnEvent\n");

	switch (event.type)
	{
		case SDL_KEYDOWN:
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
			{
				pointerBag->isRunning = false;
			} break;
			case SDLK_q:
			{
				pointerBag->appFSM->ChangeState("Title");
			} break;
			case SDLK_RETURN:
			{
				pointerBag->appFSM->ChangeState("Game");
			} break;
			default:
				break;
			}
		} break;
	}

}

void GameSetup_AppState::OnUpdate()
{
	//printf("GameSetup_AppState::OnUpdate\n");
}

void GameSetup_AppState::OnRender()
{
	//printf("GameSetup_AppState::OnRender\n");

	if (!renderer)
		return;

	testText->Render();
	testText2->Render();
}

void GameSetup_AppState::OnRenderUI()
{
	//printf("GameSetup_AppState::OnRenderUI\n");

	if (!renderer)
		return;
}
