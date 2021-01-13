
#ifndef BULLET_MANAGER_H
#define BULLET_MANAGER_H

#include "../Common.h"
#include "../Function/Function.h"
#include "../Character/Bullet.h"
#include "../Object/ObjectBase.h"

class BulletManager{
public:
	BulletManager(){};
	~BulletManager(){};

public:
	// 処理
	void Control();

	// 描画
	void Draw();

	/// @brief 弾の生成
	/// @param 主のキャラクターデータ
	void CreateBullet( CharacterData data_ );

	// オブジェクトに対する当たり判定
	void Collision( ObjectBase* object_, Position pos_, int stageNumber_ );

private:
	std::vector<Bullet*> bullets;
};

#endif // !BULLET_MANAGER_H
