
#include "BulletManager.h"
#include "SpriteManager.h"
#include "GameManager.h"

void BulletManager::Control(){
	for( int i = 0; i < bullets.size(); i++ ){
		if( bullets.at( i ) != nullptr ){
			bullets.at( i )->Control();
			if( CheckOffWindow( bullets.at( i )->GetData() ) == true ){
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

void BulletManager::Collision( ObjectBase* object_, Position pos_, int stageNumber_ ){
	GameManager* ins = GameManager::GetInstance();

	for( int i = 0; i < bullets.size(); i++ ){
		if( bullets.at( i ) != nullptr ){
			float l = pow( object_->GetData().position.x - bullets.at( i )->GetData().position.x, 2 );
			float r = pow( object_->GetData().position.y - bullets.at( i )->GetData().position.y, 2 );
			float range = sqrt( l + r );

			float radius = object_->GetData().size.width / 2 + bullets.at( i )->GetData().size.width / 2;

			if( range <= radius ){
				if( object_->GetTag() == ObjectTag::Block_o ||
					object_->GetTag() == ObjectTag::EmptyBlock_o ||
					object_->GetTag() == ObjectTag::SkeletonBlock_o ||
					object_->GetTag() == ObjectTag::Save_o ){
					// 当たってる
					if( object_->GetTag() == ObjectTag::Save_o ){
						ins->DataSaving( { pos_.x, pos_.y, stageNumber_ } );
					}

					delete bullets.at( i );
					bullets.at( i ) = nullptr;
				}
			}
		}
	}
}
