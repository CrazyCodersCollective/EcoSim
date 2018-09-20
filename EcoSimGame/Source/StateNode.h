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

	void SetState(int state);
	void AddChild(RootNode* node);

	PointerBag* pointerBag;
	RootNode* StateNow;
private:
	AppFSM* app;
	//RootNode* StateNow;
	std::vector<RootNode*> states;
};

