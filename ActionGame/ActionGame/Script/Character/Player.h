
#ifndef PLAYER_H
#define PLAYER_H

#include "../Common.h"
#include "../Function/Function.h"
#include "../Manager/BulletManager.h"
#include "../Object/ObjectBase.h"
#include "../Manager/SoundManager.h"

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

	// 当たり判定
	// 当たったオブジェクトを返す
	ObjectTag Collision( ObjectBase* object_ );

	// 弾の判定
	void BulletCollision( ObjectBase* object_, int stageNumber_ );

	void ResetHitData();

	CharacterData GetData() const { return data; }

	void operator = ( CharacterData data_ ){
		data = data_;
	}

	struct HitData{
		bool up;
		bool left;
		bool right;
		bool down;
	};

private:
	CharacterData data;
	float jumpPower;
	int jumpCounter;
	bool isJumping;
	bool isDoubleJumping;
	const float JUMP_POWER = 8;
	BulletManager* pBulletManager;
	bool isFlying;
	Position previousPos;
	HitData previousHit;
	HitData hitChecker;

	SoundManager* sndIns;
};

#endif // !PLAYER_H
