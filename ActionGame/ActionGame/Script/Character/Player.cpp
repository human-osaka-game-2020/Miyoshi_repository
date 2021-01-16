
#include "Player.h"
#include "../Manager/SpriteManager.h"
#include "../Manager/SoundManager.h"

Player::Player( CharacterData initData ) :
	data( initData ),
	jumpPower( 0 ),
	isJumped( true ),
	isDoubleJumped( false ),
	jumpCounter( 0 ),
	isFlying( false ),
	previousPos( {} ),
	previousHit( {} )
{
	pBulletManager = new BulletManager();

	SoundManager* sndIns = SoundManager::GetInstance();
	sndIns->LoadSoundHandle( SoundName::sJump );
	sndIns->LoadSoundHandle( SoundName::sDoubleJump );
	sndIns->LoadSoundHandle( SoundName::sShoot );
}

Player::~Player() {

}

void Player::Move() {
	previousHit = hitChecker;
	previousPos = data.position;

	if( GetKeyStatus( Key::RIGHT ) == InputState::Pressing ) {
		if( hitChecker.right == false ){
			data.position.x += data.speed;
			data.direction = Direction::Right;
		}
	}
	else if( GetKeyStatus( Key::LEFT ) == InputState::Pressing ) {
		if( hitChecker.left == false ){
			data.position.x -= data.speed;
			data.direction = Direction::Left;
		}
	}

	if( GetKeyStatus( Key::JUMP ) == InputState::Pressed ) {
		if( ( isFlying == false || isDoubleJumped == false ) && hitChecker.up == false ){
			data.position.y -= 20;
			jumpPower = -JUMP_POWER;
			hitChecker.down = false;
			if( isFlying == true ){
				isDoubleJumped = true;
				PlaySoundMem( SoundManager::GetInstance()->GetSoundHandle( SoundName::sDoubleJump ), DX_PLAYTYPE_BACK );
			}
			else{
				PlaySoundMem( SoundManager::GetInstance()->GetSoundHandle( SoundName::sJump ), DX_PLAYTYPE_BACK );
			}
		}
	}
	else if( GetKeyStatus( Key::JUMP ) == InputState::Pressing ) if(jumpPower < 0) jumpPower -= 0.35f;

	if( GetKeyStatus( Key::SHOT ) == InputState::Pressed ) Shoot();

	if( hitChecker.down == false ){
		isFlying = true;
	}
	else{
		isFlying = false;
		isDoubleJumped = false;
		jumpPower = 0;
	}

	if( hitChecker.up == true ){
		jumpPower = 2;
	}

	if( CheckOffWindow( data, false ) ) data = previousPos;

	Jump();

	pBulletManager->Control();
}

void Player::Draw() {
	DrawGraphF( data.position.x, data.position.y, data.graphHandle, true );
	pBulletManager->Draw();
}

void Player::Jump(){
	if( hitChecker.down == true ) return;

	data.position.y += jumpPower;
	jumpPower += GRAVITY;

	if( jumpPower > 30 ) jumpPower = 30; // ブロックの幅より小さく
}

void Player::Shoot(){
	PlaySoundMem( SoundManager::GetInstance()->GetSoundHandle( SoundName::sShoot ), DX_PLAYTYPE_BACK );
	pBulletManager->CreateBullet( data );
}

ObjectTag Player::Collision( ObjectBase* object_ ){
	if( ( ( data.position.x + data.size.width ) > object_->GetData().position.x ) &&
		data.position.x < ( object_->GetData().position.x + object_->GetData().size.width ) &&
		( data.position.y + data.size.height ) > object_->GetData().position.y &&
		data.position.y < ( object_->GetData().position.y + object_->GetData().size.height ) ){
		// どの方向からあたっているか
		// 上から
		if( ( ( data.position.x + data.size.width - 10 ) > object_->GetData().position.x ) &&
			( data.position.x + 10 ) < ( object_->GetData().position.x + object_->GetData().size.width ) &&
			( data.position.y + data.size.height ) > ( object_->GetData().position.y + object_->GetData().size.height ) &&
			data.position.y < ( object_->GetData().position.y + object_->GetData().size.height ) ){
			if( object_->GetTag() == ObjectTag::Block_o || object_->GetTag() == ObjectTag::SkeletonBlock_o ){
				hitChecker.up = true;
			}
		}

		// 左から
		if( data.position.x < ( object_->GetData().position.x + object_->GetData().size.width ) &&
			data.position.x > object_->GetData().position.x &&
			( data.position.y + data.size.height - 10 ) > object_->GetData().position.y &&
			( data.position.y + 10 ) < ( object_->GetData().position.y + object_->GetData().size.height ) ){
			if( object_->GetTag() == ObjectTag::Block_o || object_->GetTag() == ObjectTag::SkeletonBlock_o ){
				hitChecker.left = true;
			}
		}

		// 右から
		if( ( data.position.x + data.size.width ) > object_->GetData().position.x &&
			data.position.x < object_->GetData().position.x &&
			( data.position.y + data.size.height - 10 ) > object_->GetData().position.y &&
			( data.position.y + 10 ) < ( object_->GetData().position.y + object_->GetData().size.height ) ){
			if( object_->GetTag() == ObjectTag::Block_o || object_->GetTag() == ObjectTag::SkeletonBlock_o ){
				hitChecker.right = true;
			}
		}

		// 下から
		if( ( ( data.position.x + data.size.width - 10 ) > object_->GetData().position.x ) &&
			( data.position.x + 10 ) < ( object_->GetData().position.x + object_->GetData().size.width ) &&
			( data.position.y + data.size.height ) > object_->GetData().position.y &&
			data.position.y < object_->GetData().position.y ){
			if( object_->GetTag() == ObjectTag::Block_o || object_->GetTag() == ObjectTag::SkeletonBlock_o ){
				hitChecker.down = true;
			}
		}

		// 当たっている場合
		switch( object_->GetTag() ){
		case EmptyBlock_o:
			PlaySoundMem( SoundManager::GetInstance()->GetSoundHandle( SoundName::sBlockDestroy ), DX_PLAYTYPE_BACK );
			object_->Control();
			break;
		case SkeletonBlock_o:
			PlaySoundMem( SoundManager::GetInstance()->GetSoundHandle( SoundName::sBlockSpawn ), DX_PLAYTYPE_BACK );
			object_->Control();
			break;
		case Sauce_o:
			isDoubleJumped = false;
			break;
			// 今のところあたってもなにもない方達
		case Warp_o: break;
		case Okonomiyaki_o: break;
		case Air_o: break;
		case Block_o: break;
		case Save_o: break;
		case objMax_o: break;
		default: break;
		}

		return object_->GetTag();
	}
}

void Player::BulletCollision( ObjectBase* object_, int stageNumber_ ){
	pBulletManager->Collision( object_, data.position, stageNumber_ );
}

void Player::ResetHitData(){
	hitChecker = { false, false, false, false };
}
