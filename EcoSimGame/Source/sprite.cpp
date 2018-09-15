#include <SDL.h>
#include "SDL_ImageLoader.h"
#include "sprite.h"




Sprite::Sprite(PointerBag* master, int x, int y, std::string file)
{
	Node::Node(master, x, y);
	//this->renderer = master->GetRenderer();
	Texture(file);
	
}


Sprite::~Sprite()
{
}

void Sprite::render() {
	if (renderer && texture)
		SDL_RenderCopy(renderer, texture, NULL, &dest);
}
void Sprite::Destroy()
{
	if (texture)
		SDL_DestroyTexture(texture);
}
void Sprite::Texture(std::string file) {
	
	//if (texture)
		//SDL_DestroyTexture(texture);
	std::string texturePath = "Resource/Textures/testObject.png";
	char* file_path = (char*)texturePath.c_str();
	SDL_Texture* newTexture = NULL;

	// Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(file_path);
	
	if (loadedSurface == NULL)
	{
		printf("ERROR: Unable to load image %s! SDL_image Error: %s\n", file_path, IMG_GetError());
		// TODO(kim): implement error logging
	}
	else
	{
		// Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(master->GetRenderer(), loadedSurface);
		if (newTexture == NULL)
		{
			printf("ERROR: Unable to create texture from %s! SDL Error: %s\n", file_path, SDL_GetError());
			// TODO(kim): implement error logging
		}

		// Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	int w, h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);//can you just pass in &dest.w?
	dest.w = w;
	dest.h = h;
}
