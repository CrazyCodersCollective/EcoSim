#include "Node.h"



Node::Node(PointerBag* master, int x, int y){
	this->master = master;
	this->renderer = master->GetRenderer();
	this->x = x;
	this->y = y;
}

void Node::SetPos(int xp, int yp) {
	this->x = xp;
	this->y = yp;
	dest.x = xp;
	dest.y = yp;
}
