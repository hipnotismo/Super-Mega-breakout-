#include "credits.h"

#include "Game Manager/manager.h"
namespace credits {
	static void creditsDraw();

	static Vector2 mousePoint;

	void creditsInit() {

		rec1.x = static_cast<float>(GetScreenWidth()) / 15 - 50;
		rec1.y = static_cast<float>(GetScreenHeight()) / 15;
		rec1.height = 50;
		rec1.width = 100;
	}

	void creditsUpdate() {

		creditsDraw();
		mousePoint = GetMousePosition();

		if (CheckCollisionPointRec(mousePoint, rec1)) {

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

				gameManager::Screens = gameManager::Menu;

			}
		}
	}

	void creditsDraw() {
		ClearBackground(RAYWHITE);

		DrawRectangle(static_cast<int>(rec1.x), static_cast<int>(rec1.y), static_cast<int>(rec1.width), static_cast<int>(rec1.height), BLACK);
		DrawText("atras", static_cast<int>(rec1.x) + 18, static_cast<int>(rec1.y) + 10, 20, WHITE);

		EndDrawing();

	}

}