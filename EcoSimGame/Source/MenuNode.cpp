#include "MenuNode.h"



MenuNode::MenuNode()
{
}
MenuNode::MenuNode(PointerBag* pointerbag)
{
	this->pointerBag = pointerbag;
	app = new AppFSM(pointerbag);
	this->pointerBag->appFSM = app;
}


MenuNode::~MenuNode()
{
	
}

void MenuNode::render() {
	for (int i = 0; i < children.size(); i++) {
		children[i]->render();
	}
	app->OnRender();
	app->OnRenderUI();
}

void MenuNode::UpdateState() {
	app->UpdateFSM();
}

void MenuNode::HandleEvent(SDL_Event& event) {
	app->OnEvent(event);
}

void MenuNode::Update() {
	app->OnUpdate();
}

void MenuNode::AddState(AppState* state) {
	app->AddState(state);
}
void MenuNode::ChangeState(std::string stateName) {
	app->ChangeState(stateName);
}