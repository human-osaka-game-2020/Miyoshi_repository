
#ifndef SC_BASE_H
#define SC_BASE_H

// 各シーンの基盤
class SceneBase {
public:
	// コンストラクタ
	SceneBase();

	// デストラクタ
	~SceneBase();

	/// <summary>
	/// 現在のシーンを取得する
	/// </summary>
	/// <returns>現在のシーン</returns>
	static enum SceneList GetCurrentScene();

	/// <summary>
	/// 現在のシーンを削除する
	/// :アプリの終了前に呼び出す
	/// </summary>
	static void ReleaseScene();

	/// <summary>
	/// シーンがnullの場合は作成する
	/// :ExecuteSceneの前に呼び出す
	/// </summary>
	static void CreateScene();

	/// <summary>
	/// 現在のシーンで処理を行う
	/// :CreateSceneの後に呼び出す
	/// </summary>
	static void ExecuteScene();

	/// <summary>
	/// ExecuteSceneで変化があった場合は現在のシーンをdeleteする
	/// :ExecuteSceneの後に呼び出す
	/// </summary>
	static void ReleaseCurrentScene();

private:
	virtual void Execute() = 0;
	virtual void Control() = 0;
	virtual void Draw() = 0;

protected:
	/// <summary>
	/// フェードイン、フェードアウトで同じ引数を使用
	/// </summary>
	/// <param name="destinationScene">フェードアウト後に移動するシーン</param>
	/// <param name="fadePower">フェードの強さ</param>
	/// <param name="fadeColor">フェードの色</param>
	/// <param name="waitTime">待ち時間</param>
	void SceneFade( SceneList destinationScene, int fadePower, int fadeColor, int waitTime = 0 );
	
	/// <summary>
	/// フェードイン、フェードアウトで別の引数を使用
	/// </summary>
	/// <param name="destinationScene">フェードアウト後に移動するシーン</param>
	/// <param name="inPower">フェードインの強さ</param>
	/// <param name="outPower">フェードアウトの強さ</param>
	/// <param name="inColor">フェードインの色</param>
	/// <param name="outColor">フェードアウトの色</param>
	/// <param name="inWaitTime">フェードイン前に待つ時間(フレーム)</param>
	/// <param name="outWaitTime">フェードアウト後に待つ時間(フレーム)</param>
	void SceneFade( SceneList destinationScene, int inPower, int outPower, int inColor, int outColor, int inWaitTime = 0, int outWaitTime = 0 );

protected:
	static FadeMode fadeMode;		// 現在のフェードの状態
	static SceneList currentScene;	// 現在のシーン

private:
	static SceneBase* sc_title;
	static SceneBase* sc_onPlay;
	static SceneBase* sc_result;
	static SceneBase* pSceneBase[3];
	static int previousScene;

};

#endif // !SC_BASE_H
