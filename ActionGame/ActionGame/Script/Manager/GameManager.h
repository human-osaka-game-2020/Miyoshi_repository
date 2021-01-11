
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "../Common.h"
#include "../Singleton.h"

#include "../Character/Player.h"

class GameManager : public Singleton<GameManager>{
public:
	GameManager();
	~GameManager(){};

public:
	Player* GetPlayerData() { return &player; }
	void SetPlayerData( CharacterData data ) { player = data; }

private:
	Player player;
};

#endif // !GAME_MANAGER_H
