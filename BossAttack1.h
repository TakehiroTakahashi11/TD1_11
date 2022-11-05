#pragma once
#include "BaseBullet.h"

#define BossAttack1MaxNum 16

class BossAttack1 : public BaseBullet
{
public:
	/// @brief �R���X�g���N�^
	BossAttack1(class Game& game, Vector2D pos);

	/// @brief �f�X�g���N�^
	~BossAttack1();

	// �p��

	void Init() override;
	void Update() override;
	void Draw() override;

private:

	bool endCheck();

	struct BossAttack1Struct {
		Vector2D position = { 0.0f,0.0f };
		Vector2D size = { 32.0f,32.0f };
		Vector2D velocity = { 0.0f,0.0f };
		float theta = 0.0f;
		float elapseFrame = 0.0f;
		bool isEnd = false;
	};

	BossAttack1Struct bossAttack1[BossAttack1MaxNum];
};