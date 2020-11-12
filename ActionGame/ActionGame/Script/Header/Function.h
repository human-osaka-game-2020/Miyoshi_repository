#ifndef FUNCTION_H
#define FUNCTION_H

enum FadeMode {
	Mode_FadeNone,
	Mode_FadeIn,
	Mode_FadeOut
};

// キーボード、マウスの入力状態
enum InputState {
	Invalid,		// 無効
	NotPressed,		// 押されていない
	Pressed,		// 押された瞬間
	Pressing,		// 押している
	Released		// 離した瞬間
};

// マウスボタンの入力状態を調べる範囲
const int MOUSEBUTTON_UPDATE_RANGE = 5;

/// <summary>
/// フェード処理の中身
/// </summary>
/// <param name="fademode">フェードの種類</param>
/// <param name="fadePower">フェードの速さ</param>
/// <param name="fadeColor">フェードする色</param>
/// <param name="waitTime">フェードの待ち時間(フレーム)</param>
/// <returns>true == 処理終了, false == 処理中</returns>
bool Fade( FadeMode fademode, unsigned int fadePower, int fadeColor, int waitTime );

/// <summary>
/// フェードイン
/// </summary>
/// <param name="fadePower">フェードの速さ</param>
/// <param name="fadeColor">フェードインする前の色</param>
/// <param name="waitTime">フェードが始まる前に待つ時間(フレーム)</param>
/// <returns>true == 処理終了, false == 処理中</returns>
bool FadeIn( unsigned int fadePower, int fadeColor = GetColor( 0, 0, 0 ), int waitTime = 0 );

/// <summary>
/// フェードアウト
/// </summary>
/// <param name="fadePower">フェードの速さ</param>
/// <param name="fadeColor">フェードアウトした後の色</param>
/// <param name="waitTime">フェードが終わった後に待つ時間(フレーム)</param>
/// <returns>true == 処理終了, false == 処理中</returns>
bool FadeOut( unsigned int fadePower, int fadeColor = GetColor( 0, 0, 0 ), int waitTime = 0 );

/// <summary>
/// キーの入力状態を更新する
/// :毎フレーム呼び出す
/// </summary>
/// <returns>0以外はエラー</returns>
int UpdateKeyState();

/// <summary>
/// キーの入力状態を取得する
/// </summary>
/// <param name="keyCode">入力状態を取得したいキーのキーコード</param>
/// <returns>InputStateで返す</returns>
InputState GetKeyStatus( int keyCode );

/// <summary>
/// キー入力の無効/有効切り替え
/// </summary>
/// <param name="keyCode">入力の無効/有効を切り替えたいキーのキーコード</param>
void ChangeKeyInputInvalidState( int keyCode );

/// <summary>
/// マウスボタンの入力状態を更新する
/// :毎フレーム呼び出す
/// </summary>
/// <returns>0以外はエラー</returns>
int UpdateMouseButtonState();

/// <summary>
/// マウスボタンの入力状態を取得する
/// </summary>
/// <param name="mouseButtonCode">入力状態を取得したいマウスボタンのコード</param>
/// <returns>InputStateで返す</returns>
InputState GetMouseButtonStatus( int mouseButtonCode );

/// <summary>
/// マウスボタン入力の無効/有効切り替え
/// </summary>
/// <param name="keyCode">入力の無効/有効を切り替えたいマウスボタンのコード</param>
void ChangeMouseInputInvalidState( int mouseButtonCode );

#endif // !FUNCTION_H
