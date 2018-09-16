#pragma once
#include <string>
#include "AppState.h"
#include <SDL.h>
#include "PointerBag.h"
#include "Font.h"
#include "Text.h"
#include "SimpleButton.h"

/*
	TODO: Hovering buttons
*/

class GameSetup_AppState : public AppState
{
public:
	GameSetup_AppState(PointerBag* pointerBag) : pointerBag(pointerBag) { stateName = "GameSetup"; }
	virtual ~GameSetup_AppState() {}

	void OnEntry();
	void OnExit();
	void OnEvent(SDL_Event& event);
	void OnUpdate();
	void OnRender();
	void OnRenderUI();

private:
	/* Common stuff */
	PointerBag* pointerBag;
	SDL_Renderer* renderer;

	/* Game stuffs */
	Font* uiFont;
	//Text* testText;
	//Text* testText2;

	/* UI stuff */
	SimpleButton* sButtonBack;
	SimpleButton* sButtonReady;

	/* Game setup stuff */

	/* FOOD */
	int simFood;
	const int simFoodMax = 100;
	SimpleButton* sButtonFoodDecrease; // Decrease 1 food
	SimpleButton* sButtonFoodIncrease; // Increase 1 food
	Text* foodText;
	Text* foodLabelText;

	/* WATER */
	int simWater;
	const int simWaterMax = 100;
	SimpleButton* sButtonWaterDecrease; // Decrease 1 water
	SimpleButton* sButtonWaterIncrease; // Increase 1 water
	Text* waterText;
	Text* waterLabelText;
};
