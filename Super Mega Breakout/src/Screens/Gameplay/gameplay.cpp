#include "gameplay.h"
#include "Structs/player.h"

#include <iostream>

namespace gameplay {

	static void gameplayDraw();
	Player player;

	void gameplayInit() {
		player.size = { static_cast<float>(GetScreenWidth()) / 6,static_cast<float>(GetScreenHeight()) / 15 };
		player.pos = { static_cast<float>(GetScreenWidth()) / 2 - player.size.x/2,static_cast<float>(GetScreenHeight()) - player.size.y - 10 };
		std::cout<< player.size.x / 2 << std::endl;
	}

	void gameplayUpdate() {
		gameplayDraw();


	}

	void gameplayDraw() {
		ClearBackground(RAYWHITE);

		DrawRectangle(static_cast<int>(player.pos.x), static_cast<int>(player.pos.y), static_cast<int>(player.size.x), static_cast<int>(player.size.y), BLACK);

		EndDrawing();
	}

}