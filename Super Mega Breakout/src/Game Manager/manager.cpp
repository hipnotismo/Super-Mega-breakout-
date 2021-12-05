#include "manager.h"

#include "raylib.h"

#include "Screens/Menu/menu.h"
#include "Screens/Gameplay/gameplay.h"

namespace gameManager {

	GameScreen Screens;

	const int screenWidth = 1000;
	const int screenHeight = 550;

	static void change();

	void manger() {

		InitWindow(screenWidth, screenHeight, "BREAKOUT");

		Init();

		while (!WindowShouldClose()){
			change();

		}
		CloseWindow();
	}

	static void change() {

		switch (Screens) {
		case Menu:
		//	menu::menuUpdate();
			gameplay::gameplayUpdate();
			break;
		case Game:
			break;
		case End:
			break;
		}
	}

	void Init() {

		menu::menuInit();
		gameplay::gameplayInit();
	}
}