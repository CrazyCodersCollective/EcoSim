#include <SDL.h>
#include "SDL_ImageLoader.h"
#include "SpriteNode.h"




Sprite::Sprite(Node* master, int x, int y, const std::string & file)
{

	//Node::Node(master->renderer, x, y); get this working
	this->renderer = master->renderer;
	this->screen = master->screen;
	this->master = master;
	if (master->renderer == NULL)printf("null pointer in spritenode init");
	//this->renderer = master->renderer;
	master->AddChild(this);
	SetPos(x, y);

	Texture(file);
}


Sprite::~Sprite()
{
}

void Sprite::render() {
	for (int i = 0; i < children.size(); i++) {
		children[i]->render();
	}
	if (renderer && texture)//madatory texture or test for textutr eeach frame?
		SDL_RenderCopy(renderer, texture, NULL, &dest);
}
void Sprite::Destroy()
{
	if (texture)
		SDL_DestroyTexture(texture);
}
void Sprite::Texture(std::string file) {
	
	if (texture)
		SDL_DestroyTexture(texture);
	
	
	texture = SDL_ImageLoader_LoadTexture(this->renderer, (char*)file.c_str());

	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);//can you just pass in &dest.w?
}
