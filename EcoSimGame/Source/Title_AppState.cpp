#include "Title_AppState.h"
#include <stdio.h>
#include "AppFSM.h"
#include "PointerBag.h"
//#include "SDL_ImageLoader.h"

void Title_AppState::OnEntry()
{
	//printf("Title_AppState::OnEntry\n");

	renderer = pointerBag->GetRenderer();

	uiTextureButtons = new UITexture(renderer, "Resource/Textures/titleMenuButtons.png");
	if (!uiTextureButtons)
	{
		// TODO(kim): Implement error handling
	}

	uiTextureBackground = new UITexture(renderer, "Resource/Textures/TitleScreen.png");
	// TODO(kim): error check
	
	titleMenu = new TitleMenu(pointerBag->GetRenderer());
	titleMenu->AddButton(uiTextureButtons, SDL_Rect{ 0,0,255,63 }, SDL_Rect{ 200,200,255,63 });
	titleMenu->AddButton(uiTextureButtons, SDL_Rect{ 0,64,255,63 }, SDL_Rect{ 200,270,255,63 });
	titleMenu->AddButton(uiTextureButtons, SDL_Rect{ 0,128,255,63 }, SDL_Rect{ 200,340,255,63 });
	titleMenu->AddButton(uiTextureButtons, SDL_Rect{ 0,192,255,63 }, SDL_Rect{ 200,410,255,63 });

	testFont = new Font();
	testFont->LoadFont("Resource/Fonts/monogram.ttf", 28);

	testText = new Text(renderer, "Title", testFont);
	testText->Create(200, 300, SDL_Color{ 255,0,0,255 });
}

void Title_AppState::OnExit()
{
	//printf("Title_AppState::OnExit\n");

	delete uiTextureBackground;

	// Free UI
	delete titleMenu;
	delete uiTextureButtons;

	if (testText)
		testText->Destroy();
	delete testText;

	if (testFont)
		testFont->FreeFont();
	delete testFont;
}

void Title_AppState::OnEvent(SDL_Event& event)
{
	//printf("Title_AppState::OnEvent\n");

	switch (event.type)
	{
		case SDL_KEYDOWN:
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				pointerBag->isRunning = false;
		} break;
		case SDL_KEYUP:
		{
			if (event.key.keysym.sym == SDLK_SPACE)
			{				
				pointerBag->appFSM->ChangeState("Game");
			}
		} break;
		
		case SDL_MOUSEBUTTONDOWN:
		{
			switch (titleMenu->EventButtonPressed(event))
			{
				case 0: // New game
				{
					pointerBag->appFSM->ChangeState("GameSetup");
				} break;
				case 1: // Load game
				{
					pointerBag->appFSM->ChangeState("Load");
				} break;
				case 2: // Options
				{
					pointerBag->appFSM->ChangeState("Options");
				} break;
				case 3: // Exit
				{
					pointerBag->isRunning = false; // Quit the program
				} break;
			}
		} break;
		//case SDL_MOUSEBUTTONUP: {} break;
		case SDL_MOUSEMOTION:
		{
			titleMenu->ClearHovers();

			int hoverId = titleMenu->EventButtonHovered(event);
			if (hoverId != -1)
			{
				titleMenu->GetButton(hoverId)->SetHover(true);
			}
		} break;
	}

}

void Title_AppState::OnUpdate()
{
	//printf("Title_AppState::OnUpdate\n");
}

void Title_AppState::OnRender()
{
	//printf("Title_AppState::OnRender\n");

	SDL_RenderCopy(renderer, uiTextureBackground->GetTexture(), NULL, NULL);

	// Let us draw some text
	testText->Render();
}

void Title_AppState::OnRenderUI()
{
	//printf("Title_AppState::OnRenderUI\n");

	titleMenu->Render();
}
