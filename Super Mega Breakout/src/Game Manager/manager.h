#ifndef GameManager_H
#define GameManager_H

#include <iostream>

namespace gameManager {

	enum GameScreen{
		Menu = 0,
		Game,
		Credits,
		End
	};

	extern GameScreen Screens;

	void manger();
	void Init();
}
#endif // GameManger_H
