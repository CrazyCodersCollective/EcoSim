#include "Node.h"



Node::Node(Node* master, int xp, int yp){
	
	//this->screen = master->screen;
	//this->master = master;
	//if (master->renderer == NULL)printf("null pointer in node init");
	//this->renderer = master->renderer;
	this->x = (float)xp;
	this->y = (float)yp;
	master->AddChild(this);
}
Node::Node(){}

Node::Node(SDL_Renderer* renderer, int xp , int yp) {
	this->renderer = renderer;
	this->x = (float)xp;
	this->y = (float)yp;
}
void Node::SetPos(float xp, float yp) {
	this->x = xp;
	this->y = yp;
	dest.x = (int)xp;// +master->x;
	dest.y = (int)yp;// +master->y;
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
void Node::render() {
	for (int i = 0; i < children.size(); i++) {
		children[i]->render();
	}
}