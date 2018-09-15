#include <SDL.h>
#include "SDL_ImageLoader.h"
#include "sprite.h"




Sprite::Sprite(Node* master, int x, int y, std::string file)
{
	Node::Node(master, x, y);
	Texture(file);
}


Sprite::~Sprite()
{
}

void Sprite::render() {
	if (renderer && texture)//madatory texture or test for textutreeach frame?
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
	texture = SDL_ImageLoader_LoadTexture(renderer, (char*)file.c_str());
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);//can you just pass in &dest.w?
	dest.w = w;
	dest.h = h;
}
