#include "GameSetup_AppState.h"
#include <stdio.h>
#include "SDL_ImageLoader.h"
#include "AppFSM.h"

void GameSetup_AppState::OnEntry()
{
	//printf("GameSetup_AppState::OnEntry\n");

	renderer = pointerBag->GetRenderer();

	testFont = new Font();
	testFont->LoadFont("Resource/Fonts/monogram.ttf", 28);
	
	testText = new Text(renderer, "GameSetup! Press Q to return.", testFont);
	testText->Create(200, 300, SDL_Color{ 255,0,0,255 });

	testText2 = new Text(renderer, "Press ENTER to start game.", testFont);
	testText2->Create(200, 350, SDL_Color{ 255,0,0,255 });

	/* Default simulation properties */
	simFood = 10;
	simWater = 50;

	/* Create UI */
	sButtonBack = new SimpleButton(renderer, testFont, SDL_Rect{ 50,550, 100, 30 }, "Back", SDL_Color{ 255,255,255,255 }, SDL_Color{ 163,163,163,255 });
	sButtonReady = new SimpleButton(renderer, testFont, SDL_Rect{ 650,550,100, 30 }, "Ready", SDL_Color{ 255,255,255,255 }, SDL_Color{ 163,163,163,255 });

	/* FOOD */
	sButtonFoodDecrease = new SimpleButton(renderer, testFont, SDL_Rect{ 280,200, 20, 20 }, "-", SDL_Color{ 255,255,255,255 }, SDL_Color{ 163,163,163,255 });
	sButtonFoodIncrease = new SimpleButton(renderer, testFont, SDL_Rect{ 335,200, 20, 20 }, "+", SDL_Color{ 255,255,255,255 }, SDL_Color{ 163,163,163,255 });
	foodLabelText = new Text(renderer, "Food:", testFont);
	foodLabelText->Create(200, 198, SDL_Color{ 255,255,255,255 });
	foodText = new Text(renderer, std::to_string(simFood), testFont);
	foodText->Create(310, 198, SDL_Color{ 255,255,255,255 });

	/* WATER */
	sButtonWaterDecrease = new SimpleButton(renderer, testFont, SDL_Rect{ 280,220, 20, 20 }, "-", SDL_Color{ 255,255,255,255 }, SDL_Color{ 163,163,163,255 });
	sButtonWaterIncrease = new SimpleButton(renderer, testFont, SDL_Rect{ 335,220, 20, 20 }, "+", SDL_Color{ 255,255,255,255 }, SDL_Color{ 163,163,163,255 });
	waterLabelText = new Text(renderer, "Water:", testFont);
	waterLabelText->Create(200, 218, SDL_Color{ 255,255,255,255 });
	waterText = new Text(renderer, std::to_string(simWater), testFont);
	waterText->Create(310, 218, SDL_Color{ 255,255,255,255 });
}

void GameSetup_AppState::OnExit()
{
	//printf("GameSetup_AppState::OnExit\n");

	/* UI */
	delete sButtonBack;
	delete sButtonReady;

	/* FOOD */
	delete sButtonFoodDecrease;
	delete sButtonFoodIncrease;
	if (foodLabelText)
		foodLabelText->Destroy();
	if (foodText)
		foodText->Destroy();

	/* WATER */
	delete sButtonWaterDecrease;
	delete sButtonWaterIncrease;
	if (waterLabelText)
		waterLabelText->Destroy();
	if (waterText)
		waterText->Destroy();

	//
	if (testText)
		testText->Destroy();

	if (testText2)
		testText2->Destroy();

	if (testFont)
		testFont->FreeFont();
}

void GameSetup_AppState::OnEvent(SDL_Event& event)
{
	//printf("GameSetup_AppState::OnEvent\n");

	switch (event.type)
	{
		case SDL_KEYDOWN:
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
			{
				pointerBag->isRunning = false;
			} break;
			case SDLK_q:
			{
				pointerBag->appFSM->ChangeState("Title");
			} break;
			case SDLK_RETURN:
			{
				pointerBag->appFSM->ChangeState("Game");
			} break;
			default:
				break;
			}
		} break;
		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
		{
			/* UI */
			if (sButtonBack->EventMouseClick(event))
			{
				pointerBag->appFSM->ChangeState("Title");
				return;
			}
			if (sButtonReady->EventMouseClick(event))
			{
				pointerBag->appFSM->ChangeState("Game");
				return;
			}

			/* FOOD */
			if (sButtonFoodDecrease->EventMouseClick(event))
			{
				// Decrease food
				simFood--;
				if (simFood < 0)
					simFood = 0;
				foodText->SetString(std::to_string(simFood));
			}
			if (sButtonFoodIncrease->EventMouseClick(event))
			{
				// Increase food
				simFood++;
				if (simFood > simFoodMax)
					simFood = simFoodMax;
				foodText->SetString(std::to_string(simFood));
			}

			/* WATER */
			if (sButtonWaterDecrease->EventMouseClick(event))
			{
				// Decrease water
				simWater--;
				if (simWater < 0)
					simWater = 0;
				waterText->SetString(std::to_string(simWater));
			}
			if (sButtonWaterIncrease->EventMouseClick(event))
			{
				// Increase water
				simWater++;
				if (simWater > simWaterMax)
					simWater = simWaterMax;
				waterText->SetString(std::to_string(simWater));
			}
		} break;
	}

}

void GameSetup_AppState::OnUpdate()
{
	//printf("GameSetup_AppState::OnUpdate\n");
}

void GameSetup_AppState::OnRender()
{
	//printf("GameSetup_AppState::OnRender\n");

	if (!renderer)
		return;

	SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
	SDL_RenderFillRect(renderer, NULL);
}

void GameSetup_AppState::OnRenderUI()
{
	//printf("GameSetup_AppState::OnRenderUI\n");

	if (!renderer)
		return;

	/* UI */
	sButtonBack->Render();
	sButtonReady->Render();

	/* FOOD */
	foodLabelText->Render();
	foodText->Render();
	sButtonFoodDecrease->Render();
	sButtonFoodIncrease->Render();

	/* WATER */
	waterLabelText->Render();
	waterText->Render();
	sButtonWaterDecrease->Render();
	sButtonWaterIncrease->Render();

	//
	testText->Render();
	testText2->Render();
}
