
#ifndef SC_ONPLAY_H
#define SC_ONPLAY_H

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
};

#endif
