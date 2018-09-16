#include <SDL.h>
#include "SDL_ImageLoader.h"
#include "sprite.h"




Sprite::Sprite(Node* master, int x, int y, std::string file)
{

	//Node::Node(master->renderer, x, y);
	//this->renderer = master->renderer;
	this->screen = master->screen;
	this->master = master;
	if (master->renderer == NULL)printf("null pointer in spritenode init");
	this->renderer = master->renderer;
	this->x = (float)x;
	this->y = (float)y;

	Texture(file);
}


Sprite::~Sprite()
{
}

void Sprite::render() {
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
	
	int w, h;
	texture = SDL_ImageLoader_LoadTexture(this->renderer, (char*)file.c_str());

	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);//can you just pass in &dest.w?
}
