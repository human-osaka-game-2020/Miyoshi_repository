
#include "TitleScene.h"
#include "../Manager/GameManager.h"
#include "../Manager/SpriteManager.h"
#include "../Manager/SoundManager.h"

TitleScene::TitleScene() :
	currentSelect( 0 ),
	pointerRadius( 15 )
{
	SetFontSize( 48 );
	SpriteManager::GetInstance()->LoadGraphHandle( GraphName::gTitle );

	SoundManager* sndIns = SoundManager::GetInstance();
	sndIns->LoadSoundHandle( SoundName::sSelect );
	sndIns->LoadSoundHandle( SoundName::sEnter );
	sndIns->LoadSoundHandle( SoundName::bTitle );
	PlaySoundMem( sndIns->GetSoundHandle( SoundName::bTitle ), DX_PLAYTYPE_LOOP );
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
	DrawGraph( 0, 0, SpriteManager::GetInstance()->GetGraphHandle( GraphName::gTitle ), false );

	int offset = 200;
	for( int i = 0; i < currentSelect; i++ ) offset -= 100;

	DrawCircle( WINDOW_WIDTH / 2 - 120 , WINDOW_HEIGHT - offset, pointerRadius, Color::red, true );
	DrawString( WINDOW_WIDTH / 2 - 96, WINDOW_HEIGHT - 200 - 24, "New Game", Color::white );
	DrawString( WINDOW_WIDTH / 2 - 96, WINDOW_HEIGHT - 100 - 24, "Continue", Color::white );

	SceneFade( SceneList::OnPlay, 255 / 60, Color::black );
}

bool TitleScene::SelectMenu(){
	SoundManager* sndIns = SoundManager::GetInstance();

	if( GetKeyStatus( KEY_INPUT_UP ) == InputState::Pressed ){
		PlaySoundMem( sndIns->GetSoundHandle( SoundName::sSelect ), DX_PLAYTYPE_BACK );
		currentSelect--;
		if( currentSelect <= 0 ) currentSelect = 0;
	}
	else if( GetKeyStatus( KEY_INPUT_DOWN ) == InputState::Pressed ){
		PlaySoundMem( sndIns->GetSoundHandle( SoundName::sSelect ), DX_PLAYTYPE_BACK );
		currentSelect++;
		if( currentSelect >= Menu::MenuMax ) currentSelect--;
	}

	if( GetKeyStatus( KEY_INPUT_RETURN ) == InputState::Pressed ){
		PlaySoundMem( sndIns->GetSoundHandle( SoundName::sEnter ), DX_PLAYTYPE_BACK );
		if( currentSelect == 0 ) GameManager::GetInstance()->DataSaving( { 0, 0, 0, 0 } );
		return true;
	}

	return false;
}
