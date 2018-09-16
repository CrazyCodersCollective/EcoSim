#include "Game_AppState.h"
#include <stdio.h>
#include "SDL_ImageLoader.h"
#include "AppFSM.h"

void Game_AppState::OnEntry()
{
	//printf("Game_AppState::OnEntry\n");

	renderer = pointerBag->GetRenderer();

	testFont = new Font();
	testFont->LoadFont("Resource/Fonts/monogram.ttf", 28);
	
	testText = new Text(renderer, "Game! Press Q to return", testFont);
	testText->Create(200, 300, SDL_Color{ 255,0,0,255 });
}

void Game_AppState::OnExit()
{
	//printf("Game_AppState::OnExit\n");

	if (testText)
		testText->Destroy();
	delete testText;
	
	if (testFont)
		testFont->FreeFont();
	delete testFont;
}

void Game_AppState::OnEvent(SDL_Event& event)
{
	//printf("Game_AppState::OnEvent\n");

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
			default:
				break;
			}
		} break;
	}

}

void Game_AppState::OnUpdate()
{
	//printf("Game_AppState::OnUpdate\n");
}

void Game_AppState::OnRender()
{
	//printf("Game_AppState::OnRender\n");

	if (!renderer)
		return;

	testText->Render();
}

void Game_AppState::OnRenderUI()
{
	//printf("Game_AppState::OnRenderUI\n");

	if (!renderer)
		return;
}
