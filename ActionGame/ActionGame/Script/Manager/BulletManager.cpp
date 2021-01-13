
#include "BulletManager.h"
#include "SpriteManager.h"

void BulletManager::Control(){
	for( int i = 0; i < bullets.size(); i++ ){
		if( bullets.at( i ) != nullptr ){
			bullets.at( i )->Control();
			if( CheckOffWindow( bullets.at( i )->GetCharacterData() ) == true ){
				delete bullets.at( i );
				bullets.at( i ) = nullptr;
			}
		}
	}
}

void BulletManager::Draw(){
	for( int i = 0; i < bullets.size(); i++ ){
		if( bullets.at( i ) != nullptr ){
			bullets.at( i )->Draw();
		}
	}
}

void BulletManager::CreateBullet( CharacterData data_ ){
	for( int i = 0; i < bullets.size(); i++ ){
		if( bullets.at( i ) == nullptr ){
			bullets.at( i ) = new Bullet( { data_.position, { 16, 16 }, 25, data_.direction, SpriteManager::GetInstance()->GetGraphHandle( GraphName::gBullet ) } );
			return;
		}
	}

	bullets.push_back( new Bullet( { data_.position, { 16, 16 }, 25, data_.direction, SpriteManager::GetInstance()->GetGraphHandle( GraphName::gBullet ) } ) );
}
