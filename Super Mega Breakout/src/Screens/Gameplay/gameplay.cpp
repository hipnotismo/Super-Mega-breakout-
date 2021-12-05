#include "gameplay.h"
#include "Structs/player.h"

#include <iostream>

namespace gameplay {

	static void gameplayDraw();
	Player player;

	void gameplayInit() {
		player.pos = { static_cast<float>(GetScreenWidth())/10,static_cast<float>(GetScreenHeight())/10};
		player.size = { static_cast<float>(GetScreenWidth()) / 10,static_cast<float>(GetScreenHeight()) / 10 };
	}

	void gameplayUpdate() {
		gameplayDraw();
	}

	void gameplayDraw() {
		ClearBackground(RAYWHITE);

		DrawRectangle(static_cast<int>(player.pos.x), static_cast<int>(player.pos.y), static_cast<int>(player.size.y), static_cast<int>(player.size.x), BLACK);

		EndDrawing();
	}

}