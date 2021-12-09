#include "controls.h"

#include "Game Manager/manager.h"
namespace controls {
	static void controlsDraw();

	static Vector2 mousePoint;

	void controlsInit() {

		rec1CO.x = static_cast<float>(GetScreenWidth()) / 15 - 50;
		rec1CO.y = static_cast<float>(GetScreenHeight()) / 15;
		rec1CO.height = 50;
		rec1CO.width = 100;
	}

	void controlsUpdate() {

		controlsDraw();
		mousePoint = GetMousePosition();

		if (CheckCollisionPointRec(mousePoint, rec1CO)) {

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

				gameManager::Screens = gameManager::GameScreen::Menu;

			}
		}
	}

	void controlsDraw() {
		ClearBackground(RAYWHITE);

		DrawRectangle(static_cast<int>(rec1CO.x), static_cast<int>(rec1CO.y), static_cast<int>(rec1CO.width), static_cast<int>(rec1CO.height), BLACK);
		DrawText("atras", static_cast<int>(rec1CO.x) + 18, static_cast<int>(rec1CO.y) + 10, 20, WHITE);

		DrawText("Made by: Martin Concetti", static_cast<int>(GetScreenWidth() / 2), 200, 30, BLACK);
		DrawText("Using raylib", static_cast<int>(GetScreenWidth() / 2), 300, 30, BLACK);
		DrawText("V0.8", static_cast<int>(GetScreenWidth() / 2), 400, 30, BLACK);

		EndDrawing();

	}

}