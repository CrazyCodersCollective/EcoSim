#pragma once
#include "RootNode.h"
#include "AppFSM.h"

class MenuNode :
	public RootNode
{
public:
	MenuNode();
	~MenuNode();
private:
	AppFSM* app;
};

