#ifndef GameManager_H
#define GameManager_H


namespace gameManager {

	enum GameScreen{
		Menu = 0,
		Game,
		End
	};

	extern GameScreen Screens;

	void manger();
}
#endif // GameManger_H
