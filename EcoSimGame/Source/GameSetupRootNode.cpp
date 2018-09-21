#include "GameSetupRootNode.h"


GameSetupRootNode::GameSetupRootNode()
{
	State = "GameSetUp";
}


GameSetupRootNode::~GameSetupRootNode()
{
}

void GameSetupRootNode::StartUp() {

	std::string texturePath = "Resource/Textures/testObject.png";
	sp = new Sprite(this, 200, 100, texturePath);

}
void GameSetupRootNode::HandleEvent(SDL_Event& event) {
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
			NextState = "Game";

		} break;
		default:
			break;
		}
	} break;
	}
}
void GameSetupRootNode::Update() {

}