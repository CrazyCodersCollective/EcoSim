
#pragma once
#include "Node.h"

class RootNode :
	public Node
{
public:
	RootNode();
	RootNode(SDL_Renderer* renderer, int x = 0 , int y = 0);
	~RootNode();
};

