#pragma once
#include <SDL.h>
#include "GameEngine.h"

// AppStates
//#include "Title_AppState.h"
//#include "Game_AppState.h"
//#include "GameSetup_AppState.h"
//#include "Load_AppState.h"
//#include "Options_AppState.h"
//#include "GameRootNode.h"
class GameApp : public GameEngine
{
public:
	GameApp() {}
	virtual ~GameApp() {}
	
private:
	void Setup()
	{
		
	}
};
