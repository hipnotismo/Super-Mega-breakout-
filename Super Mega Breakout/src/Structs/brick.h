#ifndef Brick_H
#define Brick_H

#include "raylib.h"

namespace breakout {
	namespace brick {
		struct Brick {
			Vector2 pos;
			Vector2 size;
			bool active;
			int color;
		};
	}
}
#endif 