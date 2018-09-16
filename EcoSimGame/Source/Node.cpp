#include "Node.h"



Node::Node(Node* master, int xp, int yp){
	if (master) {
		this->screen = master->screen;
		this->master = master;
		if (master->renderer) {
			this->renderer = master->renderer;
			printf("null pointer in node init");
		}
	}
	this->x = (float)xp;
	this->y = (float)yp;
}
Node::Node(){}
Node::Node(SDL_Renderer* renderer, int x , int y) {

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