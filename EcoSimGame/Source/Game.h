#pragma once
#include <SDL.h>
#include "GameEngine.h"
#include "Font.h"
#include "Text.h"
#include "sprite.h"
#include "ButtonNode.h"


class Game : public GameEngine
{
public:
	Game() {}

	virtual ~Game() {}
	
private:
	/* GameEngine */
	void StartUp();
	void Shutdown();



	/* Game stuffs */

	RootNode* test;
	
};
