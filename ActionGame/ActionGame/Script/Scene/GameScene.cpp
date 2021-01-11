
#include "GameScene.h"
#include "../Manager/GameManager.h"
#include "../Character/Player.h"

std::vector<Gauge> GameScene::gaugeList;

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

	for( int i = 0; i < gaugeList.size(); i++ ){
		gaugeList.back().Control();
	}

	if ( CheckHitKey( KEY_INPUT_2 ) ) {
		fadeMode = FadeMode::Out;
	}
}

void GameScene::Draw() {
	DrawString( 10, 10, "OnPlay", Color::red );
	DrawString( 10, 30, "Press 2 to Result Scene", Color::red );

	GameManager::GetInstance()->GetPlayerData()->Draw();


	for( int i = 0; i < gaugeList.size(); i++ ){
		gaugeList.back().Draw();
	}

	SceneFade( SceneList::Result, 255 / 120, 255 / 60, Color::white, Color::blue, 30 );
}
