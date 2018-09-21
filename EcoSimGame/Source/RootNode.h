
#pragma once
#include "Node.h"
#include "json.hpp"

class RootNode :
	public Node
{
public:
	RootNode();
	RootNode(SDL_Renderer* renderer, int x = 0 , int y = 0);
	~RootNode();
	virtual void StartUp() {};
	virtual void HandleEvent(SDL_Event& event) {};
	virtual void Update() {};
	RootNode* Fromjson(std::string* filepath);

	bool init = true;
	std::string State = "";
	std::string NextState = "";

};

