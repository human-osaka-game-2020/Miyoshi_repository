
#ifndef SC_RESULT_H
#define SC_RESULT_H

#include "../Common.h"
#include "../Function/Function.h"
#include "SceneBase.h"
#include "../Manager/SpriteManager.h"
#include "../Manager/SoundManager.h"
#include "../Manager/GameManager.h"

// リザルトシーン
class ResultScene : public SceneBase {
public:
	// コンストラクタ
	ResultScene();

	// デストラクタ
	~ResultScene();

	// メインループで呼び出すもの
	void Execute();

private:
	// ゲーム処理
	// Execute内で呼び出し
	void Control();

	// 描画処理
	// Execute内で呼び出し
	void Draw();

	SpriteManager* sprIns;
	SoundManager* sndIns;
	GameManager* gameIns;
};

#endif
