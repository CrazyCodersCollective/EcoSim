#include "GameRootNode.h"
#include "TextNode.h"

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
	
	text = new TextNode(this, 200, 300);
	SDL_Color* co = new SDL_Color{255,0,0,255 };
	text->SetText("Game! Press Q to return", 28, co);

	//sp = new Sprite(this, 100, 100, texturePath);

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
			pointerbag->isRunning = false;
		} break;
		case SDLK_q:
		{
			//pointerBag->appFSM->ChangeState("Title");
			//printf(NextState.c_str());
			NextState = "GameSetUp";
			
		} break;
		case SDLK_w:
		{
			//pointerBag->appFSM->ChangeState("Title");
			//printf(NextState.c_str());
			NextState = "json";

		} break;
		default:
			break;
		}
	} break;
	}
}
void GameRootNode::Update() {

}