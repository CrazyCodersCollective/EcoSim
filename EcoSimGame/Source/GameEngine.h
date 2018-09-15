#pragma once
#include <vector>
#include <SDL.h>
#include "PointerBag.h"
#include "Application.h"
#include "Node.h"

class GameEngine
{
public:
	GameEngine() {}
	virtual ~GameEngine() {}

	void Run();

protected:
	virtual void StartUp() = 0;
	virtual void Shutdown() = 0;
	virtual void HandleEvent(SDL_Event& event) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	void AddChild(Node* item);

	PointerBag pointerBag; // origin
	SDL_Renderer* renderer; // for quick lookup (not the source)

private:
	Application* application;
	std::vector<Node*> items;
};
