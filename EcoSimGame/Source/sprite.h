#pragma once
#include <string>
#include "Node.h"
class Sprite :
	public Node
{
public:
	Sprite(Node* master, int x, int y, const std::string & file);
	Sprite(){}
	~Sprite();
	virtual void render();
	virtual void Destroy();
	void Texture(std::string file);
protected:
	SDL_Texture* texture = nullptr;
};

