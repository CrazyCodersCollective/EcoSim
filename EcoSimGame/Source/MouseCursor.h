#pragma once
#include <string>
#include <SDL.h>

class MouseCursor
{
public:
	MouseCursor() {}
	virtual ~MouseCursor() {}

	bool Create(const std::string & filePath);
	void Destroy();

private:
	SDL_Cursor* cursor;
};
