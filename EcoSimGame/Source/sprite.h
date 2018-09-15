#pragma once
#include <string>
#include "Node.h"
class Sprite :
	public Node
{
public:
	Sprite(Node* master, int x, int y, std::string file);
	Sprite(){}
	~Sprite();
	void render();
	void Destroy();
	void Texture(std::string file);
protected:
	SDL_Texture* texture;
};

