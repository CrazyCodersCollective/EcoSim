#include "AppExit_AppState.h"
#include <stdio.h>

void AppExit_AppState::OnEntry()
{
	printf("AppExit_AppState::OnEntry\n");

	renderer = pointerBag->GetRenderer();
}

void AppExit_AppState::OnExit()
{
	printf("AppExit_AppState::OnExit\n");
}

void AppExit_AppState::OnEvent(SDL_Event& event)
{
	printf("AppExit_AppState::OnEvent\n");
}

void AppExit_AppState::OnUpdate()
{
	printf("AppExit_AppState::OnUpdate\n");
}

void AppExit_AppState::OnRender()
{
	printf("AppExit_AppState::OnRender\n");
}

void AppExit_AppState::OnRenderUI()
{
	printf("AppExit_AppState::OnRenderUI\n");
}
