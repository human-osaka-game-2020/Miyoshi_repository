
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

struct CharacterData{
	int x;
	int y;
	int width;
	int height;
	int speed;
	LPCTSTR sprite;
};

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

const int COLOR_WHITE = GetColor(255, 255, 255);
const int COLOR_BLACK = GetColor(0, 0, 0);
const int COLOR_BLUE = GetColor(0, 0, 255);
const int COLOR_GREEN = GetColor(0, 255, 0);
const int COLOR_RED = GetColor(255, 0, 0);

#endif // !COMMON_N
