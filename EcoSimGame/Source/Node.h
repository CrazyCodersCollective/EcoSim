
#pragma once
#include "PointerBag.h"
#include <SDL.h>
#include <vector>
//#include "RootNode.h"

class Node {
public:
	Node(void);
	Node(Node* master, int x = 0, int y = 0);
	Node(SDL_Renderer* renderer, int x = 0, int y = 0);

	virtual ~Node(){}
	virtual void render(){}
	virtual void Destroy() {}

	void SetPos(float x, float y);
	void AddPos(float x, float y);
	void AddChild(Node* node);

	
	float x;//add seter and getter
	float y;//add seter and getter
	int z; //the draw order
	float rotation;//add seter and getter

	std::vector<Node*> children;
	SDL_Renderer* renderer = nullptr;
	Node* screen;

protected:
	Node* master = nullptr;
	SDL_Rect dest;

	

};









