#pragma once
#include "Node.h"
class RootNode :
	public Node
{
public:
	RootNode(){}
	RootNode(PointerBag* screen, int x, int y);
	~RootNode();
};

