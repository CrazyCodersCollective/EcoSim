#pragma once
#include "RootNode.h"
#include "AppFSM.h"
#include "PointerBag.h"

class StateNode :
	public RootNode
{
public:
	StateNode();
	StateNode(PointerBag* pointerbag);
	~StateNode();
	//AppFSM* app;
	void render();
	void UpdateState();
	void HandleEvent(SDL_Event& event);
	void Update();
	void AddState(AppState* state);
	void ChangeState(std::string stateName);

	PointerBag* pointerBag;
private:
	AppFSM* app;
	RootNode* StateNow;
};

