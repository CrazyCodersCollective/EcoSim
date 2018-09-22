#pragma once
#include "SpriteNode.h"
#include <SDL_image.h>
#include "Font.h"

class ButtonNode :
	public Sprite
{
public:
	ButtonNode();
	ButtonNode(Node* master, SDL_Rect pos, const std::string & text);
	~ButtonNode();
	bool SetText(const std::string& text);
	

private:
	// inherit texture
	Font font;
	std::string text;
	SDL_Texture * UpTexture = nullptr;
	SDL_Texture* DownTexture = nullptr;
	int padx = 1;
	int pady = 1;
	int borderWidth = 1;
	int borderRad = 5;
	SDL_Color bgTop;
	SDL_Color bgBottom;
	SDL_Color borderColour;
	SDL_Color textColor;

};

