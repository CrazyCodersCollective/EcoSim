#pragma once
#include "RootNode.h"
class TitleRootNode :
	public RootNode
{
public:
	TitleRootNode();
	~TitleRootNode();

	void StartUp();
	void HandleEvent(SDL_Event& event);
	void Update();
	
};

