
#include "ResultScene.h"

ResultScene::ResultScene() {

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
