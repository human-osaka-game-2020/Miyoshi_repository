﻿
#include "ResultScene.h"
#include "../Manager/GameManager.h"
#include "../Manager/SpriteManager.h"

ResultScene::ResultScene() {
	GameManager* gameIns = GameManager::GetInstance();
	SaveState saveTemp = gameIns->DataLoading();
	gameIns->DataSaving( { saveTemp.x, saveTemp.y, saveTemp.stageNumber,gameIns->GetDeathCounter() } );
	SpriteManager::GetInstance()->LoadGraphHandle( GraphName::gResult );
}

ResultScene::~ResultScene() {

}

void ResultScene::Execute() {
	Control();
	Draw();
}

void ResultScene::Control() {

	if ( SceneBase::fadeMode != FadeMode::None ) return;

	if ( CheckHitKey( KEY_INPUT_RETURN ) ) {
		SceneBase::fadeMode = FadeMode::Out;
	}
}

void ResultScene::Draw() {
	DrawGraph( 0, 0, SpriteManager::GetInstance()->GetGraphHandle( GraphName::gResult ), false );

	DrawFormatString( WINDOW_WIDTH / 2 - 192, WINDOW_HEIGHT - 200, Color::black, "死亡回数：%d", GameManager::GetInstance()->GetDeathCounter() );

	SceneFade( SceneList::Title, 255 / 60, Color::black );
}
