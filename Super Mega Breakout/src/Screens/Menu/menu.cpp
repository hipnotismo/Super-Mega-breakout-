#include "menu.h"

namespace menu {

	void init() {

		rec1.x = static_cast<float>(GetScreenWidth()) / 2 - 50;
		rec1.y = static_cast<float>(GetScreenHeight()) / 2 - 80;
		rec1.height = 50;
		rec1.width = 100;
	}

	void draw() {
		ClearBackground(RAYWHITE);

		DrawRectangle(static_cast<int>(rec1.x), static_cast<int>(rec1.y), static_cast<int>(rec1.width), static_cast<int>(rec1.height), BLACK);

		EndDrawing();

	}

	void Update() {

		draw();
	}
}