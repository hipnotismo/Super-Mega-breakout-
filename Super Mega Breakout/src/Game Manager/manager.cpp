#include "manager.h"

#include "raylib.h"

#include "Screens/Menu/menu.h"
#include "Screens/Gameplay/gameplay.h"
#include "Screens/Credits/credits.h"

namespace gameManager {

	GameScreen Screens = GameScreen::Menu;

	const int screenWidth = 1000;
	const int screenHeight = 550;

	static void change();

	void manager() {

		InitWindow(screenWidth, screenHeight, "BREAKOUT V0.6");

		Init();

		while (!WindowShouldClose()){
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
			break;
		}
	}

	void Init() {

		menu::menuInit();
		gameplay::gameplayInit();
		credits::creditsInit();
	}
}