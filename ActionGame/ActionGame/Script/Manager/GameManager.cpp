
#include "GameManager.h"

void GameManager::LoadStage(){

	std::vector<std::string> fileName;

	{
		WIN32_FIND_DATA fileData;

		HANDLE handle = FindFirstFile( "Stage/*.txt", &fileData );

		// ファイルがない場合は終了
		if( handle == INVALID_HANDLE_VALUE ) return;

		do{
			// ファイルリストに登録
			fileName.push_back( fileData.cFileName );
			fileName.back().insert( 0, "Stage/" );
		} while( FindNextFile( handle, &fileData ) == TRUE );

		// 検索終了
		FindClose( handle );
	}

	// 読み込み
	for( int i = 0; i < fileName.size(); i++ ){
		std::ifstream file( fileName.at( i ) );
		std::string lineTemp;
		bool readMode = false;
		int y = 0;

		std::getline( file, lineTemp );
		if( lineTemp.find( "/action" ) != -1 ){
			stageData.push_back( {} );
			stageData.back().resize( STAGE_HEIGHT, std::vector<ObjectTag>( STAGE_WIDTH ) );
			while( std::getline( file, lineTemp ) ){

				// コメント文は無視
				if( lineTemp.find( "//" ) != -1 );
				// 読み込み開始
				else if( lineTemp.find( "/start" ) != -1 ){
					readMode = true;
				}
				// 読み込み終了
				else if( lineTemp.find( "/end" ) != -1 ){
					break;
				}
				else if( readMode == true ){
					for( int x = 0; x < STAGE_WIDTH; x++ ){
						if( lineTemp.at( x ) == ',' ) break;	// カンマで改行

						// 値を変換して登録
						if( lineTemp.at( x ) >= 48 && lineTemp.at( x ) <= 48 + ObjectTag::objMax_o - 1 ){
							ObjectTag objTemp = ObjectTag::Air_o;
							switch( lineTemp.at( x ) - 48 ){
							case 0: break;
							case 1: objTemp = ObjectTag::Block_o; break;
							case 2: objTemp = ObjectTag::EmptyBlock_o; break;
							case 3: objTemp = ObjectTag::SkeletonBlock_o; break;
							case 4: objTemp = ObjectTag::Save_o; break;
							case 5: objTemp = ObjectTag::Okonomiyaki_o; break;
							case 6: objTemp = ObjectTag::Sauce_o; break;
							case 7: objTemp = ObjectTag::Warp_o; break;
							default: break;
							}
							stageData.at( i ).at( y ).at( x ) = objTemp;
						}
					}
					y++;
					if( y == STAGE_HEIGHT ) break;
				}
			}
		}
	}

}

void GameManager::Save( SaveState data_ ){
	std::ofstream file( "SaveData.txt" );

	file.clear();

	// データ書き込み
	file << data_.x << std::endl << data_.y << std::endl << data_.stageNumber << std::endl << data_.deathCount;

	file.close();
}

SaveState GameManager::Load(){
	std::ifstream file( "SaveData.txt" );

	// ファイルがない場合は初期地点へ
	if( file.fail() ) return { 0.0f, 0.0f, 0, 0 };

	std::string lineTemp;
	SaveState returnTemp;

	std::getline( file, lineTemp );
	returnTemp.x = std::stof( lineTemp );
	std::getline( file, lineTemp );
	returnTemp.y = std::stof( lineTemp );
	std::getline( file, lineTemp );
	returnTemp.stageNumber = std::stoi( lineTemp );
	std::getline( file, lineTemp );
	returnTemp.deathCount = std::stoi( lineTemp );

	return returnTemp;
}

std::vector<std::vector<ObjectTag>> GameManager::GetStageData( int stageNumber_ ){
	if( stageNumber_ >= stageData.size() ) {
		stageNumber_ = 0;
	}

	return stageData.at( stageNumber_ );
}

void GameManager::AddDeathCounter(){
	SaveState dataTemp = Load();
	dataTemp.deathCount++;
	Save( { dataTemp } );
	deathCounter++;
}
