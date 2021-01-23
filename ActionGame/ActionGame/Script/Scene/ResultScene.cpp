
#include "ResultScene.h"

ResultScene::ResultScene() {
	sprIns = SpriteManager::GetInstance();
	sndIns = SoundManager::GetInstance();
	gameIns = GameManager::GetInstance();

	SaveState saveTemp = gameIns->Load();
	gameIns->Save( { saveTemp.x, saveTemp.y, saveTemp.stageNumber,gameIns->GetDeathCounter() } );
	sprIns->LoadGraphHandle( GraphName::gResult );

	sndIns->LoadSoundHandle( SoundName::sClear );
	sndIns->LoadSoundHandle( SoundName::sEnter );
	sndIns->LoadSoundHandle( SoundName::bResult );

	PlaySE( SoundName::sClear );
	PlayBGM( SoundName::bResult );
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
		PlaySE( SoundName::sEnter );
		SceneBase::fadeMode = FadeMode::Out;
	}
}

void ResultScene::Draw() {
	DrawGraph( 0, 0, sprIns->GetGraphHandle( GraphName::gResult ), false );

	DrawFormatString( WINDOW_WIDTH / 2 - 192, WINDOW_HEIGHT - 200, Color::black, "死亡回数：%d", gameIns->GetDeathCounter() );

	SceneFade( SceneList::Title, 255 / 60, Color::black );
}
