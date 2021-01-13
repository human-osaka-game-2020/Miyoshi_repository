
#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "../Common.h"
#include "../Singleton.h"

#include "../Character/Player.h"

struct SaveState{
	float x;
	float y;
	int stageNumber;
};

class GameManager : public Singleton<GameManager>{
public:
	GameManager(){};
	~GameManager(){};

public:
	// ステージをテキストファイルから読み込む
	void LoadStage();

	std::vector<std::vector<ObjectTag>> GetStageData( int stageNumber_ );

	int GetStageMax() const { return stageData.size(); }

	// セーブ
	void DataSaving( SaveState data_ );

	// ロード
	SaveState DataLoading();

private:
	std::vector<std::vector<std::vector<ObjectTag>>> stageData;

};

#endif // !GAME_MANAGER_H
