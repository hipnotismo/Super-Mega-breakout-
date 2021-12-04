#include "menu.h"

namespace menu {

	void menuInit() {

		rec1.x = static_cast<float>(GetScreenWidth()) / 2 - 50;
		rec1.y = static_cast<float>(GetScreenHeight()) / 2 - 80;
		rec1.height = 50;
		rec1.width = 100;
	}

	void menuDraw() {
		ClearBackground(RAYWHITE);

		DrawRectangle(static_cast<int>(rec1.x), static_cast<int>(rec1.y), static_cast<int>(rec1.width), static_cast<int>(rec1.height), BLACK);

		EndDrawing();

	}

	void menuUpdate() {

		menuDraw();
	}
}