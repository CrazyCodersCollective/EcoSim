#include "RootNode.h"


RootNode::RootNode() {

}
RootNode::RootNode(SDL_Renderer* renderer, int x, int y) //: Node.renderer(renderer), Node.x(x), Node.y(y), Node.screen(this), Node.master(this)
{
	this->renderer = renderer;
	this->master = this;
	this->screen = this;
	this->x = x;
	this->y = y;
}


RootNode::~RootNode()
{
}
