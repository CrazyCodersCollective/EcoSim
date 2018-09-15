#include "AppFSM.h"
#include <stdlib.h>
#include "AppInit_AppState.h"
#include "AppExit_AppState.h"

#include <assert.h>

AppFSM::AppFSM(PointerBag* pointerBag) : pointerBag(pointerBag)
{
	pointerBag->appFSM = this;

	vAppStates.push_back(new AppInit_AppState(pointerBag));
	vAppStates.push_back(new AppExit_AppState(pointerBag));
	
	activeState = 0;
	gotoState = 0;
	vAppStates.at(activeState)->OnEntry();

	// Run once
	vAppStates.at(activeState)->OnUpdate();
	vAppStates.at(activeState)->OnRender();
	vAppStates.at(activeState)->OnRenderUI();
}

AppFSM::~AppFSM()
{
	ChangeState("AppExit");
	vAppStates.at(activeState)->OnExit();
}

void AppFSM::UpdateFSM()
{
	if (activeState != gotoState)
	{
		vAppStates.at(activeState)->OnExit();
		activeState = gotoState;
		vAppStates.at(activeState)->OnEntry();
	}
}

void AppFSM::AddState(AppState* appState)
{
	vAppStates.push_back(appState);
}

void AppFSM::ChangeState(std::string stateName)
{
	gotoState = FindStateByName(stateName);
	if (gotoState == -1)
	{
		printf("ERROR: Could not find state by name: %s\n", stateName.c_str());
		exit(1);
	}
}

void AppFSM::OnEvent(SDL_Event& event)
{
	vAppStates.at(activeState)->OnEvent(event);
}

void AppFSM::OnUpdate()
{
	vAppStates.at(activeState)->OnUpdate();
}

void AppFSM::OnRender()
{
	vAppStates.at(activeState)->OnRender();
}

void AppFSM::OnRenderUI()
{
	vAppStates.at(activeState)->OnRenderUI();
}

int AppFSM::FindStateByName(std::string stateName)
{
	for (int i = 0; i < vAppStates.size(); i++)
	{
		if (vAppStates[i]->GetStateName() == stateName)
		{
			return i; // Success! We found the state
		}
	}

	return -1; // Failure! Could not find the state by that name
}
