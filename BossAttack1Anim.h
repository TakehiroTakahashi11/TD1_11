#pragma once
#include "BaseEffect.h"

class BossAttack1Anim : public BaseEffect
{
public:
	/// @brief コンストラクタ
	BossAttack1Anim(class Game& game, Vector2D pos);

	/// @brief デストラクタ
	~BossAttack1Anim();

	// 継承

	void Init() override;
	void Update() override;
	void Draw() override;

private:
	float elapsedFrame1;
};