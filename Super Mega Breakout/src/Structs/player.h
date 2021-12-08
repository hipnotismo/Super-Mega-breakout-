#ifndef Player_H
#define Player_H

#include "raylib.h"

namespace player {
	struct Player {
		Vector2 pos;
		Vector2 size;
		int speed;
		int lifes;
	};
}
#endif 