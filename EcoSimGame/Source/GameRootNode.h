#pragma once
#include "RootNode.h"
#include "sprite.h"
class GameRootNode :
	public RootNode
{
public:
	//GameRootNode(SDL_Renderer* renderer, int x = 0, int y = 0);
	GameRootNode();
	~GameRootNode();
	void StartUp();
	void HandleEvent(SDL_Event& event);
	void Update();
private:
	Sprite* sp;
};

