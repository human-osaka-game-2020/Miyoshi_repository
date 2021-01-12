
#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <vector>

#include "DxLib.h"

// シーンの一覧
enum class SceneList {
	Title,	// タイトル画面
	OnPlay,	// ゲーム中の画面
	Result	// リザルト画面
};

// 方向
enum class Direction{
	Up,
	Left,
	Right,
	Down
};

// 場所
struct Position{
	float x;
	float y;
};

// 大きさ
struct Size{
	float width;
	float height;
};

// キャラクターの情報
struct CharacterData{
	Position position;
	Size size;
	float speed;
	Direction direction;
	LPCTSTR sprite;

	void operator = ( Position pos_ ){
		position.x = pos_.x;
		position.y = pos_.y;
	}

	void operator = ( Size size_ ){
		size.width = size_.width;
		size.height = size_.height;
	}
};

const float WINDOW_WIDTH = 1280;
const float WINDOW_HEIGHT = 720;

const float GRAVITY = 1;

namespace Key{
	const int UP = KEY_INPUT_UP;
	const int LEFT = KEY_INPUT_LEFT;
	const int RIGHT = KEY_INPUT_RIGHT;
	const int DOWN = KEY_INPUT_DOWN;
	const int JUMP = KEY_INPUT_LSHIFT;
	const int SHOT = KEY_INPUT_Z;
};

namespace Color{
	const int white = GetColor( 255, 255, 255 );
	const int black = GetColor( 0, 0, 0 );
	const int blue = GetColor( 0, 0, 255 );
	const int green = GetColor( 0, 255, 0 );
	const int red = GetColor( 255, 0, 0 );

}

#endif // !COMMON_N
