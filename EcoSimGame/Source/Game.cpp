#include "Game.h"
#include <string>
#include "PointerBag.h"
#include "SDL_ImageLoader.h"
#include "sprite.h"
#include <stdlib.h> // rand()

void Game::StartUp()
{
	std::string texturePath = "Resource/Textures/testObject.png";
	//testObject = SDL_ImageLoader_LoadTexture(renderer, (char*)texturePath.c_str());
	//if (!testObject) {
		//pointerBag.isRunning = false;
		//return; // Failed!
	//}
	TestSprite = new Sprite(&pointerBag, 100, 100, texturePath);
	TestSprite->Texture((char*)texturePath.c_str());
}

void Game::Shutdown()
{
	if(testObject)
		SDL_DestroyTexture(testObject);

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
	
}
