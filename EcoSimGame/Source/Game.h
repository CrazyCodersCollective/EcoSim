#pragma once
#include <SDL.h>
#include "GameEngine.h"

// AppStates
#include "Title_AppState.h"
#include "Game_AppState.h"

class Game : public GameEngine
{
public:
	Game() {}
	virtual ~Game() {}
	
private:
	void Setup()
	{
		appFSM->AddState(new Title_AppState(appFSM->GetPointerBag()));
		appFSM->AddState(new Game_AppState(appFSM->GetPointerBag()));

		appFSM->ChangeState("Title");
	}
};
