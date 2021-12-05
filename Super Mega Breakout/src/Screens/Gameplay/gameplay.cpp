#include "gameplay.h"

namespace gameplay {

	static void gameplayDraw();
	Player player;
	Ball ball;


	void gameplayUpdate() {
		gameplayDraw();
		gameplayInput();

	}

	void gameplayInit() {
		player.size = { static_cast<float>(GetScreenWidth()) / 6,static_cast<float>(GetScreenHeight()) / 15 };
		player.pos = { static_cast<float>(GetScreenWidth()) / 2 - player.size.x/2,static_cast<float>(GetScreenHeight()) - player.size.y - 10 };
		player.speed = 420;
		ball.radius = 10;
		ball.pos = {player.pos.x + (player.size.x/2),player.pos.y - ball.radius};

	}


	void gameplayInput() {

		if (player.pos.x > 0) {
			if (IsKeyDown(KEY_LEFT)) player.pos.x -= GetFrameTime() * player.speed;
		}

		if (player.pos.x + player.size.x <= GetScreenWidth()) {
			if (IsKeyDown(KEY_RIGHT)) player.pos.x += GetFrameTime() * player.speed;
		}
	}

	void gameplayDraw() {
		ClearBackground(RAYWHITE);

		DrawRectangle(static_cast<int>(player.pos.x), static_cast<int>(player.pos.y), static_cast<int>(player.size.x), static_cast<int>(player.size.y), BLACK);
		DrawCircleV(ball.pos,ball.radius,RED);
		EndDrawing();
	}

}