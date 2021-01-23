
#ifndef SC_TITLE_H
#define SC_TITLE_H

#include "../Common.h"
#include "../Function/Function.h"
#include "SceneBase.h"
#include "../Manager/SpriteManager.h"
#include "../Manager/SoundManager.h"

// タイトルシーン
class TitleScene : public SceneBase {
public:
	// コンストラクタ
	TitleScene();

	// デストラクタ
	~TitleScene();

	// メインループで呼び出すもの
	void Execute();

private:
	enum class Menu{
		NewGame_m,	// 最初から
		Continue_m	// つづきから
	};

	// ゲーム処理
	// Execute内で呼び出し
	void Control();

	// 描画処理
	// Execute内で呼び出し
	void Draw();

	bool SelectMenu();

	Menu currentSelection;
	int pointerRadius;

	SpriteManager* sprIns;
	SoundManager* sndIns;
};

#endif
