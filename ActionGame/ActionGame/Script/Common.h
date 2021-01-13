
#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <string>

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

// オブジェクト一覧
enum ObjectTag{
	Air_o,	// 空気
	Block_o,	// ブロック
	EmptyBlock_o,	// あたると消える
	SkeletonBlock_o,	// あたると出現
	Save_o,	// 撃つとセーブ
	Okonomiyaki_o,	// あたると死ぬ
	Sauce_o,	// 無限ジャンプ
	Warp_o,		// 次のステージへ

	objMax_o
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
	int graphHandle;

	void operator = ( Position pos_ ){
		position.x = pos_.x;
		position.y = pos_.y;
	}

	void operator = ( Size size_ ){
		size.width = size_.width;
		size.height = size_.height;
	}
};

struct ObjectData{
	Position position;
	Size size;
	int graphHandle;
	ObjectTag tag;

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

const float STAGE_WIDTH = 20;
const float STAGE_HEIGHT = 12;

const float CHIP_WIDTH = 64;
const float CHIP_HEIGHT = 64;

const float GRAVITY = 0.6f;

namespace Key{
	const int UP = KEY_INPUT_UP;
	const int LEFT = KEY_INPUT_LEFT;
	const int RIGHT = KEY_INPUT_RIGHT;
	const int DOWN = KEY_INPUT_DOWN;
	const int JUMP = KEY_INPUT_LSHIFT;
	const int SHOT = KEY_INPUT_Z;
	const int RESET = KEY_INPUT_R;
};

namespace Color{
	const int white = GetColor( 255, 255, 255 );
	const int black = GetColor( 0, 0, 0 );
	const int blue = GetColor( 0, 0, 255 );
	const int green = GetColor( 0, 255, 0 );
	const int red = GetColor( 255, 0, 0 );

}

#endif // !COMMON_N
