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
		//init player
		player.size = { static_cast<float>(GetScreenWidth()) / 6,static_cast<float>(GetScreenHeight()) / 15 };
		player.pos = { static_cast<float>(GetScreenWidth()) / 2 - player.size.x/2,static_cast<float>(GetScreenHeight()) - player.size.y - 10 };
		player.speed = 420;
		//init ball
		ball.radius = 20;
		ball.pos = {player.pos.x + (player.size.x/2),player.pos.y - ball.radius};
		ball.active = false;
		ball.speed = {0,0};
	}


	void gameplayInput() {

		if (player.pos.x > 0) {
			if (IsKeyDown(KEY_LEFT)) {
				player.pos.x -= GetFrameTime() * player.speed;
				if (ball.active == false) {
					ball.pos.x -= GetFrameTime() * player.speed;

				}
			}
		}

		if (player.pos.x + player.size.x <= GetScreenWidth()) {
			if (IsKeyDown(KEY_RIGHT)) {
				player.pos.x += GetFrameTime() * player.speed;
				if (ball.active == false) {
					ball.pos.x += GetFrameTime() * player.speed;
				}
			}
		}

		if (!ball.active) {
			if (IsKeyPressed(KEY_SPACE)) {
				ball.active = !ball.active;
				ball.speed = { 300 , 300 };
			}
		}

		if (ball.active) {
			ball.pos.x += ball.speed.x * GetFrameTime();
			ball.pos.y -= ball.speed.y * GetFrameTime();

		}
	}

	void gameplayDraw() {
		ClearBackground(RAYWHITE);

		DrawRectangle(static_cast<int>(player.pos.x), static_cast<int>(player.pos.y), static_cast<int>(player.size.x), static_cast<int>(player.size.y), BLACK);
		DrawCircleV(ball.pos,ball.radius,RED);
		EndDrawing();
	}

}