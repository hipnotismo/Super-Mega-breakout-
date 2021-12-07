#include "menu.h"
#include <iostream>

namespace menu {
	static void menuDraw();
	static Vector2 mousePoint;

	void menuInit() {

		rec1M.height = static_cast<float>(GetScreenHeight()) / 10;
		rec1M.width = static_cast<float>(GetScreenWidth()) / 10;
		rec1M.x = static_cast<float>(GetScreenWidth()) / 9 - rec1M.width;
		rec1M.y = static_cast<float>(GetScreenHeight()) / 9 - rec1M.height;
		std::cout << rec1M.y << std::endl;

		rec2M.height = static_cast<float>(GetScreenHeight()) / 10;
		rec2M.width = static_cast<float>(GetScreenWidth()) / 10;
		rec2M.x = static_cast<float>(GetScreenWidth()) / 9 - rec1M.width;
		rec2M.y = static_cast<float>(GetScreenHeight()) / 9 + rec1M.height;

		rec3M.height = static_cast<float>(GetScreenHeight()) / 10;
		rec3M.width = static_cast<float>(GetScreenWidth()) / 10;
		rec3M.x = static_cast<float>(GetScreenWidth()) / 9 - rec1M.width;
		rec3M.y = static_cast<float>(GetScreenHeight()) / 9 + rec1M.height*3;
	}

	void menuUpdate() {

		menuDraw();

		mousePoint = GetMousePosition();

		if (CheckCollisionPointRec(mousePoint, rec1M)) {

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

				gameManager::Screens = gameManager::Game;

			}
		}

		if (CheckCollisionPointRec(mousePoint, rec2M)) {

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {

				gameManager::Screens = gameManager::Credits;

			}
		}
	}

	void menuDraw() {
		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawRectangle(static_cast<int>(rec1M.x), static_cast<int>(rec1M.y), static_cast<int>(rec1M.width), static_cast<int>(rec1M.height), BLACK);
		DrawRectangle(static_cast<int>(rec2M.x), static_cast<int>(rec2M.y), static_cast<int>(rec2M.width), static_cast<int>(rec2M.height), BLACK);
		DrawRectangle(static_cast<int>(rec3M.x), static_cast<int>(rec3M.y), static_cast<int>(rec3M.width), static_cast<int>(rec3M.height), BLACK);

		DrawText("Play", static_cast<int>(rec1M.x) + 18, static_cast<int>(rec1M.y) + 10, 20, WHITE);
		DrawText("Credits", static_cast<int>(rec2M.x) + 18, static_cast<int>(rec2M.y) + 10, 20, WHITE);
		DrawText("Exit", static_cast<int>(rec3M.x) + 18, static_cast<int>(rec3M.y) + 10, 20, WHITE);

		DrawText("SUPER", static_cast<float>(GetScreenWidth() - 400) , 100,50,RED);
		DrawText("MEGA", static_cast<float>(GetScreenWidth() - 400),200,50,LIME);
		DrawText("SOKOBA", static_cast<float>(GetScreenWidth() - 400), 300, 50, SKYBLUE);

		DrawText("V0.5", static_cast<float>(GetScreenWidth() - 100), static_cast<float>(GetScreenHeight())-40, 20, SKYBLUE);

		EndDrawing();

	}

}