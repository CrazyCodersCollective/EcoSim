#include <SDL.h>
#include "Game.h"

int main(int argc, char* argv[])
{
	Game* game = new Game();
	game->init();

	game->loadResources();

	while (game->isRunning)
	{
		game->events();
		game->update();
		game->display();
	}

	game->quit();
	delete game;

	return 0;
}
