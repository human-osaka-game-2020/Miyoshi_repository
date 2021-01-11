
#include "TitleScene.h"

TitleScene::TitleScene() {

}

TitleScene::~TitleScene() {

}

void TitleScene::Execute() {
	Control();
	Draw();
}

void TitleScene::Control() {

	if ( fadeMode != FadeMode::None ) return;

	if ( CheckHitKey( KEY_INPUT_1 ) ) {
		fadeMode = FadeMode::Out;
	}
}

void TitleScene::Draw() {

	DrawString( 10, 10, "Title", Color::red );
	DrawString( 10, 30, "Press 1 to OnPlay Scene", Color::red );

	SceneFade( SceneList::OnPlay, 255 / 60, Color::white, 60 );
}
