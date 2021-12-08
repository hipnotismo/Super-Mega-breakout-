#ifndef GameManager_H
#define GameManager_H

namespace gameManager {

	enum class GameScreen{
		Menu = 0,
		Game,
		Credits,
		End
	};

	extern GameScreen Screens;

	void run();
	void Init();
}
#endif // GameManger_H
