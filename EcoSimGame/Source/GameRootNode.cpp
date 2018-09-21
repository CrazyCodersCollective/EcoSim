#include "GameRootNode.h"


GameRootNode::GameRootNode()
{
	State = "Game";
	//RootNode::RootNode(renderer, x, y); SDL_Renderer* renderer, int x, int y
}


GameRootNode::~GameRootNode()
{
}

void GameRootNode::StartUp(){
	
	std::string texturePath = "Resource/Textures/testObject.png";
	sp = new Sprite(this, 100, 100, texturePath);

}
void GameRootNode::HandleEvent(SDL_Event& event) {
	switch (event.type)
	{
	case SDL_KEYDOWN:
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
		{
			//pointerBag->isRunning = false;
		} break;
		case SDLK_q:
		{
			//pointerBag->appFSM->ChangeState("Title");
			//printf(NextState.c_str());
			NextState = "GameSetUp";
			
		} break;
		default:
			break;
		}
	} break;
	}
}
void GameRootNode::Update() {

}