#include "controls.h"

#include "Game Manager/manager.h"
namespace controls {
	static void controlsDraw();

	static Vector2 mousePoint;
	static Rectangle rec1CO;

	void controlsInit() {

		rec1CO.width = static_cast<float>(GetScreenWidth()) / 10;
		rec1CO.height = static_cast<float>(GetScreenHeight()) / 10;
		rec1CO.x = static_cast<float>(GetScreenWidth()) / 9 - rec1CO.width;
		rec1CO.y = static_cast<float>(GetScreenHeight()) / 9 - rec1CO.height;
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

		DrawText("Move the player with the left and right arrows", static_cast<int>(GetScreenWidth() / 2), 200, 30, BLACK);
		DrawText("Press espace to lunch the ball", static_cast<int>(GetScreenWidth() / 2), 300, 30, BLACK);
		DrawText("Press P for pause", static_cast<int>(GetScreenWidth() / 2), 400, 30, BLACK);

		EndDrawing();

	}

}