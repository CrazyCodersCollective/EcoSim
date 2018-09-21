#include "StateNode.h"



StateNode::StateNode()
{
}

StateNode::StateNode(PointerBag* pointerbag)
{
	this->pointerBag = pointerbag;
	this->master = this;
	this->renderer = pointerbag->renderer;
}


StateNode::~StateNode()
{
	
}

void StateNode::render() {
	for (int i = 0; i < children.size(); i++) {
		states[i]->render();
	}
}


void StateNode::SetState(int state) {
	if (state < states.size()) {
		this->StateNow = states[state];
	}
	else { printf("index out of range"); }
}
void StateNode::AddChild(RootNode* node) {
	node->screen = this;
	node->master = this;
	node->renderer = renderer;
	

	states.push_back(node);//add sort insertion sort by z
}

bool StateNode::ChangeState(std::string& state) {
	for (int i = 0; i < states.size(); i++)
	{
		if (states[i]->State == state)
		{
			if (states[i]->init) {
				states[i]->StartUp();
				states[i]->init = false;
			}
			SetState(i);
			return true; 
		}
	}
	return false;
}