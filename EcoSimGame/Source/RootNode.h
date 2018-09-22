
#pragma once
#include "Node.h"
#include "json.hpp"

class RootNode :
	public Node
{
public:
	RootNode();
	RootNode(PointerBag* pointerbag, int x = 0 , int y = 0);
	~RootNode();
	virtual void StartUp() {};
	virtual void HandleEvent(SDL_Event& event) {};
	virtual void Update() {};
	RootNode* Fromjson(const char* filepath);

	bool init = true;
	std::string State = "";
	std::string NextState = "";
	PointerBag* pointerbag = nullptr;
private:
	void ProssesJson(RootNode* node, nlohmann::json j);
	void ProssesNodes(Node* node, nlohmann::json j);
	void ProssesNode(Node* node, nlohmann::json j);
	void ProssesSprite(Node* node, nlohmann::json j);
	void ProssesButton(Node* node, nlohmann::json j);
};

