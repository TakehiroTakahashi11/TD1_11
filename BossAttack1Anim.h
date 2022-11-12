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
	Vector2D circlePos;
	float circle1Size;
	float circle2Size;
	float circle3Size;
	float circle1Theta;
	float circle2Theta;
	float circle3Theta;
	float circle1ThetaSpd;
	float circle2ThetaSpd;
	float circle3ThetaSpd;

	float elapsedFrame1;
};