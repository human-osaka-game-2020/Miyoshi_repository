#include "Script/Header/Common.h"

// ゲーム処理
void GameProcessing ();
// 描画処理
void DrawProcessing ();

Player player;

FadeMode fadeMode = Mode_FadeNone;

// プログラムは WinMain から始まります
int WINAPI WinMain ( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	SetOutApplicationLogValidFlag(false);

	SetGraphMode ( WINDOW_WIDTH, WINDOW_HEIGHT, 32, 60 );
	ChangeWindowMode ( true ); // ウィンドウモードに変更

	if ( DxLib_Init () == -1 )	// ＤＸライブラリ初期化処理
	{
		return -1; // エラーが起きたら直ちに終了
	}

	// グラフィックの描画先を裏画面にセット
	SetDrawScreen ( DX_SCREEN_BACK );

	// メインループ
	while ( UpdateKeyState() == 0 && UpdateMouseButtonState() == 0 )
	{
		// 画面を初期化
		ClearDrawScreen ();

		GameProcessing ();
		DrawProcessing ();

		// -1 が返ってきたらループを抜ける
		if ( ProcessMessage () < 0 ) break;
		// もしＥＳＣキーが押されていたらループから抜ける
		if ( CheckHitKey ( KEY_INPUT_ESCAPE ) ) break;

		// 裏画面の内容を表画面にコピーする
		ScreenFlip ();
	}

	DxLib_End ();				// ＤＸライブラリ使用の終了処理

	return 0;					// ソフトの終了
}

void GameProcessing () {
	player.Moving();

	if ( GetKeyStatus( KEY_INPUT_RETURN ) == InputState::Pressed ) {
		KeyInputInvalidSwitching( KEY_INPUT_A );
	}

	if ( GetKeyStatus( KEY_INPUT_SPACE ) == InputState::Pressed ) {
		MouseButtonInputInvalidSwitching( MOUSE_INPUT_LEFT );
	}

	if ( GetKeyStatus( KEY_INPUT_A ) == InputState::Invalid ) {
		DrawString( 10, 100, "入力は無効", COLOR_WHITE );
	}
	else if ( GetKeyStatus( KEY_INPUT_A ) == InputState::NotPressed ) {
		DrawString( 10, 100, "押されていない", COLOR_WHITE );
	}
	else if ( GetKeyStatus( KEY_INPUT_A ) == InputState::Pressed ) {
		DrawString( 1000, 100, "押された", COLOR_GREEN );
	}
	else if ( GetKeyStatus( KEY_INPUT_A ) == InputState::Released ) {
		DrawString( 1000, 100, "離された", COLOR_RED );
	}
	else {
		DrawFormatString( 10, 100, COLOR_BLUE, "押されている : %d フレーム", GetKeyStatus(KEY_INPUT_A) );
	}

	if ( GetMouseButtonStatus( MOUSE_INPUT_LEFT ) == InputState::Invalid ) {
		DrawString( 10, 300, "入力は無効", COLOR_WHITE );
	}
	else if ( GetMouseButtonStatus( MOUSE_INPUT_LEFT ) == InputState::NotPressed ) {
		DrawString( 10, 300, "押されていない", COLOR_WHITE );
	}
	else if ( GetMouseButtonStatus( MOUSE_INPUT_LEFT ) == InputState::Pressed ) {
		DrawString( 1000, 300, "押された", COLOR_GREEN );
	}
	else if ( GetMouseButtonStatus( MOUSE_INPUT_LEFT ) == InputState::Released ) {
		DrawString( 1000, 300, "離された", COLOR_RED );
	}
	else {
		DrawFormatString( 10, 300, COLOR_BLUE, "押されている : %d フレーム", GetMouseButtonStatus( MOUSE_INPUT_LEFT ) );
	}
}

void DrawProcessing() {
	player.Draw();
}
