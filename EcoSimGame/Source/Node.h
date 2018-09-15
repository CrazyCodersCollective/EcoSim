#pragma once
#include "PointerBag.h"
#include <SDL.h>

class Node {
public:
	Node(void){}
	Node(PointerBag* master, int x = 0, int y = 0);
	virtual ~Node(){}
	virtual void render(){}
	void SetPos(int x, int y);
	virtual void Destroy(){}

	int x;
	int y;

protected:
	PointerBag* master = nullptr;
	SDL_Renderer* renderer;
	SDL_Rect dest;

};









