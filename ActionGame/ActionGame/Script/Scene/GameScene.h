
#ifndef SC_ONPLAY_H
#define SC_ONPLAY_H

#include "../Common.h"
#include "../Function/Function.h"
#include "SceneBase.h"
#include "../Function/Gauge.h"
#include "../Character/Player.h"
#include "../Object/ObjectBase.h"
#include "../Manager/SpriteManager.h"
#include "../Manager/SoundManager.h"
#include "../Manager/GameManager.h"

// ゲーム中のシーン
class GameScene : public SceneBase {
public:
	// コンストラクタ
	GameScene();

	// デストラクタ
	~GameScene();

	// メインループで呼び出すもの
	void Execute();

	// 次のステージへ
	void NextStage();

private:
	// ゲーム処理
	// Execute内で呼び出し
	void Control();

	// 描画処理
	// Execute内で呼び出し
	void Draw();

	Player* GetPlayerData() { return player; }
	void SetPlayerData( CharacterData data ) { *player = data; }

	// 死んだときとかに呼ぶやつ
	void Reset();

	// 衝突判定
	void Collision();

	void SceneDataLoad();

private:
	static std::vector<Gauge> gaugeList;
	Player* player;
	static int stageNumber;
	static std::vector<std::vector<ObjectBase*>> stageData;

	SpriteManager* sprIns;
	SoundManager* sndIns;
	GameManager* gameIns;
};

#endif
