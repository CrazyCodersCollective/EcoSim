#pragma once
#include <string>
#include <vector>
#include "AppState.h"
#include "PointerBag.h"

/*
	NOTE: This FSM state machine is not a true FSM but simplified.

	TODO(kim): Battle test this FSM
*/


class AppFSM
{
public:
	AppFSM() {}
	AppFSM(PointerBag* pointerBag);
	virtual ~AppFSM();

	void UpdateFSM();

	void AddState(AppState* appState);
	//void RemoveState(std::string stateName); // TODO(kim): implement code
	void ChangeState(std::string stateName);

	// States
	void OnEvent(SDL_Event& event);
	void OnUpdate();
	void OnRender();
	void OnRenderUI();

	// Getter
	PointerBag* pointerBag;
	//PointerBag* GetPointerBag() { return pointerBag; }
		
private:
	//PointerBag* pointerBag;

	std::vector<AppState*> vAppStates;
	int activeState;
	int gotoState;

	int FindStateByName(std::string stateName);
};
