
#include "GameScene.h"
#include "../Object/Block.h"
#include "../Object/Okonomiyaki.h"
#include "../Object/Sauce.h"
#include "../Object/Save.h"
#include "../Object/Warp.h"

int GameScene::stageNumber = 0;
std::vector<Gauge> GameScene::gaugeList;
std::vector<std::vector<ObjectBase*>> GameScene::stageData;

GameScene::GameScene() {
	sprIns = SpriteManager::GetInstance();
	sndIns = SoundManager::GetInstance();
	gameIns = GameManager::GetInstance();

	SceneDataLoad();
	Reset();
}

GameScene::~GameScene() {

}

void GameScene::Execute() {
	Control();
	Draw();
}

void GameScene::Control() {
	if ( fadeMode != FadeMode::None ) return;

	if( GetKeyStatus( Key::RESET ) == InputState::Pressed ){
		PlaySE( SoundName::sReset );
		Reset();
		return;
	}

	if( player != nullptr ){
		player->Move();
		player->ResetHitData();
		Collision();
	}

	for( int i = 0; i < gaugeList.size(); i++ ){
		gaugeList.at( i ).Control();
	}
}

void GameScene::Draw() {
	for( int y = 0; y < STAGE_HEIGHT; y++ ){
		for( int x = 0; x < STAGE_WIDTH; x++ ){
			if( stageData.at( y ).at( x ) != nullptr ){
				stageData.at( y ).at( x )->Draw();
			}
		}
	}

	if( player != nullptr ){
		player->Draw();
	}

	for( int i = 0; i < gaugeList.size(); i++ ){
		gaugeList.at( i ).Draw();
	}

	DrawFormatString( 0, 0, Color::red, "Death : %d", gameIns->GetDeathCounter() );

	SceneFade( SceneList::Result, 255 / 60, Color::black );
}

void GameScene::Reset(){
	SaveState dataTemp = gameIns->Load();

	player = new Player( { { dataTemp.x, dataTemp.y }, sprIns->GetGraphData( GraphName::gPlayer ).size, 6,
	Direction::Right, sprIns->GetGraphHandle( GraphName::gPlayer ) } );

	stageData.clear();
	stageData.resize( STAGE_HEIGHT, std::vector<ObjectBase*>( STAGE_WIDTH ) );

	for( int y = 0; y < STAGE_HEIGHT; y++ ){
		for( int x = 0; x < STAGE_WIDTH; x++ ){
			Position drawPos = { x * CHIP_WIDTH, y * CHIP_HEIGHT };
			Size chipSize = { CHIP_WIDTH, CHIP_HEIGHT };
			ObjectTag objTag = gameIns->GetStageData( stageNumber ).at( y ).at( x );

			switch( objTag ){
			case Block_o: stageData.at( y ).at( x ) =			new Block( { drawPos, chipSize, sprIns->GetGraphHandle( GraphName::gBlock ), objTag } ); break;
			case EmptyBlock_o: stageData.at( y ).at( x ) =		new Block( { drawPos, chipSize, sprIns->GetGraphHandle( GraphName::gBlock ), objTag } ); break;
			case SkeletonBlock_o: stageData.at( y ).at( x ) =	new Block( { drawPos, chipSize, 0, objTag } ); break;
			case Save_o: stageData.at( y ).at( x ) =		 	 new Save( { drawPos, chipSize, sprIns->GetGraphHandle( GraphName::gSave ), objTag } ); break;
			case Okonomiyaki_o:
			{
				float offsetX = 18;
				float offsetY = 18;
				drawPos.x += offsetX;
				drawPos.y += offsetY;
				chipSize.width -= offsetX * 2;
				chipSize.height -= offsetY * 2;
			}
			stageData.at( y ).at( x ) =			  new Okonomiyaki( { drawPos, chipSize, sprIns->GetGraphHandle( GraphName::gOkonomiyaki ), objTag } ); break;
			case Sauce_o: stageData.at( y ).at( x ) =	new Sauce( { drawPos, chipSize, sprIns->GetGraphHandle( GraphName::gSauce ), objTag } ); break;
			case Warp_o: stageData.at( y ).at( x ) =	 new Warp( { drawPos, chipSize, sprIns->GetGraphHandle( GraphName::gWarp ), objTag } ); break;
			case Air_o:
			default: stageData.at( y ).at( x ) = nullptr;  break;
			}
		}
	}
	PlayBGM( SoundName::bGame );
}

void GameScene::Collision(){
	for( int y = 0; y < STAGE_HEIGHT; y++ ){
		for( int x = 0; x < STAGE_WIDTH; x++ ){
			if( stageData.at( y ).at( x ) != nullptr ){
				// 弾判定
				player->BulletCollision( stageData.at( y ).at( x ), stageNumber );

				// プレイヤー判定
				switch( player->Collision( stageData.at( y ).at( x ) )){
				case ObjectTag::Okonomiyaki_o:
					gameIns->AddDeathCounter();
					PlaySE( SoundName::sDeath );
					PlayBGM( SoundName::sGameOver );
					delete player;
					player = nullptr;
					return;
				case ObjectTag::Warp_o:
					PlaySE( SoundName::sWarp );
					NextStage();
					return;
				}
			}
		}
	}
}

void GameScene::NextStage(){
	stageNumber++;
	if( stageNumber >= gameIns->GetStageMax() ){
		fadeMode = FadeMode::Out;
		return;
	}

	gameIns->Save( { 0,0,stageNumber, gameIns->GetDeathCounter() } );
	Reset();
}

void GameScene::SceneDataLoad(){
	sprIns->LoadGraphHandle( GraphName::gPlayer );
	sprIns->LoadGraphHandle( GraphName::gBullet );
	sprIns->LoadGraphHandle( GraphName::gBlock );
	sprIns->LoadGraphHandle( GraphName::gEmptyBlock );
	sprIns->LoadGraphHandle( GraphName::gOkonomiyaki );
	sprIns->LoadGraphHandle( GraphName::gSauce );
	sprIns->LoadGraphHandle( GraphName::gSave );
	sprIns->LoadGraphHandle( GraphName::gWarp );

	sndIns->LoadSoundHandle( SoundName::sBlockDestroy );
	sndIns->LoadSoundHandle( SoundName::sBlockSpawn );
	sndIns->LoadSoundHandle( SoundName::sDeath );
	sndIns->LoadSoundHandle( SoundName::sWarp );
	sndIns->LoadSoundHandle( SoundName::sReset );
	sndIns->LoadSoundHandle( SoundName::bGame );
	sndIns->LoadSoundHandle( SoundName::sGameOver );

	stageNumber = gameIns->Load().stageNumber;
	gameIns->SetDeathCounter( gameIns->Load().deathCount );
}
