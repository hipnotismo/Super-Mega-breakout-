#include "manager.h"

#include "raylib.h"

#include "Screens/Menu/menu.h"
#include "Screens/Gameplay/gameplay.h"
#include "Screens/Credits/credits.h"

namespace gameManager {

	GameScreen Screens;

	const int screenWidth = 1000;
	const int screenHeight = 550;

	static void change();

	void manger() {

		InitWindow(screenWidth, screenHeight, "BREAKOUT V0.5");

		Init();

		while (!WindowShouldClose()){
			change();

		}
		CloseWindow();
	}

	static void change() {

		switch (Screens) {
		case Menu:
			menu::menuUpdate();
			break;
		case Game:
			gameplay::gameplayUpdate();
			break;
		case Credits:
			credits::creditsUpdate();
			break;
		case End:
			break;
		}
	}

	void Init() {

		menu::menuInit();
		gameplay::gameplayInit();
		credits::creditsInit();
	}
}