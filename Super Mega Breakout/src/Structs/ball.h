#ifndef Ball_H
#define Ball_H

#include "raylib.h"

namespace ball {
	struct Ball {
		Vector2 pos;
		Vector2 speed;
		int radius;
		bool active;
	};
}
#endif