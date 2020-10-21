
#ifndef SC_TITLE_H
#define SC_TITLE_H

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
	// ゲーム処理
	// Execute内で呼び出し
	void Control();

	// 描画処理
	// Execute内で呼び出し
	void Draw();
};

#endif
