#include "Options_AppState.h"
#include <stdio.h>
#include "SDL_ImageLoader.h"
#include "AppFSM.h"

void Options_AppState::OnEntry()
{
	//printf("Options_AppState::OnEntry\n");

	renderer = pointerBag->GetRenderer();

	testFont = new Font();
	testFont->LoadFont("Resource/Fonts/monogram.ttf", 28);
	
	testText = new Text(renderer, "Options! Press Q to return", testFont);
	testText->Create(200, 300, SDL_Color{ 255,0,0,255 });
}

void Options_AppState::OnExit()
{
	//printf("Options_AppState::OnExit\n");

	if (testText)
		testText->Destroy();
	delete testText;
	
	if (testFont)
		testFont->FreeFont();
	delete testFont;
}

void Options_AppState::OnEvent(SDL_Event& event)
{
	//printf("Options_AppState::OnEvent\n");

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

void Options_AppState::OnUpdate()
{
	//printf("Options_AppState::OnUpdate\n");
}

void Options_AppState::OnRender()
{
	//printf("Options_AppState::OnRender\n");

	if (!renderer)
		return;

	testText->Render();
}

void Options_AppState::OnRenderUI()
{
	//printf("Options_AppState::OnRenderUI\n");

	if (!renderer)
		return;
}
