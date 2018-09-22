#include "Game.h"
#include <string>
#include "PointerBag.h"
#include "SDL_ImageLoader.h"
//#include "sprite.h"
#include <stdlib.h> // rand()

#include "GameRootNode.h"
#include "GameSetupRootNode.h"
void Game::StartUp()
{
	test = new GameRootNode();
	states->AddChild(test);
	states->AddChild(new GameSetupRootNode());
	RootNode* rr = new RootNode();
	states->AddChild(rr);
	rr->Fromjson("Resource/States/title.json");

	
}

void Game::Shutdown()
{

}

