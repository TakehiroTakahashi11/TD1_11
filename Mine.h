#pragma once
#include "BaseBullet.h"

#define BossAttack2MaxNum 1

class Mine : public BaseBullet
{
public:
	/// @brief �R���X�g���N�^
	Mine(class Game& game, Vector2D pos);

	/// @brief �f�X�g���N�^
	~Mine();

	// �p��

	void Init() override;
	void Update() override;
	void Draw() override;

private:

	bool isStartAnim;
	float anim;

	float col_rad;
};