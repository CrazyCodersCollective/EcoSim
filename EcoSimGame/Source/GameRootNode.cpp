#include "GameRootNode.h"



GameRootNode::GameRootNode()
{
	//RootNode::RootNode(renderer, x, y); SDL_Renderer* renderer, int x, int y
}


GameRootNode::~GameRootNode()
{
}

void GameRootNode::StartUp(){
	//sp = Sprite(thi	)
	std::string texturePath = "Resource/Textures/testObject.png";
	//root =  new RootNode(this->pointerBag.GetRenderer());
	//butt = new ButtonNode(&screen, SDL_Rect{ 100, 100, 100, 100 }, "hello");
	sp = new Sprite(this, 100, 100, texturePath);

	this->AddChild(sp);

}
