﻿
#include "Common.h"
#include "Manager/GameManager.h"
#include "Manager/SpriteManager.h"

#include "Scene/SceneBase.h"

// プログラムは WinMain から始まります
int WINAPI WinMain ( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	SetOutApplicationLogValidFlag( false );

	SetGraphMode ( WINDOW_WIDTH, WINDOW_HEIGHT, 32, 60 );
	ChangeWindowMode ( true ); // ウィンドウモードに変更
	SetBackgroundColor( 128, 255, 255 );

	if ( DxLib_Init () == -1 )	// ＤＸライブラリ初期化処理
	{
		return -1; // エラーが起きたら直ちに終了
	}

	// グラフィックの描画先を裏画面にセット
	SetDrawScreen ( DX_SCREEN_BACK );

	GameManager::CreateInstance();
	SpriteManager::CreateInstance();

	GameManager::GetInstance()->LoadStage();

	// メインループ
	while ( true )
	{
		// 画面を初期化
		ClearDrawScreen();

		if( UpdateKeyState() != 0 ) break;
		if( UpdateMouseButtonState() != 0 ) break;

		SceneBase::CreateScene();
		SceneBase::ExecuteScene();
		SceneBase::ReleaseCurrentScene();

		// -1 が返ってきたらループを抜ける
		if( ProcessMessage() < 0 ) break;
		// もしＥＳＣキーが押されていたらループから抜ける
		if( CheckHitKey( KEY_INPUT_ESCAPE ) ) break;

		// 裏画面の内容を表画面にコピーする
		ScreenFlip();
	}

	SpriteManager::DestroyInstance();
	GameManager::DestroyInstance();

	SceneBase::ReleaseScene();
	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;					// ソフトの終了
}
