
#ifndef PLAYER_H
#define PLAYER_H

#include "../Common.h"
#include "../Function/Function.h"
#include "../Manager/BulletManager.h"

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

	// ジャンプ
	void Jump();

	// 射撃
	void Shoot();

	void operator = ( CharacterData data_ ){
		data = data_;
	}

private:
	CharacterData data;
	float jumpPower;
	int jumpCounter;
	bool isJumped;
	bool isDoubleJumped;
	const float JUMP_POWER = 12;
	BulletManager* pBulletManager;
};

#endif // !PLAYER_H
