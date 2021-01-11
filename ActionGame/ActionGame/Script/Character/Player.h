
#ifndef PLAYER_H
#define PLAYER_H

#include "../Common.h"
#include "../Function/Function.h"

// プレイヤーに関する変数や処理を管理する
class Player {
public:
	// コンストラクタ
	Player( CharacterData initData );

	// デストラクタ
	~Player();

	// 移動
	void Move();

	// 描画
	void Draw();

private:
	CharacterData data;
};

#endif // !PLAYER_H
