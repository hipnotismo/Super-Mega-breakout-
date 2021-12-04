#include "manager.h"

#include "raylib.h"

#include "Screens/Menu/menu.h"

namespace gameManager {

	GameScreen Screens;

	const int screenWidth = 800;
	const int screenHeight = 450;

	static void change();

	void manger() {

		InitWindow(screenWidth, screenHeight, "BREAKOUT");

		while (!WindowShouldClose()){
			change();

		}
		CloseWindow();
	}

	static void change() {

		switch (Screens) {
		case Menu:
			menu::Update();
			break;
		case Game:
			break;
		case End:
			break;
		}
	}

}