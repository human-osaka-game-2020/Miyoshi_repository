#include "DxLib.h"
#include "Common.h"

Player::Player() {
	pos_x = 640;
	pos_y = 360;
	movingSpeed = 1;
}

Player::~Player() {

}

void Player::Moving() {
	if (CheckHitKey(KEY_INPUT_UP)) {
		Player::pos_y -= movingSpeed;
	}
	else if (CheckHitKey(KEY_INPUT_DOWN)) {
		Player::pos_y += movingSpeed;
	}

	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		Player::pos_x += movingSpeed;
	}
	else if (CheckHitKey(KEY_INPUT_LEFT)) {
		Player::pos_x -= movingSpeed;
	}
}

void Player::Draw() {
	LoadGraphScreen(pos_x, pos_y, "Sprite/Player.bmp", false);
}