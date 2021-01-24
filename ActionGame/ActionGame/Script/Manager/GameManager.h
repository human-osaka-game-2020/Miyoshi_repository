
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "../Common.h"
#include "../Singleton.h"
#include "../Character/Player.h"

struct SaveState{
	float x;
	float y;
	int stageNumber;
	int deathCount;
};

class GameManager : public Singleton<GameManager>{
public:
	GameManager() :deathCounter( 0 ){};
	~GameManager(){};

public:
	// ステージをテキストファイルから読み込む
	void LoadStage();

	std::vector<std::vector<ObjectTag>> GetStageData( int stageNumber_ );

	int GetStageMax() const { return stageData.size(); }

	// セーブ
	void Save( SaveState data_ );

	// ロード
	SaveState Load();

	void AddDeathCounter();
	int GetDeathCounter() const { return deathCounter; }
	void SetDeathCounter( int deathCounter_ ) { deathCounter = deathCounter_; }

private:
	std::vector<std::vector<std::vector<ObjectTag>>> stageData;
	int deathCounter;
};

#endif // !GAME_MANAGER_H
