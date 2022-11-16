#pragma once
#include "BaseBullet.h"

#define BossAttack2MaxNum 1

class Lazer : public BaseBullet
{
public:
	/// @brief コンストラクタ
	Lazer(class Game& game, Vector2D pos);

	/// @brief デストラクタ
	~Lazer();

	// 継承

	void Init() override;
	void Update() override;
	void Draw() override;

private:

	Vector2D bossPos;
	Vector2D dir;

	float anim;
};