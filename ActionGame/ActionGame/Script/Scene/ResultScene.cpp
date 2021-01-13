
#include "ResultScene.h"
#include "../Manager/GameManager.h"

ResultScene::ResultScene() {
	GameManager::GetInstance()->DataSaving( { 0, 0, 0 } );
}

ResultScene::~ResultScene() {

}

void ResultScene::Execute() {
	Control();
	Draw();
}

void ResultScene::Control() {

	if ( SceneBase::fadeMode != FadeMode::None ) return;

	if ( CheckHitKey( KEY_INPUT_3 ) ) {
		SceneBase::fadeMode = FadeMode::Out;
	}
}

void ResultScene::Draw() {

	DrawString( 10, 10, "Result", Color::red );
	DrawString( 10, 30, "Press 3 to Title Scene", Color::red );

	SceneFade( SceneList::Title, 255 / 60, Color::blue );
}
