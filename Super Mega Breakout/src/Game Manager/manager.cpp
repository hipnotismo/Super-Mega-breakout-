#include "manager.h"

#include "raylib.h"

namespace gameManager {

	GameScreen Screens;

	static void change();

	void manger() {

		while (!WindowShouldClose()){
			change();

		}
		CloseWindow();
	}

	static void change() {

		switch (Screens) {
		case Menu:
			break;
		case Game:
			break;
		case End:
			break;
		}
	}

}