#include "gameplay.h"


#include "raylib.h"

#include "Structs/player.h"
#include "Structs/ball.h"
#include "Structs/brick.h"
#include "Game Manager/manager.h"

namespace gameplay {

	static void gameplayDraw();

	const int files = 10;
	const int rows = 3;

	bool pause = false;

	player::Player player;
	ball::Ball ball;
	brick::Brick brick[rows][files];


	void gameplayUpdate() {
		gameplayDraw();
		gameplayInput();

		if (!pause) {
		if (ball.active) {
			ball.pos.x += ball.speed.x * GetFrameTime();
			ball.pos.y += ball.speed.y * GetFrameTime();
		}
		else {
			ball.speed = { player.pos.x + (player.size.x / 2),player.pos.y - ball.radius };
		}

		//interaction with walls
		if ((ball.pos.x - ball.radius) <= 0) {
			ball.speed.x *= -1;
		}

		if ((ball.pos.x + ball.radius) >= GetScreenWidth()) {
			ball.speed.x *= -1;
		}

		if (ball.pos.y - ball.radius <= 0) {
			ball.speed.y *= -1;
		}

		if (ball.pos.y + ball.radius >= GetScreenHeight()) {
			ball.speed = { 0,0 };
			ball.pos = { player.pos.x + (player.size.x / 2),player.pos.y - ball.radius };
			ball.active = !ball.active;

		}

		//interaction with player
		if (CheckCollisionCircleRec(ball.pos, static_cast<float>(ball.radius), { player.pos.x, player.pos.y,player.size.x, player.size.y })) {
			if (ball.speed.y > 0) {
				ball.speed.y *= -1;
				ball.speed.x = (ball.pos.x - player.pos.x) / (player.size.x / 2) * 5;
			}
		}

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < files; j++) {
				if (brick[i][j].active) {
					if (CheckCollisionCircleRec(ball.pos, static_cast<float>(ball.radius), { brick[i][j].pos.x,brick[i][j].pos.y,brick[i][j].size.x,brick[i][j].size.y })) {
						brick[i][j].active = false;
						ball.speed.y *= -1;
					}
				}
			}
		}
	}
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
		//init bricks
	
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < files; j++){
				brick[i][j].pos = { static_cast<float>(GetScreenWidth()) / 10 + (GetScreenWidth()/10 * (j-1)),static_cast<float>(GetScreenHeight()) / 10 + (GetScreenHeight()/10 * (i-1))};
				brick[i][j].size = { static_cast<float>(GetScreenWidth()) / 10 ,static_cast<float>(GetScreenHeight()) / 10  };
				brick[i][j].active = true;
			}
		}
		

	}


	void gameplayInput() {

		if (IsKeyPressed(KEY_P)) pause = !pause;

		if(!pause) {
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

		//ball activation
		if (!ball.active) {
			if (IsKeyPressed(KEY_SPACE)) {
				ball.active = !ball.active;
				ball.speed = { -100 , -300 };
			}
		}
		}
		else {
			if (IsKeyPressed(KEY_ENTER)) {
				pause = false;
				gameManager::Screens = gameManager::GameScreen::Menu;
				gameplayInit();

			}
		}
	}

	void gameplayDraw() {
		BeginDrawing();
		ClearBackground(RAYWHITE);

		if (!pause) {
			DrawRectangle(static_cast<int>(player.pos.x), static_cast<int>(player.pos.y), static_cast<int>(player.size.x), static_cast<int>(player.size.y), BLACK);
			DrawCircleV(ball.pos, static_cast<float>(ball.radius), RED);
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < files; j++) {
					if (brick[i][j].active) {
						DrawRectangle(static_cast<int>(brick[i][j].pos.x), static_cast<int>(brick[i][j].pos.y), static_cast<int>(brick[i][j].size.x), static_cast<int>(brick[i][j].size.y), BLACK);
					}
				}
			}
		}
		else {
			DrawText("Press P to play again", static_cast<int>(GetScreenWidth()) / 9, static_cast<int>(GetScreenHeight()) / 9, 40, RED);
			DrawText("Press enter to go to menu", static_cast<int>(GetScreenWidth()) / 9, static_cast<int>(GetScreenHeight()) / 6, 40, RED);


		}
		EndDrawing();
	}

}