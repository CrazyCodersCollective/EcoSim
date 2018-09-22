#include "ButtonNode.h"
#include <SDL_image.h>
#include <SDL_ttf.h>

ButtonNode::ButtonNode()
{
}
ButtonNode::ButtonNode(Node* master, SDL_Rect pos, const std::string & text)
{
	master->AddChild(this);
	font.LoadFont("Resource/Fonts/monogram.ttf", 28);
	x = pos.x;
	y = pos.y;
	dest = pos;

}
bool ButtonNode::SetText(const std::string & text) {

	if (UpTexture)
		SDL_DestroyTexture(UpTexture);
	if (DownTexture)
		SDL_DestroyTexture(UpTexture);
	font.LoadFont("Resource/Fonts/monogram.ttf", 28);

	SDL_Surface* textSurface;

	textSurface = TTF_RenderUTF8_Blended(font.GetFont(), text.c_str(), SDL_Color{ 255,0,255,255 });
	if (textSurface == NULL)
	{
		printf("ERROR: Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
		return false; // Failed!
	}
	else
	{
		// Create texture from surface pixels
		SDL_Texture* texts;
		texts = SDL_CreateTextureFromSurface(renderer, textSurface);
		if (texts == NULL)
		{
			printf("ERROR: Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
			return false; // Failed!
		}
		else
		{
			// Get image dimension
			int w, h;
			w = padx + (borderWidth * 2) + textSurface->w;
			h = pady + (borderWidth * 2) + textSurface->h;

			dest.w = w;
			dest.h = h;
			
			SDL_Surface* canva;
			canva = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 109);
			SDL_Surface* grad;
			grad = SDL_CreateRGBSurface(0, 1, 2, 32, 0, 255, 0, 100);
			//SDL_LockSurface(grad);
			SDL_Rect r = {0, 0, 1, 1};
			SDL_FillRect(grad, &r, SDL_MapRGB(grad->format, 255, 0, 255));
			r =  {0,1,1,1};
			SDL_FillRect(grad, &r, SDL_MapRGB(grad->format, 0, 0, 255));
			//SDL_FillRect(grad, &r, SDL_MapRGB(grad->format, 255, 0, 255));
			//grad->pixels = 255; 

			//SDL_UnlockSurface(grad);
			SDL_BlitScaled(grad,
				NULL,
				canva,
				NULL);
			r = { padx + borderWidth, pady + borderWidth, textSurface->w, textSurface->h };

			SDL_BlitSurface(textSurface, NULL,canva, &r);

			texture = SDL_CreateTextureFromSurface(renderer, canva);

			SDL_FreeSurface(canva);
			SDL_FreeSurface(grad);
			//todo gradiant border 

		}

		//Get rid of old surface
		SDL_FreeSurface(textSurface);
		
	}

	return true; // Success!
}

ButtonNode::~ButtonNode()
{
}
