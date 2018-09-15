#include "Node.h"



Node::Node(Node* master = NULL, int xp, int yp){
	if (master) {
		this->screen = master->screen;
		this->master = master;
		this->renderer = master->renderer;
	}
	this->x = (float)xp;
	this->y = (float)yp;
}

void Node::SetPos(float xp, float yp) {
	this->x = xp;
	this->y = yp;
	dest.x = (int)xp + master->x;
	dest.y = (int)yp + master->y;
}
void Node::AddPos(float xp, float yp) {
	this->x += xp;
	this->y += yp;
	dest.x = (int)x + master->x;
	dest.y = (int)y + master->y;
}
void Node::AddChild(Node* node) {
	node->screen = master->screen;
	node->master = master;
	node->renderer = master->renderer;

	children.push_back(node);//add sort insertion sort by z
 }