#pragma once
#include "BaseBullet.h"

#define BossAttack2MaxNum 1

class BossAttack2 : public BaseBullet
{
public:
	/// @brief コンストラクタ
	BossAttack2(class Game& game, Vector2D pos);

	/// @brief デストラクタ
	~BossAttack2();

	// 継承

	void Init() override;
	void Update() override;
	void Draw() override;

private:

	bool endCheck();

	struct BossAttack2Struct {
		Vector2D position = { 0.0f,0.0f };
		Vector2D size = { 32.0f,32.0f };
		Vector2D velocity = { 0.0f,0.0f };
		float theta = 0.0f;
		float elapseFrame = 0.0f;
		bool isEnd = false;
	};

	BossAttack2Struct bossAttack2[BossAttack2MaxNum];
};