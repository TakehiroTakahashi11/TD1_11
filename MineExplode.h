#pragma once
#include "BaseBullet.h"

#define BossAttack2MaxNum 1

class MineExplode : public BaseBullet
{
public:
	/// @brief �R���X�g���N�^
	MineExplode(class Game& game, Vector2D pos);

	/// @brief �f�X�g���N�^
	~MineExplode();

	// �p��

	void Init() override;
	void Update() override;
	void Draw() override;

private:
	bool isCheck;
};