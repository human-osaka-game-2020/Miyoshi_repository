
#include "GameScene.h"
#include "../Manager/GameManager.h"
#include "../Manager/SpriteManager.h"

std::vector<Gauge> GameScene::gaugeList;

GameScene::GameScene() {
	SpriteManager::GetInstance()->LoadGraphHandle( GraphName::gPlayer );
	SpriteManager::GetInstance()->LoadGraphHandle( GraphName::gBullet );

	player = new Player( { { 0, 0 }, { 64, 64 }, 5, Direction::Right, SpriteManager::GetInstance()->GetGraphHandle( GraphName::gPlayer ) } );
}

GameScene::~GameScene() {

}

void GameScene::Execute() {
	Control();
	Draw();
}

void GameScene::Control() {
	if ( fadeMode != FadeMode::None ) return;

	player->Move();

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

	player->Draw();

	for( int i = 0; i < gaugeList.size(); i++ ){
		gaugeList.back().Draw();
	}

	SceneFade( SceneList::Result, 255 / 120, 255 / 60, Color::white, Color::blue, 30 );
}
