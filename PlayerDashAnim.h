#pragma once
#include "BaseEffect.h"

class PlayerDashAnim : public BaseEffect
{
public:
	/// @brief �R���X�g���N�^
	PlayerDashAnim(class Game& game, Vector2D pos);

	/// @brief �f�X�g���N�^
	~PlayerDashAnim();

	// �p��

	void Init() override;
	void Update() override;
	void Draw() override;

private:
	float theta;
	Vector2D pos;
};
