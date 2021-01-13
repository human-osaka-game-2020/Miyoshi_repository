
#ifndef SC_ONPLAY_H
#define SC_ONPLAY_H

#include "../Common.h"
#include "../Function/Function.h"
#include "SceneBase.h"
#include "../Function/Gauge.h"
#include "../Character/Player.h"

// ゲーム中のシーン
class GameScene : public SceneBase {
public:
	// コンストラクタ
	GameScene();

	// デストラクタ
	~GameScene();

	// メインループで呼び出すもの
	void Execute();

private:
	// ゲーム処理
	// Execute内で呼び出し
	void Control();

	// 描画処理
	// Execute内で呼び出し
	void Draw();

	Player* GetPlayerData() { return player; }
	void SetPlayerData( CharacterData data ) { *player = data; }

private:
	static std::vector<Gauge> gaugeList;
	Player* player;

};

#endif
