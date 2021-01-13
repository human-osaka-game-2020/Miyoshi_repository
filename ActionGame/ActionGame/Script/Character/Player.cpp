
#include "Player.h"
#include "../Manager/SpriteManager.h"

Player::Player( CharacterData initData ) :
	data( initData ),
	jumpPower( JUMP_POWER ),
	isJumped( true ),
	isDoubleJumped( false ),
	jumpCounter( 0 )
{
	pBulletManager = new BulletManager();
}

Player::~Player() {

}

void Player::Move() {
	Position previousPos = { data.position.x, data.position.y };

	if( GetKeyStatus( Key::RIGHT ) == InputState::Pressing ) {
		data.position.x += data.speed;
		data.direction = Direction::Right;
	}
	else if( GetKeyStatus( Key::LEFT ) == InputState::Pressing ) {
		data.position.x -= data.speed;
		data.direction = Direction::Left;
	}

	if( GetKeyStatus( Key::JUMP ) == InputState::Pressed ) isJumped = true;
	else if( GetKeyStatus( Key::JUMP ) == InputState::Pressing ) jumpPower += 0.5f;

	if( GetKeyStatus( Key::SHOT ) == InputState::Pressed ) Shoot();

	if( CheckOffWindow( data, false ) == true ) data = previousPos;

	Jump();

	pBulletManager->Control();
}

void Player::Draw() {
	DrawGraphF( data.position.x, data.position.y, data.graphHandle, true );
	pBulletManager->Draw();
}

void Player::Jump(){
	if( isJumped == false ){
		jumpPower = JUMP_POWER;
		jumpCounter = 0;
		return;
	}

	jumpCounter++;
	float tempJumpPower = jumpPower + -GRAVITY * jumpCounter;

	// ここのifは「地面に接触したら」に変更する
	if( data.position.y > 600 - data.size.height ){
		data.position.y = 600 - data.size.height;
		isJumped = false;
		isDoubleJumped = false;
		return;
	}

	if( isDoubleJumped == false && jumpCounter >= 2 ){
		if( GetKeyStatus( Key::JUMP ) == InputState::Pressed ){
			isDoubleJumped = true;
			jumpCounter = 0;
			jumpPower = JUMP_POWER;
		}
	}

	data.position.y -= tempJumpPower;
}

void Player::Shoot(){
	pBulletManager->CreateBullet( data );
}
