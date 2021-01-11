
#include "GameScene.h"
#include "../Manager/GameManager.h"
#include "../Character/Player.h"

GameScene::GameScene() {

}

GameScene::~GameScene() {

}

void GameScene::Execute() {
	Control();
	Draw();
}

void GameScene::Control() {
	if ( fadeMode != FadeMode::None ) return;

	GameManager::GetInstance()->GetPlayerData()->Move();

	if ( CheckHitKey( KEY_INPUT_2 ) ) {
		fadeMode = FadeMode::Out;
	}

}

void GameScene::Draw() {
	DrawString( 10, 10, "OnPlay", COLOR_RED );
	DrawString( 10, 30, "Press 2 to Result Scene", COLOR_RED );

	GameManager::GetInstance()->GetPlayerData()->Draw();

	SceneFade( SceneList::Result, 255 / 120, 255 / 60, COLOR_WHITE, COLOR_BLUE, 30 );
}
