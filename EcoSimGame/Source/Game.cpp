#include "Game.h"
#include <string>
#include "PointerBag.h"
#include "SDL_ImageLoader.h"
#include "sprite.h"
#include <stdlib.h> // rand()
#include "Title_AppState.h"
#include "Game_AppState.h"
#include "GameSetup_AppState.h"
#include "Load_AppState.h"
#include "Options_AppState.h"
void Game::StartUp()
{

	this->states.AddState(new Title_AppState(states.pointerBag));
	this->states.AddState(new Game_AppState(states.pointerBag));
	this->states.AddState(new GameSetup_AppState(states.pointerBag));
	this->states.AddState(new Load_AppState(states.pointerBag));
	this->states.AddState(new Options_AppState(states.pointerBag));

	states.ChangeState("Title");


	std::string texturePath = "Resource/Textures/testimage.png";
	//root =  new RootNode(this->pointerBag.GetRenderer());
	butt = new ButtonNode(&screen, SDL_Rect{ 100, 100, 100, 100 }, "hello");
	TestSprite = new Sprite(&screen, 100, 100, texturePath);//we dont need add it to the screeen with addchild becaue the firt paramiter will do that for us 
	
	butt->SetText("hello");
															//TestSprite->Texture(texturePath);
	//AddChild(TestSprite);
	//TestSprite->Texture(texturePath);

	TestSprite2 = new Sprite(TestSprite, 10, 10, texturePath);//becaues the master is the other node it will folow it around
	//AddChild(TestSprite2);
	//TestSprite->Texture(texturePath);
}

void Game::Shutdown()
{

}

void Game::HandleEvent(SDL_Event& event)
{
	switch (event.type)
	{
	case (SDL_KEYDOWN):
		
		switch (event.key.keysym.sym){
		case (SDLK_ESCAPE):
			pointerBag.isRunning = false;
			break;
		case (SDLK_w):
			TestSprite->AddPos(0.0, -5.0);
			break;
		case (SDLK_a):
			TestSprite->AddPos(-5.0, 0.0);
			break;
		case (SDLK_s):
			TestSprite->AddPos(0.0, 5.0);
			break;
		case (SDLK_d):
			TestSprite->AddPos(5.0, 0.0);
			break;
		case (SDLK_q):
			printf("float: %f", this->TestSprite->x);
			break;
		}
		//case (SDL_KEYUP):
	}
}

void Game::Update()
{
	//TestSprite->render();
}

void Game::Render()
{
	TestSprite->render();
}
