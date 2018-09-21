#pragma once
#include "RootNode.h"
//#include "AppFSM.h"
#include "PointerBag.h"
#include <vector>

class StateNode :
	public Node
{
public:
	StateNode();
	StateNode(PointerBag* pointerbag);
	~StateNode();
	void render();


	void SetState(int state);
	bool ChangeState(std::string& state);
	void AddChild(RootNode* node);

	PointerBag* pointerBag;
	RootNode* StateNow;
private:
	std::vector<RootNode*> states;
};

