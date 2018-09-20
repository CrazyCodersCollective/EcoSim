
#pragma once
#include "Node.h"

class RootNode :
	public Node
{
public:
	RootNode();
	RootNode(SDL_Renderer* renderer, int x = 0 , int y = 0);
	~RootNode();
	virtual void StartUp() {};
	virtual void HandleEvent(SDL_Event& event) {};
	virtual void Update() {};
	//virtual void Shutdown() = 0;
	//virtual void Render() = 0;
};

