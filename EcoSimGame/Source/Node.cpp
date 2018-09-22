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
	NewPos();
}
void Node::AddPos(float xp, float yp) {
	this->x += xp;
	this->y += yp;
	NewPos();
}
void Node::NewPos() {
	dest.x = x + master->x;
	dest.y = y + master->y;
	for (int i = 0; i < children.size(); i++) {
		children[i]->NewPos();
	}
}
void Node::AddChild(Node* node) {
	node->screen = master->screen;
	node->master = this;
	node->renderer = master->renderer;
	node->NewPos();
	children.push_back(node);//add sort insertion sort by z
 }
void Node::render() {
	for (int i = 0; i < children.size(); i++) {
		children[i]->render();
	}
}