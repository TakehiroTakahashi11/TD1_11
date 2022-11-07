#pragma once
#include "BaseEffect.h"

class BossAttack1Anim : public BaseEffect
{
public:
	/// @brief �R���X�g���N�^
	BossAttack1Anim(class Game& game, Vector2D pos);

	/// @brief �f�X�g���N�^
	~BossAttack1Anim();

	// �p��

	void Init() override;
	void Update() override;
	void Draw() override;

private:
	float elapsedFrame1;
};