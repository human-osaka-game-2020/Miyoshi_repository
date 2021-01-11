
#include "Player.h"

Player::Player( CharacterData initData ) :
	data( initData )
{

}

Player::~Player() {

}

void Player::Move() {
	if( GetKeyStatus( KEY_INPUT_UP ) == InputState::Pressing ) {
		data.y -= data.speed;
	}
	else if( GetKeyStatus( KEY_INPUT_DOWN ) == InputState::Pressing ) {
		data.y += data.speed;
	}

	if( GetKeyStatus( KEY_INPUT_RIGHT ) == InputState::Pressing ) {
		data.x += data.speed;
	}
	else if( GetKeyStatus( KEY_INPUT_LEFT ) == InputState::Pressing ) {
		data.x -= data.speed;
	}
}

void Player::Draw() {
	LoadGraphScreen( data.x, data.y, data.sprite, false );
}
