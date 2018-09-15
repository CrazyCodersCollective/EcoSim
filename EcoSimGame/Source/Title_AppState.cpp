#include "Title_AppState.h"
#include <stdio.h>
#include "AppFSM.h"
#include "PointerBag.h"
#include "SDL_ImageLoader.h"

void Title_AppState::OnEntry()
{
	printf("Title_AppState::OnEntry\n");

	renderer = pointerBag->GetRenderer();

	std::string texturePath = "Resource/Textures/testObject.png";
	testObject = SDL_ImageLoader_LoadTexture(renderer, (char*)texturePath.c_str());
	if (!testObject) {
		pointerBag->isRunning = false;
		return; // Failed!
	}

	testFont = new Font();
	testFont->LoadFont("Resource/Fonts/monogram.ttf", 28);

	testText = new Text(pointerBag, "Title", testFont);
	testText->Create(200, 300, SDL_Color{ 255,0,0,255 });
}

void Title_AppState::OnExit()
{
	printf("Title_AppState::OnExit\n");

	if (testObject)
		SDL_DestroyTexture(testObject);

	if (testText)
		testText->Destroy();

	if (testFont)
		testFont->FreeFont();

}

void Title_AppState::OnEvent(SDL_Event& event)
{
	printf("Title_AppState::OnEvent\n");

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
	}

}

void Title_AppState::OnUpdate()
{
	printf("Title_AppState::OnUpdate\n");
}

void Title_AppState::OnRender()
{
	printf("Title_AppState::OnRender\n");

	// Should we bother with checking? OK wasting CPU cycles?
	if (testObject)
		SDL_RenderCopy(renderer, testObject, NULL, NULL);

	// Let us draw some text
	testText->Render();
}

void Title_AppState::OnRenderUI()
{
	printf("Title_AppState::OnRenderUI\n");
}
