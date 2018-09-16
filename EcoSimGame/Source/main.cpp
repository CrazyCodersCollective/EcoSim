#include <SDL.h>
#include "GameApp.h"
#include "Game.h"

int main(int argc, char* argv[])
{
	//GameApp* gameApp = new GameApp();
	//gameApp->Run();
	//delete gameApp;

	Game* game = new Game();
	game->Run();
	delete game;
	return 0;

	return 0;
}
