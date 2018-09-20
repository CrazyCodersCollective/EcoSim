#include "SimpleButton.h"

SimpleButton::SimpleButton(SDL_Renderer* renderer,
		                   Font* font,
						   SDL_Rect rect,
						   const std::string & text,
						   SDL_Color foreColor, SDL_Color backColor
)
	: renderer(renderer),
	rect(rect),
	textString(text),
	foreColor(foreColor),
	backColor(backColor)
{
	this->text = new Text(renderer, textString, font);

	float tX = 6.0f; // Text origin
	float tY = -12.0f; // ..

	tY += rect.h / 2;
	this->text->Create((float)rect.x+tX, (float)rect.y+tY, foreColor);
}

SimpleButton::~SimpleButton()
{
	text->Destroy();
	delete text;
}

bool SimpleButton::EventMouseHover(SDL_Event& event)
{
	if (event.type != SDL_MOUSEMOTION)
		return false;

	int mx;
	int my;
	SDL_GetMouseState(&mx, &my);
	if (isPointInsideBox(mx, my, rect))
		return true; // Hovering button

	return false; // Not hovering
}

bool SimpleButton::EventMouseDown(SDL_Event& event)
{
	if (event.type != SDL_MOUSEBUTTONDOWN)
		return false;

	int mx;
	int my;
	int mb = SDL_GetMouseState(&mx, &my);
	if (SDL_BUTTON(mb) == SDL_BUTTON_LEFT)
	{
		if (isPointInsideBox(mx, my, rect))
			return true; // Pressing button
	}

	return false;
}

bool SimpleButton::EventMouseUp(SDL_Event& event)
{
	if (event.type != SDL_MOUSEBUTTONUP)
		return false;

	int mx;
	int my;
	int mb = SDL_GetMouseState(&mx, &my);
	if (SDL_BUTTON(mb) == SDL_BUTTON_LEFT)
	{
		if (isPointInsideBox(mx, my, rect))
			return true; // Releasing button
	}

	return false;
}

bool SimpleButton::EventMouseClick(SDL_Event& event)
{
	if (event.type == SDL_MOUSEBUTTONUP)
	{
		ResetClickEvent();
		return false;
	}

	int mx;
	int my;
	int mb = SDL_GetMouseState(&mx, &my);
	if (SDL_BUTTON(mb) == SDL_BUTTON_LEFT)
	{
		if (isPointInsideBox(mx, my, rect))
		{
			if (!isDown)
			{
				isDown = true;
				return true; // Clicked button
			}
		}
	}

	return false; // Not clicked
}

void SimpleButton::Render()
{
	// Draw button background
	SDL_SetRenderDrawColor(renderer, backColor.r, backColor.g, backColor.b, backColor.a);
	SDL_RenderFillRect(renderer, &rect);

	// Draw button border
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderDrawRect(renderer, &rect);

	// Draw button text
	text->Render();
}

bool SimpleButton::isPointInsideBox(int mx, int my, SDL_Rect box)
{
	if (mx > box.x && mx <= (box.x + box.w))
		if (my > box.y && my <= (box.y + box.h))
			return true;

	return false;
}
