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
	/// @brief �A�j���[�V�����֐�
	void Animation();

public://�Q�b�^�[�Z�b�^�[

	Vector2D GetPosition() { return position; }

private:
	// �K�[�h�A�j���[�V�����p�x
	float guard_dir;
	// �_�b�V���A�j���[�V����
	float dash_dis;
	float dash_dir;

	// �A�j���[�V����
	int x_anim;

	Vector2D chargePos;
	// �`���[�W�A�^�b�N
	float chargeAttackFrame;
	float chargeAttackSpeed;

	bool InitFlag;
};