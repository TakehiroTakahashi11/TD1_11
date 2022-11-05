#pragma once
#include "BaseEffect.h"

class Thunder : public BaseEffect
{
public:
	/// @brief �R���X�g���N�^
	Thunder(class Game& game, Vector2D pos);

	/// @brief �f�X�g���N�^
	~Thunder();

	// �p��

	void Init() override;
	void Update() override;
	void Draw() override;

private:
	Vector2D col_pos;
};
