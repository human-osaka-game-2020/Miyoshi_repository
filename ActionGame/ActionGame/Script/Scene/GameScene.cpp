
#include "GameScene.h"
#include "../Manager/GameManager.h"
#include "../Manager/SpriteManager.h"
#include "../Object/Block.h"
#include "../Object/Okonomiyaki.h"
#include "../Object/Sauce.h"
#include "../Object/Save.h"
#include "../Object/Warp.h"

int GameScene::stageNumber = 0;
std::vector<Gauge> GameScene::gaugeList;
std::vector<std::vector<ObjectBase*>> GameScene::stageData;

GameScene::GameScene() {
	SpriteManager* sprIns = SpriteManager::GetInstance();
	sprIns->LoadGraphHandle( GraphName::gPlayer );
	sprIns->LoadGraphHandle( GraphName::gBullet );
	sprIns->LoadGraphHandle( GraphName::gBlock );
	sprIns->LoadGraphHandle( GraphName::gEmptyBlock );
	sprIns->LoadGraphHandle( GraphName::gOkonomiyaki );
	sprIns->LoadGraphHandle( GraphName::gSauce );
	sprIns->LoadGraphHandle( GraphName::gSave );
	sprIns->LoadGraphHandle( GraphName::gWarp );
	stageNumber = GameManager::GetInstance()->DataLoading().stageNumber;
	GameManager::GetInstance()->SetDeathCounter( GameManager::GetInstance()->DataLoading().deathCount );

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

	DrawFormatString( 0, 0, Color::black, "Death : %d", GameManager::GetInstance()->GetDeathCounter() );

	SceneFade( SceneList::Result, 255 / 60, Color::black );
}

void GameScene::Reset(){
	SpriteManager* sprIns = SpriteManager::GetInstance();

	SaveState dataTemp = GameManager::GetInstance()->DataLoading();

	player = new Player( { { dataTemp.x, dataTemp.y }, sprIns->GetGraphData( GraphName::gPlayer ).size, 6,
	Direction::Right, sprIns->GetGraphHandle( GraphName::gPlayer ) } );

	stageData.clear();
	stageData.resize( STAGE_HEIGHT, std::vector<ObjectBase*>( STAGE_WIDTH ) );

	for( int y = 0; y < STAGE_HEIGHT; y++ ){
		for( int x = 0; x < STAGE_WIDTH; x++ ){
			switch( GameManager::GetInstance()->GetStageData( stageNumber ).at( y ).at( x ) ){
			case Block_o:
				stageData.at( y ).at( x ) = new Block( { { x * CHIP_WIDTH, y * CHIP_HEIGHT }, { CHIP_WIDTH, CHIP_HEIGHT },
					sprIns->GetGraphHandle( GraphName::gBlock ), ObjectTag::Block_o } );
				break;
			case EmptyBlock_o:
				stageData.at( y ).at( x ) = new Block( { { x * CHIP_WIDTH, y * CHIP_HEIGHT }, { CHIP_WIDTH, CHIP_HEIGHT },
					sprIns->GetGraphHandle( GraphName::gBlock ), ObjectTag::EmptyBlock_o } );
				break;
			case SkeletonBlock_o:
				stageData.at( y ).at( x ) = new Block( { { x * CHIP_WIDTH, y * CHIP_HEIGHT }, { CHIP_WIDTH, CHIP_HEIGHT },
					0, ObjectTag::SkeletonBlock_o } );
				break;
			case Save_o:
				stageData.at( y ).at( x ) = new Save( { {x * CHIP_WIDTH, y * CHIP_HEIGHT}, {CHIP_WIDTH, CHIP_HEIGHT},
					sprIns->GetGraphHandle( GraphName::gSave ), ObjectTag::Save_o } );
				break;
			case Okonomiyaki_o:
				stageData.at( y ).at( x ) = new Okonomiyaki( { {x * CHIP_WIDTH + 2, y * CHIP_HEIGHT + 2}, {CHIP_WIDTH - 4, CHIP_HEIGHT - 4},
					sprIns->GetGraphHandle( GraphName::gOkonomiyaki ), ObjectTag::Okonomiyaki_o } );
				break;
			case Sauce_o:
				stageData.at( y ).at( x ) = new Sauce( { {x * CHIP_WIDTH, y * CHIP_HEIGHT },{CHIP_WIDTH, CHIP_HEIGHT},
					sprIns->GetGraphHandle( GraphName::gSauce ), ObjectTag::Sauce_o } );
				break;
			case Warp_o:
				stageData.at( y ).at( x ) = new Warp( { {x * CHIP_WIDTH, y * CHIP_HEIGHT}, {CHIP_WIDTH, CHIP_HEIGHT},
					sprIns->GetGraphHandle( GraphName::gWarp ), ObjectTag::Warp_o } );
				break;
			case Air_o:
			default:
				stageData.at( y ).at( x ) = nullptr;
				break;
			}
		}
	}
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
					GameManager::GetInstance()->AddDeathCounter();
					delete player;
					player = nullptr;
					return;
				case ObjectTag::Warp_o:
					NextStage();
					return;
				}
			}
		}
	}
}

void GameScene::NextStage(){
	stageNumber++;
	if( stageNumber >= GameManager::GetInstance()->GetStageMax() ){
		fadeMode = FadeMode::Out;
		return;
	}

	GameManager::GetInstance()->DataSaving( { 0,0,stageNumber, GameManager::GetInstance()->GetDeathCounter() } );
	Reset();
}
