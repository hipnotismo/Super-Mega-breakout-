#include "manager.h"

#include "raylib.h"

#include "Screens/Menu/menu.h"
#include "Screens/Gameplay/gameplay.h"
#include "Screens/Credits/credits.h"

namespace gameManager {

	GameScreen Screens = GameScreen::Menu;

	const int screenWidth = 1000;
	const int screenHeight = 550;
	 bool playing = true;

	static void change();

	void run() {

		InitWindow(screenWidth, screenHeight, "BREAKOUT V0.7");

		Init();

		while (!WindowShouldClose() && playing){
			change();

		}

		CloseWindow();
	}

	static void change() {

		switch (Screens) {
		case GameScreen::Menu:
			menu::menuUpdate();
			break;
		case GameScreen::Game:
			gameplay::gameplayUpdate();
			break;
		case GameScreen::Credits:
			credits::creditsUpdate();
			break;
		case GameScreen::End:
			playing = false;
			break;
		}
	}

	void Init() {

		menu::menuInit();
		gameplay::gameplayInit();
		credits::creditsInit();
	}
}