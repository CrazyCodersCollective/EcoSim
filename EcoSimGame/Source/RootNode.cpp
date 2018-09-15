#include "RootNode.h"



RootNode::RootNode(PointerBag* pointerBag, int x, int y)
{
	this->renderer = pointerBag->renderer;
	this->screen = this;
	this->master = this;
	this->x = x;
	this->y = y;
}


RootNode::~RootNode()
{
}
