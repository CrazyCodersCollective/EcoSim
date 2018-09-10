#include "Game.h"
#include <string>
#include "PointerBag.h"
#include "SDL_ImageLoader.h"

void Game::StartUp()
{
	std::string texturePath = "Resource/Textures/testObject.png";
	testObject = SDL_ImageLoader_LoadTexture(renderer, (char*)texturePath.c_str());
	if (!testObject) {
		pointerBag.isRunning = false;
		return; // Failed!
	}

	testFont = new Font();
	testFont->LoadFont("Resource/Fonts/monogram.ttf", 28);

	testText = new Text(&pointerBag, "Hello world!", testFont);
	testText->Create(200, 300, SDL_Color{ 255,0,0,255 });
}

void Game::Shutdown()
{
	if(testObject)
		SDL_DestroyTexture(testObject);

	if (testText)
		testText->Destroy();

	if (testFont)
		testFont->FreeFont();
}

void Game::HandleEvent(SDL_Event& event)
{
	switch (event.type)
	{
		case (SDL_KEYDOWN):
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
				pointerBag.isRunning = false;
		} break;
	}
}

void Game::Update()
{
}

void Game::Render()
{
	// Should we bother with checking? OK wasting CPU cycles?
	if(testObject)
		SDL_RenderCopy(renderer, testObject, NULL, NULL);

	// Let us draw some text
	testText->Render();
}
