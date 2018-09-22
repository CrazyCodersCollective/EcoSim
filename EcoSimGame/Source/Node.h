
#pragma once
#include "PointerBag.h"
#include <SDL.h>
#include <vector>
#include <iostream>
//#include "RootNode.h"

class Node {
public:
	Node(void);
	Node(Node* master, int x = 0, int y = 0);
	Node(SDL_Renderer* renderer, int x = 0, int y = 0);

	virtual ~Node(){}
	virtual void render();
	virtual void Destroy() {}

	void SetPos(float x, float y);
	void AddPos(float x, float y);
	void AddChild(Node* node);
	void SetZ(int z);
	int GetZ();
	
	float x = 0 ;//add seter and getter
	float y = 0;//add seter and getter
	
	float rotation;//add seter and getter

	std::vector<Node*> children;
	SDL_Renderer* renderer = nullptr;
	Node* screen;
	Node* master = nullptr;
	bool operator<(Node* rhs) const { return z < rhs->GetZ(); }
protected:
	
	SDL_Rect dest;
	void NewPos();
private:
	int z; //the draw order

};









