
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "../Common.h"
#include "../Singleton.h"

#include "../Character/Player.h"

class GameManager : public Singleton<GameManager>{
public:
	GameManager(){};
	~GameManager(){};
};

#endif // !GAME_MANAGER_H
