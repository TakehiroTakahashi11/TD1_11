#pragma once
#include "Obj.h"

class Gauntlets : public Obj
{
public:
	Gauntlets(class Game& game);
	~Gauntlets();

	void Init() override;
	void Update() override;
	void Draw() override;

	bool ChargeAttack();

private:

public://�Q�b�^�[�Z�b�^�[

	Vector2D GetPosition() { return position; }
	void SetEndChargeAtk() { chargeAttackFrame = 70.0f; }
	void SetChargeAtkInit() {
		chargePos = { 0.0f,0.0f };
		InitFlag = false;
		chargeAttackFrame = 0.0f;
		chargeAttackSpeed = 0.0f;
	}

private:
	// �_�b�V���A�j���[�V����
	float dash_dis;
	float dash_dis_acc;

	// �A�j���[�V����
	int x_anim;

	Vector2D chargePos;
	// �`���[�W�A�^�b�N
	float chargeAttackFrame;
	float chargeAttackSpeed;

	bool InitFlag;
};