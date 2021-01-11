
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
	int x;
	int y;
};

// 大きさ
struct Size{
	int width;
	int height;
};

// キャラクターの情報
struct CharacterData{
	int x;
	int y;
	int width;
	int height;
	int speed;
	LPCTSTR sprite;

	void operator = ( Position pos ){
		x = pos.x;
		y = pos.y;
	}

	void operator = ( Size size ){
		width = size.width;
		height = size.height;
	}
};

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

namespace Color{
	const int white = GetColor( 255, 255, 255 );
	const int black = GetColor( 0, 0, 0 );
	const int blue = GetColor( 0, 0, 255 );
	const int green = GetColor( 0, 255, 0 );
	const int red = GetColor( 255, 0, 0 );

}

#endif // !COMMON_N
