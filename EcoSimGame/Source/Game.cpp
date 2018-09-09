#include "Game.h"
#include <string>
#include <stdio.h>
#include "SDL_ImageLoader.h"

void Game::init() {
	isRunning = true;

	if (SDL_Init(SDL_INIT_EVERYTHING)) {
		printf("ERROR: Unable to initialize SDL: %s", SDL_GetError());
		isRunning = false;
		return; // Failed!
	}

	window = SDL_CreateWindow("EcoSim", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0); // See SDL_WindowFlags for more info.
	if (!window) {
		printf("ERROR: Could not create window: %s\n", SDL_GetError());
		isRunning = false;
		return; // Failed!
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
	if (!renderer) {
		printf("ERROR: Could not create renderer: %s\n", SDL_GetError());
		isRunning = false;
		return; // False;
	}
}

void Game::loadResources()
{
	std::string texturePath = "Resource/Textures/testObject.png";
	testObject = SDL_ImageLoader_LoadTexture(renderer, (char*)texturePath.c_str());
	if (!testObject) {
		isRunning = false;
		return; // Failed!
	}
}

void Game::update() {
}

void Game::events() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			//processing events
			case (SDL_QUIT): {
				isRunning = false;
			} break;
			case (SDL_KEYDOWN): {
				printf("key pressed\n");
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					isRunning = false;
				}
			} break;
		}
	}
}

void Game::display() {
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, testObject, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void Game::quit() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}
