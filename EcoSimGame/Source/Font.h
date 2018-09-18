#pragma once
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

class Font
{
public:
	Font() {}
	virtual ~Font() {}

	bool LoadFont(const std::string & path, int size);
	void FreeFont();
	
	TTF_Font* GetFont() { return ttf_font; }

private:
	TTF_Font* ttf_font = nullptr;
};
