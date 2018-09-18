#include "StateNode.h"



StateNode::StateNode()
{
}
StateNode::StateNode(PointerBag* pointerbag)
{
	this->pointerBag = pointerbag;
	app = new AppFSM(pointerbag);
	this->pointerBag->appFSM = app;
}


StateNode::~StateNode()
{
	
}

void StateNode::render() {
	for (int i = 0; i < children.size(); i++) {
		children[i]->render();
	}
	app->OnRender();
	app->OnRenderUI();
}

void StateNode::UpdateState() {
	app->UpdateFSM();
}

void StateNode::HandleEvent(SDL_Event& event) {
	app->OnEvent(event);
}

void StateNode::Update() {
	app->OnUpdate();
}

void StateNode::AddState(AppState* state) {
	app->AddState(state);
}
void StateNode::ChangeState(const std::string & stateName) {
	app->ChangeState(stateName);
}
