#include "MenuButton.h"

MenuButton::MenuButton(SDL_Renderer* renderer, UITexture* uiTexture, SDL_Rect srcRect, SDL_Rect dstRect)
{
	this->renderer = renderer;
	this->uiTexture = uiTexture;
	this->srcRect = srcRect;
	this->dstRect = dstRect;
}

MenuButton::~MenuButton()
{
	delete uiTexture;
}

void MenuButton::Render()
{
	if (isHovered)
	{
		SDL_Rect hoverRect = srcRect;
		hoverRect.x = 256;
		SDL_RenderCopy(renderer, uiTexture->GetTexture(), &hoverRect, &dstRect);
	}
	else
		SDL_RenderCopy(renderer, uiTexture->GetTexture(), &srcRect, &dstRect);
}
