#include <SDL.h>
#include "GameApp.h"

int main(int argc, char* argv[])
{
	GameApp* gameApp = new GameApp();
	gameApp->Run();
	delete gameApp;

	return 0;
}
