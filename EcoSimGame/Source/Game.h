#pragma once
#include <SDL.h>
#include "GameEngine.h"
#include "Font.h"
#include "Text.h"
#include "sprite.h"

class Game : public GameEngine
{
public:
	Game() {}

	virtual ~Game() {}
	
private:
	/* GameEngine */
	void StartUp();
	void Shutdown();
	void HandleEvent(SDL_Event& event);
	void Update();
	void Render();

	/* Game stuffs */
	SDL_Texture* testObject;
	Sprite* TestSprite;
	Sprite* TestSprite2;
};
