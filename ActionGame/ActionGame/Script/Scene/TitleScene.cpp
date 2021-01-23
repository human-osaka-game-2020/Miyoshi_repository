
#include "TitleScene.h"
#include "../Manager/GameManager.h"

TitleScene::TitleScene() :
	currentSelection( Menu::NewGame_m ),
	pointerRadius( 15 )
{
	sprIns = SpriteManager::GetInstance();
	sndIns = SoundManager::GetInstance();

	SetFontSize( 48 );
	sprIns->LoadGraphHandle( GraphName::gTitle );

	sndIns->LoadSoundHandle( SoundName::sSelect );
	sndIns->LoadSoundHandle( SoundName::sEnter );
	sndIns->LoadSoundHandle( SoundName::bTitle );
	PlayBGM( SoundName::bTitle );
}

TitleScene::~TitleScene() {

}

void TitleScene::Execute() {
	Control();
	Draw();
}

void TitleScene::Control() {
	if ( fadeMode != FadeMode::None ) return;

	if ( SelectMenu() == true ) fadeMode = FadeMode::Out;
}

void TitleScene::Draw() {
	DrawGraph( 0, 0, sprIns->GetGraphHandle( GraphName::gTitle ), false );

	int offset = 200;
	if( currentSelection == Menu::Continue_m ) offset = 100;

	DrawCircle( WINDOW_WIDTH / 2 - 120 , WINDOW_HEIGHT - offset, pointerRadius, Color::red, true );
	DrawString( WINDOW_WIDTH / 2 - 96, WINDOW_HEIGHT - 200 - 24, "New Game", Color::white );
	DrawString( WINDOW_WIDTH / 2 - 96, WINDOW_HEIGHT - 100 - 24, "Continue", Color::white );

	SceneFade( SceneList::OnPlay, 255 / 60, Color::black );
}

bool TitleScene::SelectMenu(){
	if( GetKeyStatus( KEY_INPUT_UP ) == InputState::Pressed ){
		PlaySE( SoundName::sSelect );
		currentSelection = Menu::NewGame_m;
	}
	else if( GetKeyStatus( KEY_INPUT_DOWN ) == InputState::Pressed ){
		PlaySE( SoundName::sSelect );
		currentSelection = Menu::Continue_m;
	}

	if( GetKeyStatus( KEY_INPUT_RETURN ) == InputState::Pressed ){
		PlaySE( SoundName::sEnter );
		if( currentSelection == Menu::NewGame_m ) GameManager::GetInstance()->Save( { 0, 0, 0, 0 } );
		return true;
	}

	return false;
}
