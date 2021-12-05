#ifndef Gameplay_H
#define Gameplay_H

#include "raylib.h"

#include "Structs/player.h"
#include "Structs/ball.h"
#include <iostream>

namespace gameplay {

	void gameplayUpdate();
	void gameplayInit();
	void gameplayInput();
}
#endif // Gameplay_H

//	std::cout << ball.active << std::endl;

