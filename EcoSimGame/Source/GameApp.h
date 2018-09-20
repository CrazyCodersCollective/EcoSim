#pragma once
#include <SDL.h>
#include "GameEngine.h"

// AppStates
#include "Title_AppState.h"
#include "Game_AppState.h"
#include "GameSetup_AppState.h"
#include "Load_AppState.h"
#include "Options_AppState.h"
#include "GameRootNode.h"
class GameApp : public GameEngine
{
public:
	GameApp() {}
	virtual ~GameApp() {}
	
private:
	void Setup()
	{
		//states.AddChild(new GameRootNode())


		//appFSM->AddState(new Title_AppState(appFSM->pointerBag));
		//appFSM->AddState(new Game_AppState(appFSM->pointerBag));
		//appFSM->AddState(new GameSetup_AppState(appFSM->pointerBag));
		//appFSM->AddState(new Load_AppState(appFSM->pointerBag));
		//appFSM->AddState(new Options_AppState(appFSM->pointerBag));

		//appFSM->ChangeState("Title");
	}
};
