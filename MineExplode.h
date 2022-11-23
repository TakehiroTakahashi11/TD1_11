#pragma once
#include "BaseBullet.h"

#define BossAttack2MaxNum 1

class MineExplode : public BaseBullet
{
public:
	/// @brief コンストラクタ
	MineExplode(class Game& game, Vector2D pos);

	/// @brief デストラクタ
	~MineExplode();

	// 継承

	void Init() override;
	void Update() override;
	void Draw() override;

private:
	bool isCheck;
};