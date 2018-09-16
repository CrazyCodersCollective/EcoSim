#include "TitleMenu.h"

int TitleMenu::EventButtonPressed(SDL_Event& event)
{
	int mx;
	int my;
	Uint32 mb = SDL_GetMouseState(&mx, &my); // For more info: SDL_mouse.h
	if (SDL_BUTTON(mb) == SDL_BUTTON_LEFT)
	{
		for (int i = 0; i < vMenuButtons.size(); i++)
			if (isPointInsideBox(mx, my, vMenuButtons[i]->GetRect()))
				return i;
	}

	return -1; // No button clicked
}

int TitleMenu::EventButtonHovered(SDL_Event& event)
{
	int mx;
	int my;
	Uint32 mb = SDL_GetMouseState(&mx, &my); // For more info: SDL_mouse.h
	//if (SDL_BUTTON(mb) == 0)
	{
		for (int i = 0; i < vMenuButtons.size(); i++)
			if (isPointInsideBox(mx, my, vMenuButtons[i]->GetRect()))
				return i;
	}

	return -1; // No button hovered
}

void TitleMenu::Render()
{
	for (auto& it : vMenuButtons)
		it->Render();
}

void TitleMenu::AddButton(UITexture* uiTexture, SDL_Rect srcRect, SDL_Rect dstRect)
{
	vMenuButtons.push_back(new MenuButton(renderer, uiTexture, srcRect, dstRect));
}

void TitleMenu::ClearHovers()
{
	for (auto& it : vMenuButtons)
		it->SetHover(false);
}

bool TitleMenu::isPointInsideBox(int mx, int my, SDL_Rect box)
{
	if (mx > box.x && mx <= (box.x + box.w))
		if (my > box.y && my <= (box.y + box.h))
			return true;

	return false;
}
