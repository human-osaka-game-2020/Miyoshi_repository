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

	SetGraphMode ( WINDOW_WIDTH, WINDOW_HEIGHT, 32, 60 );
	ChangeWindowMode ( true ); // ウィンドウモードに変更

	if ( DxLib_Init () == -1 )	// ＤＸライブラリ初期化処理
	{
		return -1; // エラーが起きたら直ちに終了
	}

	// グラフィックの描画先を裏画面にセット
	SetDrawScreen ( DX_SCREEN_BACK );

	// メインループ
	while ( UpdateKeyState() == 0 )
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

	if ( fadeMode == Mode_FadeNone ) {
		if ( CheckHitKey( KEY_INPUT_SPACE ) ) {
			fadeMode = Mode_FadeIn;
		}
		else if ( CheckHitKey( KEY_INPUT_RETURN ) ) {
			fadeMode = Mode_FadeOut;
		}
	}

	if ( GetKeyStatus( KEY_INPUT_A ) == 0 ) {
		DrawString( 10, 100, "押されていない", COLOR_WHITE );
	}
	else if ( GetKeyStatus( KEY_INPUT_A ) == 1 ) {
		DrawString( 1000, 100, "押された", COLOR_GREEN );
	}
	else if ( GetKeyStatus( KEY_INPUT_A ) == -1 ) {
		DrawString( 1000, 100, "離された", COLOR_RED );
	}
	else {
		DrawFormatString( 10, 100, COLOR_BLUE, "押されている : %d フレーム", GetKeyStatus(KEY_INPUT_A) );
	}
}

void DrawProcessing() {
	player.Draw();

	if ( fadeMode == Mode_FadeIn ) {
		if ( FadeIn( 255 / 60, COLOR_BLUE, 30 ) ) {
			fadeMode = Mode_FadeNone;
		}
	}
	else if ( fadeMode == Mode_FadeOut ) {
		if ( FadeOut( 255 / 60, COLOR_RED, 90 ) ) {
			fadeMode = Mode_FadeNone;
		}
	}
}
