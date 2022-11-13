#pragma once
#include "BaseBullet.h"

#define BossAttack2MaxNum 1

class Mine : public BaseBullet
{
public:
	/// @brief コンストラクタ
	Mine(class Game& game, Vector2D pos);

	/// @brief デストラクタ
	~Mine();

	// 継承

	void Init() override;
	void Update() override;
	void Draw() override;

private:

	bool isStartAnim;
	float anim;

	float col_rad;
};