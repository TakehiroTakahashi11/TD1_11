#pragma once
#include "BaseBullet.h"

#define Enemy1MaxNum 4

class Enemy1 : public BaseBullet
{
public:
	/// @brief コンストラクタ
	Enemy1(class Game& game, Vector2D pos);

	/// @brief デストラクタ
	~Enemy1();

	// 継承

	void Init() override;
	void Update() override;
	void Draw() override;

private:
	bool isStartAnim;
	float col_rad;

	struct Enemy1Struct {
		Vector2D position;
		Vector2D velocity;
		float anim;
	};

	Enemy1Struct enemy1Struct[Enemy1MaxNum];
};