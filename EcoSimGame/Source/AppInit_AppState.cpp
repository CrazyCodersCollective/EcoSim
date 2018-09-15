#include "AppInit_AppState.h"
#include <stdio.h>

void AppInit_AppState::OnEntry()
{
	printf("AppInit_AppState::OnEntry\n");

	renderer = pointerBag->GetRenderer();
}

void AppInit_AppState::OnExit()
{
	printf("AppInit_AppState::OnExit\n");
}

void AppInit_AppState::OnEvent(SDL_Event& event)
{
	printf("AppInit_AppState::OnEvent\n");
}

void AppInit_AppState::OnUpdate()
{
	printf("AppInit_AppState::OnUpdate\n");
}

void AppInit_AppState::OnRender()
{
	printf("AppInit_AppState::OnRender\n");
}

void AppInit_AppState::OnRenderUI()
{
	printf("AppInit_AppState::OnRenderUI\n");
}
