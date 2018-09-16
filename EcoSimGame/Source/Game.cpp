#include "Game.h"
#include <string>
#include "PointerBag.h"
#include "SDL_ImageLoader.h"
#include "sprite.h"
#include <stdlib.h> // rand()

void Game::StartUp()
{
	std::string texturePath = "Resource/Textures/testObject.png";
	TestSprite = new Sprite(&this->screen, 100, 100, texturePath);//we dont need add it to the screeen with addchild becaue the firt paramiter will do that for us 
	//AddChild(TestSprite);
	//TestSprite->Texture(texturePath);

	//TestSprite2 = new Sprite(TestSprite, 10, 10, texturePath);//becaues the master is the other node it will folow it around
	//AddChild(TestSprite2);
	//TestSprite->Texture(texturePath);
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
			switch (event.key.keysym.sym)
		case (SDLK_ESCAPE):
				pointerBag.isRunning = false;
		case (SDLK_w):
			TestSprite->AddPos(0.0, -5.0);
		case (SDLK_a):
			TestSprite->AddPos(-5.0, 0.0);
		case (SDLK_s):
			TestSprite->AddPos(0.0, 5.0);
		case (SDLK_d):
			TestSprite->AddPos(5.0, 0.0);
		} break;
		//case (SDL_KEYUP):
	}
}

void Game::Update()
{
	//TestSprite->render();
}

void Game::Render()
{
	//TestSprite->render();
}
