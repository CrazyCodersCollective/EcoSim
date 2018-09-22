#include "TextNode.h"


TextNode::TextNode(Node* master, int x, int y)
{
	this->x = (float)x;
	this->y = (float)y;
	master->AddChild(this);
}

TextNode::~TextNode()
{
}
void TextNode::SetText(const std::string& text, int psize, SDL_Color* pTextColor, SDL_Color* pBgColor) {

	

	if (font == nullptr || size != this->size) {
		font = TTF_OpenFont("Resource/Fonts/monogram.ttf", size);
		if (!(psize == NULL))
			this->size = psize;

		if (font == NULL)
			printf("ERROR: Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
	}


	if (pTextColor) {
		this->TextColor = SDL_Color{pTextColor->r, pTextColor->g, pTextColor->b, pTextColor->a};
	}
	if (BgColor) {
		this->BgColor = new SDL_Color{pBgColor->r, pBgColor->g, pBgColor->b, pBgColor->a};
	}

	SDL_Surface* textSurface;
	textSurface = TTF_RenderUTF8_Blended(font, text.c_str(), this->TextColor);//todo el, add diffrent colour

	if (!(BgColor == nullptr) && !(this->BgColor == nullptr)) {
		SDL_Surface* BgSurface;
		BgSurface = SDL_CreateRGBSurface(0, textSurface->w, textSurface->w, 32, this->BgColor->r, this->BgColor->g, this->BgColor->b, this->BgColor->a);
		SDL_BlitSurface(textSurface, NULL, BgSurface, NULL);
		textSurface = BgSurface;
		SDL_FreeSurface(BgSurface);
		//printf("bg true");
	}

	if (textSurface == NULL)
	{
		printf("ERROR: Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}

	if (renderer) {
		texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	}
	else
		printf("no rederer in text node");

	dest.w = textSurface->w;
	dest.h = textSurface->h;

	SDL_FreeSurface(textSurface);


}