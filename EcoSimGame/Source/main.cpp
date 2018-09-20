#include <SDL.h>
#include "GameApp.h"
#include "Game.h"

#if defined(unix) || defined(__unix) || defined(__unix__)
#define x
#include <unistd.h>
#include <string>
#endif

int main(int argc, char* argv[])
{
	// Ugly hack to ensure that the program runs in its
	// correct current working directory (cwd).
	// Necessary to find the location of the media files.
#ifdef x
    std::string cwd = argv[0];  // the invocation path
    int count = cwd.size() - 1;
    for( auto it = cwd.end()-1;  *it != '/' && it != cwd.begin();  --it,--count )
    {};
    cwd = cwd.substr( 0, count);
    chdir( cwd.c_str());  // set the working directory
 #endif

	//GameApp* gameApp = new GameApp();
	//gameApp->Run();
	//delete gameApp;

	Game* game = new Game();
	game->Run();
	delete game;
	return 0;

	return 0;
}
