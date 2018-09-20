#include "StateNode.h"



StateNode::StateNode()
{
}

StateNode::StateNode(PointerBag* pointerbag)
{
	this->pointerBag = pointerbag;
	//app = new AppFSM(pointerbag);
	this->master = this;
	this->pointerBag->appFSM = app;
	this->renderer = pointerbag->renderer;
}


StateNode::~StateNode()
{
	
}

void StateNode::render() {
	for (int i = 0; i < children.size(); i++) {
		states[i]->render();
	}
	//printf("rederer");
	//app->OnRender();
	//app->OnRenderUI();
}

void StateNode::UpdateState() {
	//app->UpdateFSM();
}

void StateNode::HandleEvent(SDL_Event& event) {
	//app->OnEvent(event);
}

void StateNode::Update() {
	//app->OnUpdate();
}

void StateNode::AddState(AppState* state) {
	//state->OnRender =
	//app->AddState(state);
}
void StateNode::ChangeState(std::string stateName) {
	//app->ChangeState(stateName);
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