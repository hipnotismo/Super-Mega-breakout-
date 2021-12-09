#include "credits.h"

#include "raylib.h"

#include "Game Manager/manager.h"

namespace credits {
	static void creditsDraw();

	static Vector2 mousePoint;
	static Rectangle rec1CR;

	void creditsInit() {
		rec1CR.width = static_cast<float>(GetScreenWidth()) / 10;
		rec1CR.height = static_cast<float>(GetScreenHeight()) / 10;
		rec1CR.x = static_cast<float>(GetScreenWidth()) / 9 - rec1CR.width;
		rec1CR.y = static_cast<float>(GetScreenHeight()) / 9 - rec1CR.height;
	}

	void creditsUpdate() {
		creditsDraw();
		mousePoint = GetMousePosition();

		if (CheckCollisionPointRec(mousePoint, rec1CR)) {
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				gameManager::Screens = gameManager::GameScreen::Menu;
			}
		}
	}

	void creditsDraw() {
		ClearBackground(RAYWHITE);

		DrawRectangle(static_cast<int>(rec1CR.x), static_cast<int>(rec1CR.y), static_cast<int>(rec1CR.width), static_cast<int>(rec1CR.height), BLACK);
		DrawText("atras", static_cast<int>(rec1CR.x) + 18, static_cast<int>(rec1CR.y) + 10, 20, WHITE);

		DrawText("Made by: Martin Concetti", static_cast<int>(GetScreenWidth() /2), 200, 30, BLACK);
		DrawText("Using raylib", static_cast<int>(GetScreenWidth() /2), 300, 30, BLACK);
		DrawText("V0.9.1", static_cast<int>(GetScreenWidth() /2), 400, 30, BLACK);
		DrawText("Sound effects made in sfxr, music from pixabay", 5, 500, 30, BLACK);

		EndDrawing();
	}
}