#include "Load_AppState.h"
#include <stdio.h>
#include "SDL_ImageLoader.h"
#include "AppFSM.h"

void Load_AppState::OnEntry()
{
	//printf("Load_AppState::OnEntry\n");

	renderer = pointerBag->GetRenderer();

	testFont = new Font();
	testFont->LoadFont("Resource/Fonts/monogram.ttf", 28);
	
	testText = new Text(pointerBag, "Load! Press Q to return", testFont);
	testText->Create(200, 300, SDL_Color{ 255,0,0,255 });
}

void Load_AppState::OnExit()
{
	//printf("Load_AppState::OnExit\n");

	if (testText)
		testText->Destroy();
	
	if (testFont)
		testFont->FreeFont();
}

void Load_AppState::OnEvent(SDL_Event& event)
{
	//printf("Load_AppState::OnEvent\n");

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

void Load_AppState::OnUpdate()
{
	//printf("Load_AppState::OnUpdate\n");
}

void Load_AppState::OnRender()
{
	//printf("Load_AppState::OnRender\n");

	if (!renderer)
		return;

	testText->Render();
}

void Load_AppState::OnRenderUI()
{
	//printf("Load_AppState::OnRenderUI\n");

	if (!renderer)
		return;
}
