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

	bool GetIsBreak() { return isBreak; }

private:
	// ���W
	Vector2D gauntlets_pos;

	// �ϋv��
	float health;

	// �K�[�h�A�j���[�V�����p�x
	float guard_dir;
	// �_�b�V���A�j���[�V����
	float dash_dis;
	float dash_dir;

	// �A�j���[�V����
	int x_anim;

	// ���Ă��邩
	bool isBreak;
};