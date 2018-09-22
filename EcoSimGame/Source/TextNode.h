#pragma once
#include "SpriteNode.h"
#include <SDL_ttf.h>
class TextNode :
	public Sprite
{
public:
	TextNode(Node* master, int x = 0, int y = 0);
	~TextNode();
	void SetText(const std::string& text, int psize = NULL, SDL_Color* pTextColor = nullptr, SDL_Color* pBgColor = nullptr);

private:
	TTF_Font* font = nullptr;
	int size = 28;//defult
	SDL_Color TextColor = SDL_Color{255,255,255,0};
	SDL_Color* BgColor = nullptr;


};

